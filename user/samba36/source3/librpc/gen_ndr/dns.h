/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_dns
#define _PIDL_HEADER_dns

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_dns
#define _HEADER_dns

#define DNS_SERVICE_PORT	( 53 )
/* bitmap dns_operation */
#define DNS_RCODE ( 0x000F )
#define DNS_FLAG_BROADCAST ( 0x0010 )
#define DNS_FLAG_RECURSION_AVAIL ( 0x0080 )
#define DNS_FLAG_RECURSION_DESIRED ( 0x0100 )
#define DNS_FLAG_TRUNCATION ( 0x0200 )
#define DNS_FLAG_AUTHORITATIVE ( 0x0400 )
#define DNS_OPCODE ( 0x7800 )
#define DNS_FLAG_REPLY ( 0x8000 )

enum dns_opcode
#ifndef USE_UINT_ENUMS
 {
	DNS_OPCODE_QUERY=(int)((0x0<<11)),
	DNS_OPCODE_IQUERY=(int)((0x1<<11)),
	DNS_OPCODE_STATUS=(int)((0x2<<11)),
	DNS_OPCODE_REGISTER=(int)((0x5<<11)),
	DNS_OPCODE_RELEASE=(int)((0x6<<11)),
	DNS_OPCODE_WACK=(int)((0x7<<11)),
	DNS_OPCODE_REFRESH=(int)((0x8<<11)),
	DNS_OPCODE_REFRESH2=(int)((0x9<<11)),
	DNS_OPCODE_MULTI_HOME_REG=(int)((0xf<<11))
}
#else
 { __donnot_use_enum_dns_opcode=0x7FFFFFFF}
#define DNS_OPCODE_QUERY ( (0x0<<11) )
#define DNS_OPCODE_IQUERY ( (0x1<<11) )
#define DNS_OPCODE_STATUS ( (0x2<<11) )
#define DNS_OPCODE_REGISTER ( (0x5<<11) )
#define DNS_OPCODE_RELEASE ( (0x6<<11) )
#define DNS_OPCODE_WACK ( (0x7<<11) )
#define DNS_OPCODE_REFRESH ( (0x8<<11) )
#define DNS_OPCODE_REFRESH2 ( (0x9<<11) )
#define DNS_OPCODE_MULTI_HOME_REG ( (0xf<<11) )
#endif
;

enum dns_rcode
#ifndef USE_UINT_ENUMS
 {
	DNS_RCODE_OK=(int)(0x0),
	DNS_RCODE_FORMERR=(int)(0x1),
	DNS_RCODE_SERVFAIL=(int)(0x2),
	DNS_RCODE_NXDOMAIN=(int)(0x3),
	DNS_RCODE_NOTIMP=(int)(0x4),
	DNS_RCODE_REFUSED=(int)(0x5),
	DNS_RCODE_YXDOMAIN=(int)(0x6),
	DNS_RCODE_YXRRSET=(int)(0x7),
	DNS_RCODE_NXRRSET=(int)(0x8),
	DNS_RCODE_NOTAUTH=(int)(0x9),
	DNS_RCODE_NOTZONE=(int)(0xA)
}
#else
 { __donnot_use_enum_dns_rcode=0x7FFFFFFF}
#define DNS_RCODE_OK ( 0x0 )
#define DNS_RCODE_FORMERR ( 0x1 )
#define DNS_RCODE_SERVFAIL ( 0x2 )
#define DNS_RCODE_NXDOMAIN ( 0x3 )
#define DNS_RCODE_NOTIMP ( 0x4 )
#define DNS_RCODE_REFUSED ( 0x5 )
#define DNS_RCODE_YXDOMAIN ( 0x6 )
#define DNS_RCODE_YXRRSET ( 0x7 )
#define DNS_RCODE_NXRRSET ( 0x8 )
#define DNS_RCODE_NOTAUTH ( 0x9 )
#define DNS_RCODE_NOTZONE ( 0xA )
#endif
;

enum dns_qclass
#ifndef USE_UINT_ENUMS
 {
	DNS_QCLASS_IP=(int)(0x0001),
	DNS_QCLASS_NONE=(int)(0x00FE),
	DNS_QCLASS_ANY=(int)(0x00FF)
}
#else
 { __donnot_use_enum_dns_qclass=0x7FFFFFFF}
#define DNS_QCLASS_IP ( 0x0001 )
#define DNS_QCLASS_NONE ( 0x00FE )
#define DNS_QCLASS_ANY ( 0x00FF )
#endif
;

enum dns_qtype
#ifndef USE_UINT_ENUMS
 {
	DNS_QTYPE_ZERO=(int)(0x0000),
	DNS_QTYPE_A=(int)(0x0001),
	DNS_QTYPE_NS=(int)(0x0002),
	DNS_QTYPE_MD=(int)(0x0003),
	DNS_QTYPE_MF=(int)(0x0004),
	DNS_QTYPE_CNAME=(int)(0x0005),
	DNS_QTYPE_SOA=(int)(0x0006),
	DNS_QTYPE_MB=(int)(0x0007),
	DNS_QTYPE_MG=(int)(0x0008),
	DNS_QTYPE_MR=(int)(0x0009),
	DNS_QTYPE_NULL=(int)(0x000A),
	DNS_QTYPE_WKS=(int)(0x000B),
	DNS_QTYPE_PTR=(int)(0x000C),
	DNS_QTYPE_HINFO=(int)(0x000D),
	DNS_QTYPE_MINFO=(int)(0x000E),
	DNS_QTYPE_MX=(int)(0x000F),
	DNS_QTYPE_TXT=(int)(0x0010),
	DNS_QTYPE_RP=(int)(0x0011),
	DNS_QTYPE_AFSDB=(int)(0x0012),
	DNS_QTYPE_X25=(int)(0x0013),
	DNS_QTYPE_ISDN=(int)(0x0014),
	DNS_QTYPE_RT=(int)(0x0015),
	DNS_QTYPE_SIG=(int)(0x0018),
	DNS_QTYPE_KEY=(int)(0x0019),
	DNS_QTYPE_AAAA=(int)(0x001C),
	DNS_QTYPE_LOC=(int)(0x001D),
	DNS_QTYPE_NXT=(int)(0x001E),
	DNS_QTYPE_NETBIOS=(int)(0x0020),
	DNS_QTYPE_SRV=(int)(0x0021),
	DNS_QTYPE_ATMA=(int)(0x0022),
	DNS_QTYPE_NAPTR=(int)(0x0023),
	DNS_QTYPE_DNAME=(int)(0x0027),
	DNS_QTYPE_DS=(int)(0x002B),
	DNS_QTYPE_RRSIG=(int)(0x002E),
	DNS_QTYPE_NSEC=(int)(0x002F),
	DNS_QTYPE_DNSKEY=(int)(0x0030),
	DNS_QTYPE_DHCID=(int)(0x0031),
	DNS_QTYPE_ALL=(int)(0x00FF),
	DNS_QTYPE_WINS=(int)(0xFF01),
	DNS_QTYPE_WINSR=(int)(0xFF02)
}
#else
 { __donnot_use_enum_dns_qtype=0x7FFFFFFF}
#define DNS_QTYPE_ZERO ( 0x0000 )
#define DNS_QTYPE_A ( 0x0001 )
#define DNS_QTYPE_NS ( 0x0002 )
#define DNS_QTYPE_MD ( 0x0003 )
#define DNS_QTYPE_MF ( 0x0004 )
#define DNS_QTYPE_CNAME ( 0x0005 )
#define DNS_QTYPE_SOA ( 0x0006 )
#define DNS_QTYPE_MB ( 0x0007 )
#define DNS_QTYPE_MG ( 0x0008 )
#define DNS_QTYPE_MR ( 0x0009 )
#define DNS_QTYPE_NULL ( 0x000A )
#define DNS_QTYPE_WKS ( 0x000B )
#define DNS_QTYPE_PTR ( 0x000C )
#define DNS_QTYPE_HINFO ( 0x000D )
#define DNS_QTYPE_MINFO ( 0x000E )
#define DNS_QTYPE_MX ( 0x000F )
#define DNS_QTYPE_TXT ( 0x0010 )
#define DNS_QTYPE_RP ( 0x0011 )
#define DNS_QTYPE_AFSDB ( 0x0012 )
#define DNS_QTYPE_X25 ( 0x0013 )
#define DNS_QTYPE_ISDN ( 0x0014 )
#define DNS_QTYPE_RT ( 0x0015 )
#define DNS_QTYPE_SIG ( 0x0018 )
#define DNS_QTYPE_KEY ( 0x0019 )
#define DNS_QTYPE_AAAA ( 0x001C )
#define DNS_QTYPE_LOC ( 0x001D )
#define DNS_QTYPE_NXT ( 0x001E )
#define DNS_QTYPE_NETBIOS ( 0x0020 )
#define DNS_QTYPE_SRV ( 0x0021 )
#define DNS_QTYPE_ATMA ( 0x0022 )
#define DNS_QTYPE_NAPTR ( 0x0023 )
#define DNS_QTYPE_DNAME ( 0x0027 )
#define DNS_QTYPE_DS ( 0x002B )
#define DNS_QTYPE_RRSIG ( 0x002E )
#define DNS_QTYPE_NSEC ( 0x002F )
#define DNS_QTYPE_DNSKEY ( 0x0030 )
#define DNS_QTYPE_DHCID ( 0x0031 )
#define DNS_QTYPE_ALL ( 0x00FF )
#define DNS_QTYPE_WINS ( 0xFF01 )
#define DNS_QTYPE_WINSR ( 0xFF02 )
#endif
;

struct dns_name_question {
	const char * name;
	enum dns_qtype question_type;
	enum dns_qclass question_class;
}/* [public] */;

struct dns_rdata_data {
	uint16_t length;
	uint8_t *data;
}/* [public] */;

struct dns_soa_record {
	const char * mname;
	const char * rname;
	uint32_t serial;
	uint32_t refresh;
	uint32_t retry;
	uint32_t expire;
	uint32_t minimum;
};

struct dns_srv_record {
	uint16_t priority;
	uint16_t weight;
	uint16_t port;
	const char * target;
}/* [public] */;

struct dns_mx_record {
	uint16_t preference;
	const char * exchange;
}/* [public] */;

union dns_rdata {
	const char * ipv4_record;/* [case(DNS_QTYPE_A)] */
	const char * ns_record;/* [case(DNS_QTYPE_NS)] */
	const char * cname_record;/* [case(DNS_QTYPE_CNAME)] */
	struct dns_soa_record soa_record;/* [case(DNS_QTYPE_SOA)] */
	const char * ptr_record;/* [case(DNS_QTYPE_PTR)] */
	struct dns_mx_record mx_record;/* [case(DNS_QTYPE_MX)] */
	const char * ipv6_record;/* [case(DNS_QTYPE_AAAA)] */
	struct dns_srv_record srv_record;/* [case(DNS_QTYPE_SRV)] */
}/* [nodiscriminant,public,flag(LIBNDR_FLAG_NOALIGN)] */;

struct dns_res_rec {
	const char * name;
	enum dns_qtype rr_type;
	enum dns_qclass rr_class;
	uint32_t ttl;
	uint16_t length;
	union dns_rdata rdata;/* [switch_is(rr_type)] */
	DATA_BLOB unexpected;
}/* [nopull,nopush,flag(LIBNDR_PRINT_ARRAY_HEX|LIBNDR_FLAG_NOALIGN)] */;

struct dns_name_packet {
	uint16_t id;
	uint16_t operation;
	uint16_t qdcount;
	uint16_t ancount;
	uint16_t nscount;
	uint16_t arcount;
	struct dns_name_question *questions;
	struct dns_res_rec *answers;
	struct dns_res_rec *nsrecs;
	struct dns_res_rec *additional;
}/* [flag(LIBNDR_FLAG_NOALIGN|LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX),public] */;


struct decode_dns_name_packet {
	struct {
		struct dns_name_packet packet;
	} in;

};

#endif /* _HEADER_dns */
#endif /* _PIDL_HEADER_dns */
