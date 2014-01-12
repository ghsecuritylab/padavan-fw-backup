/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <sys/swap.h>

#include <nvram/bcmnvram.h>

#include "rc.h"

static const char*
_basename(const char *name)
{
	const char *cp = strrchr(name, '/');
	if (cp)
		return cp + 1;
	return name;
}

static int
check_root_partition(const char *devname)
{
	FILE *procpt;
	char line[128], ptname[32], ptname_check[32];
	int i, ma, mi, sz;

	if (devname && (procpt = fopen("/proc/partitions", "r")))
	{
		while (fgets(line, sizeof(line), procpt))
		{
			if (sscanf(line, " %d %d %d %[^\n ]", &ma, &mi, &sz, ptname) != 4)
				continue;
			
			for (i=1;i<15;i++) {
				sprintf(ptname_check, "%s%d", devname, i);
				if (strcmp(ptname, ptname_check) == 0)
				{
					fclose(procpt);
					return 1;
				}
			}
		}
		
		fclose(procpt);
	}

	return 0;
}

// 1: add, 0: remove.
static int
check_hotplug_action(const char *action){
	if(!strcmp(action, "remove"))
		return 0;
	else
		return 1;
}

int
usb_port_module_used(const char *mod_usb)
{
	DIR* dir;
	int ret = 0;
	char mod_path_usb[128];
	
	snprintf(mod_path_usb, sizeof(mod_path_usb), "/sys/module/%s/drivers/usb:%s", mod_usb, mod_usb);
	
	dir = opendir(mod_path_usb);
	if (dir) {
		struct dirent *de;
		char ports_id[4][32];
		strcpy(ports_id[0], USB_EHCI_PORT_1);
		strcpy(ports_id[1], USB_OHCI_PORT_1);
		strcpy(ports_id[2], USB_EHCI_PORT_2);
		strcpy(ports_id[3], USB_OHCI_PORT_2);
		while ((de = readdir(dir)) != NULL){
			int i, len;
			for (i = 0; i < 4; i++) {
				len = strlen(ports_id[i]);
				if (len > 0 && strncmp(de->d_name, ports_id[i], len) == 0) {
					ret = 1;
					break;
				}
			}
		}
		closedir(dir);
	}
	
	return ret;
}

void
detach_swap_partition(char *part_name)
{
	int need_detach = 0;
	char *swap_part = nvram_safe_get("swap_part_t");
	char swap_dev[16];
	if (strncmp(swap_part, "sd", 2))
	{
		return;
	}
	
	if (part_name && *part_name)
	{
		if (strncmp(part_name, swap_part, 3) == 0)
		{
			need_detach = 1;
		}
	}
	else
	{
		need_detach = 1;
	}
	
	// umount swap partition
	if (need_detach)
	{
		sprintf(swap_dev, "/dev/%s", swap_part);
		if ( swapoff(swap_dev) == 0 )
		{
			nvram_set_temp("swap_part_t", "");
		}
	}
}

int mdev_sd_main(int argc, char **argv)
{
	char aidisk_cmd[64];
	int isLock, mount_result;
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);

	if(get_device_type_by_device(device_name) != DEVICE_TYPE_DISK){
		usb_dbg("(%s): The device is not a sd device.\n", device_name);
		return 0;
	}

	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1){
		usb_dbg("(%s): Can't set the file lock!\n", device_name);
		return 0;
	}

	// If remove the device?
	if(!check_hotplug_action(action)){
		if (device_name[3] != '\0')
			detach_swap_partition((char*)device_name);
		else
			notify_rc("on_unplug_usb_storage");
		
		file_unlock(isLock);
		return 0;
	}

	memset(aidisk_cmd, 0, sizeof(aidisk_cmd));
	if (device_name[3] == '\0')	// sda, sdb, sdc...
	{
		system("/sbin/hddtune.sh $MDEV");
		
		if (!check_root_partition(device_name))
		{
			sprintf(aidisk_cmd, "/sbin/automount.sh $MDEV AiDisk_%c%c", device_name[2], '1');
		}
		else
			goto No_Need_To_Mount;
	}
	else
	{
		sprintf(aidisk_cmd, "/sbin/automount.sh $MDEV AiDisk_%c%c", device_name[2], device_name[3]);
	}

	umask(0000);
	mount_result = system(aidisk_cmd);
	if (mount_result == 0)
	{
		notify_rc("on_hotplug_usb_storage");
	}

	usb_dbg("(%s): Success!\n", device_name);
	file_unlock(isLock);
	return 1;

No_Need_To_Mount:
	usb_dbg("(%s): No need to mount!\n", device_name);
	file_unlock(isLock);

	return 0;
}

int mdev_lp_main(int argc, char **argv)
{
	int isLock;
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = _basename(argv[1]);
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);

	if(get_device_type_by_device(device_name) != DEVICE_TYPE_PRINTER){
		usb_dbg("(%s): The device is not a printer.\n", device_name);
		return 0;
	}

	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1){
		usb_dbg("(%s): Can't set the file lock!\n", device_name);
		return 0;
	}

	// If remove the device?
	if(!check_hotplug_action(action)){
		notify_rc("on_unplug_usb_printer");
		
		file_unlock(isLock);
		return 0;
	}

	notify_rc("on_hotplug_usb_printer");

	usb_dbg("(%s): Success!\n", device_name);

	file_unlock(isLock);

	return 1;
}

int mdev_sg_main(int argc, char **argv)
{
	int isLock;
	const char *device_name, *action;

	if(argc < 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);

	if(get_device_type_by_device(device_name) != DEVICE_TYPE_SG)
		return 0;

	// If remove the device?
	if(!check_hotplug_action(action)){
		usb_dbg("(%s): Remove sg device.\n", device_name);
		return 0;
	}

	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1){
		usb_dbg("(%s): Can't set the file lock!\n", device_name);
		return 0;
	}

	if (nvram_get_int("modem_zcd") != 0) {
		if (module_smart_load("sr_mod", NULL))
			sleep(1);
	}
	else {
		char vid[8] = {0}, pid[8] = {0};
		char usb_port_id[64] = {0};
		if (get_usb_port_by_device(device_name, usb_port_id, sizeof(usb_port_id))) {
			if (get_usb_vid(usb_port_id, vid, sizeof(vid)) && get_usb_pid(usb_port_id, pid, sizeof(pid)))
				perform_usb_modeswitch(vid, pid);
		}
	}

	usb_dbg("(%s): Success!\n", device_name);
	file_unlock(isLock);

	return 1;
}

int mdev_sr_main(int argc, char **argv)
{
	int isLock;
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);

	if(get_device_type_by_device(device_name) != DEVICE_TYPE_CD){
		usb_dbg("(%s): The device is not a CD one.\n", device_name);
		return 0;
	}

	// If remove the device?
	if(!check_hotplug_action(action)){
		usb_dbg("(%s): Remove CD device.\n", device_name);
		return 0;
	}

	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1){
		usb_dbg("(%s): Can't set the file lock!\n", device_name);
		return 0;
	}

	doSystem("eject -s /dev/%s", device_name);
	sleep(1);
	module_smart_unload("sr_mod", 1);

	usb_dbg("(%s): Success!\n", device_name);
	file_unlock(isLock);

	return 1;
}

int mdev_wdm_main(int argc, char **argv)
{
	FILE *fp;
	int isLock;
	char node_fname[64];
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);
	
	if(!isWDMNode(device_name))
		return 0;
	
	sprintf(node_fname, "%s/%s", MODEM_NODE_DIR, device_name);
	
	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1)
		return 0;
	
	unlink(QMI_CLIENT_ID);
	
	// If remove the device?
	if(!check_hotplug_action(action)){
		unlink(node_fname);
		goto out_unlock;
	}
	
	// Write node file.
	mkdir_if_none(MODEM_NODE_DIR);
	fp = fopen(node_fname, "w+");
	if (fp) {
		fprintf(fp, "pref=%d\n", 1);
		fprintf(fp, "devnum=%d\n", 0); // todo
		fclose(fp);
	}
	
	usb_dbg("(%s): Success!\n", device_name);
	
out_unlock:
	file_unlock(isLock);
	
	return 1;
}

int mdev_net_main(int argc, char **argv)
{
	FILE *fp;
	int isLock, devnum;
	char usb_port_id[64], node_fname[64];
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];

	usb_dbg("(%s): action=%s.\n", device_name, action);
	
	if (!isUsbNetIf(device_name))
		return 0;
	
	sprintf(node_fname, "%s/%s", MODEM_NODE_DIR, device_name);
	
	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1)
		return 0;
	
	// If remove the device?
	if(!check_hotplug_action(action)){
		unlink(node_fname);
		
		create_file(FLAG_FILE_WWAN_GONE);
		
		ifconfig((char*)device_name, 0, "0.0.0.0", NULL);
		
		if (get_usb_modem_wan(0))
			notify_rc("on_unplug_usb_modem");
		
		goto out_unlock;
	}

	// Get DevNum
	devnum = 0;
	usb_port_id[0] = 0;
	if (get_usb_port_by_device(device_name, usb_port_id, sizeof(usb_port_id)))
		devnum = get_usb_devnum(usb_port_id);

	// Write node file.
	mkdir_if_none(MODEM_NODE_DIR);
	fp = fopen(node_fname, "w+");
	if (fp) {
		fprintf(fp, "pref=%d\n", 1);
		fprintf(fp, "devnum=%d\n", devnum);
		fprintf(fp, "portid=%s\n", usb_port_id);
		fclose(fp);
	}

	if (nvram_invmatch("modem_arun", "0") && nvram_match("modem_rule", "1") && nvram_match("modem_type", "3"))
		notify_rc("on_hotplug_usb_modem");

	usb_dbg("(%s): Success!\n", device_name);

out_unlock:
	file_unlock(isLock);

	return 1;
}

int mdev_tty_main(int argc, char **argv)
{
	FILE *fp;
	int isLock, devnum, has_int_pipe;
	char usb_port_id[64], usb_interface_id[64], node_fname[64];
	const char *device_name, *action;

	if(argc != 3){
		printf("Usage: %s [device_name] [action]\n", argv[0]);
		return 0;
	}

	device_name = argv[1];
	action = argv[2];
	usb_dbg("(%s): action=%s.\n", device_name, action);

	if (!isSerialNode(device_name) && !isACMNode(device_name))
		return 0;

	sprintf(node_fname, "%s/%s", MODEM_NODE_DIR, device_name);

	// Check Lock.
	if((isLock = file_lock((char *)device_name)) == -1)
		return 0;
	
	// If remove the device?
	if(!check_hotplug_action(action)){
		unlink(node_fname);
		
		create_file(FLAG_FILE_WWAN_GONE);
		
		if (get_usb_modem_wan(0))
			notify_rc("on_unplug_usb_modem");
		
		usb_dbg("(%s): Remove the modem node\n", device_name);
		
		goto out_unlock;
	}

	// Get DevNum
	devnum = 0;
	has_int_pipe = 0;
	usb_port_id[0] = 0;
	if (get_interface_by_device(device_name, usb_interface_id, sizeof(usb_interface_id))) {
		has_int_pipe = get_interface_Int_endpoint(usb_interface_id);
		if (get_usb_port_by_interface_string(usb_interface_id, usb_port_id, sizeof(usb_port_id)))
			devnum = get_usb_devnum(usb_port_id);
	}

	// Write node file.
	mkdir_if_none(MODEM_NODE_DIR);
	fp = fopen(node_fname, "w+");
	if (fp) {
		fprintf(fp, "pref=%d\n", (has_int_pipe) ? 1 : 0);
		fprintf(fp, "devnum=%d\n", devnum);
		fprintf(fp, "portid=%s\n", usb_port_id);
		fclose(fp);
	}

	if (nvram_invmatch("modem_arun", "0") && nvram_match("modem_rule", "1") && nvram_invmatch("modem_type", "3"))
		notify_rc("on_hotplug_usb_modem");
	
	usb_dbg("(%s): Success!\n", device_name);

out_unlock:
	file_unlock(isLock);

	return 1;
}

