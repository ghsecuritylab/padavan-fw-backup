/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_IWbemClassObject
#define _PIDL_HEADER_IWbemClassObject

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/orpc.h"
#include "librpc/gen_ndr/dcom.h"
#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_IWbemClassObject
#define _HEADER_IWbemClassObject

struct BSTR {
	uint32_t flags;/* [value(0x72657355)] */
	const char *data;/* [charset(UTF16)] */
}/* [noprint] */;


struct Delete {
	struct {
		struct ORPCTHIS ORPCthis;
		const char *wszName;/* [charset(UTF16),ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemClassObject */
#ifndef _HEADER_IWbemServices
#define _HEADER_IWbemServices

enum WBEMSTATUS
#ifndef USE_UINT_ENUMS
 {
	RPC_S_CALL_FAILED=(int)(1726),
	WBEM_NO_ERROR=(int)(0),
	WBEM_S_NO_ERROR=(int)(0),
	WBEM_S_SAME=(int)(0),
	WBEM_S_FALSE=(int)(1),
	WBEM_S_ALREADY_EXISTS=(int)(0x40001),
	WBEM_S_RESET_TO_DEFAULT=(int)(0x40002),
	WBEM_S_DIFFERENT=(int)(0x40003),
	WBEM_S_TIMEDOUT=(int)(0x40004),
	WBEM_S_NO_MORE_DATA=(int)(0x40005),
	WBEM_S_OPERATION_CANCELLED=(int)(0x40006),
	WBEM_S_PENDING=(int)(0x40007),
	WBEM_S_DUPLICATE_OBJECTS=(int)(0x40008),
	WBEM_S_ACCESS_DENIED=(int)(0x40009),
	WBEM_S_PARTIAL_RESULTS=(int)(0x40010),
	WBEM_S_NO_POSTHOOK=(int)(0x40011),
	WBEM_S_POSTHOOK_WITH_BOTH=(int)(0x40012),
	WBEM_S_POSTHOOK_WITH_NEW=(int)(0x40013),
	WBEM_S_POSTHOOK_WITH_STATUS=(int)(0x40014),
	WBEM_S_POSTHOOK_WITH_OLD=(int)(0x40015),
	WBEM_S_REDO_PREHOOK_WITH_ORIGINAL_OBJECT=(int)(0x40016),
	WBEM_S_SOURCE_NOT_AVAILABLE=(int)(0x40017),
	WBEM_E_FAILED=(int)(0x80041001),
	WBEM_E_NOT_FOUND=(int)(0x80041002),
	WBEM_E_ACCESS_DENIED=(int)(0x80041003),
	WBEM_E_PROVIDER_FAILURE=(int)(0x80041004),
	WBEM_E_TYPE_MISMATCH=(int)(0x80041005),
	WBEM_E_OUT_OF_MEMORY=(int)(0x80041006),
	WBEM_E_INVALID_CONTEXT=(int)(0x80041007),
	WBEM_E_INVALID_PARAMETER=(int)(0x80041008),
	WBEM_E_NOT_AVAILABLE=(int)(0x80041009),
	WBEM_E_CRITICAL_ERROR=(int)(0x8004100A),
	WBEM_E_INVALID_STREAM=(int)(0x8004100B),
	WBEM_E_NOT_SUPPORTED=(int)(0x8004100C),
	WBEM_E_INVALID_SUPERCLASS=(int)(0x8004100D),
	WBEM_E_INVALID_NAMESPACE=(int)(0x8004100E),
	WBEM_E_INVALID_OBJECT=(int)(0x8004100F),
	WBEM_E_INVALID_CLASS=(int)(0x80041010),
	WBEM_E_PROVIDER_NOT_FOUND=(int)(0x80041011),
	WBEM_E_INVALID_PROVIDER_REGISTRATION=(int)(0x80041012),
	WBEM_E_PROVIDER_LOAD_FAILURE=(int)(0x80041013),
	WBEM_E_INITIALIZATION_FAILURE=(int)(0x80041014),
	WBEM_E_TRANSPORT_FAILURE=(int)(0x80041015),
	WBEM_E_INVALID_OPERATION=(int)(0x80041016),
	WBEM_E_INVALID_QUERY=(int)(0x80041017),
	WBEM_E_INVALID_QUERY_TYPE=(int)(0x80041018),
	WBEM_E_ALREADY_EXISTS=(int)(0x80041019),
	WBEM_E_OVERRIDE_NOT_ALLOWED=(int)(0x8004101A),
	WBEM_E_PROPAGATED_QUALIFIER=(int)(0x8004101B),
	WBEM_E_PROPAGATED_PROPERTY=(int)(0x8004101C),
	WBEM_E_UNEXPECTED=(int)(0x8004101D),
	WBEM_E_ILLEGAL_OPERATION=(int)(0x8004101E),
	WBEM_E_CANNOT_BE_KEY=(int)(0x8004101F),
	WBEM_E_INCOMPLETE_CLASS=(int)(0x80041020),
	WBEM_E_INVALID_SYNTAX=(int)(0x80041021),
	WBEM_E_NONDECORATED_OBJECT=(int)(0x80041022),
	WBEM_E_READ_ONLY=(int)(0x80041023),
	WBEM_E_PROVIDER_NOT_CAPABLE=(int)(0x80041024),
	WBEM_E_CLASS_HAS_CHILDREN=(int)(0x80041025),
	WBEM_E_CLASS_HAS_INSTANCES=(int)(0x80041026),
	WBEM_E_QUERY_NOT_IMPLEMENTED=(int)(0x80041027),
	WBEM_E_ILLEGAL_NULL=(int)(0x80041028),
	WBEM_E_INVALID_QUALIFIER_TYPE=(int)(0x80041029),
	WBEM_E_INVALID_PROPERTY_TYPE=(int)(0x8004102A),
	WBEM_E_VALUE_OUT_OF_RANGE=(int)(0x8004102B),
	WBEM_E_CANNOT_BE_SINGLETON=(int)(0x8004102C),
	WBEM_E_INVALID_CIM_TYPE=(int)(0x8004102D),
	WBEM_E_INVALID_METHOD=(int)(0x8004102E),
	WBEM_E_INVALID_METHOD_PARAMETERS=(int)(0x8004102F),
	WBEM_E_SYSTEM_PROPERTY=(int)(0x80041030),
	WBEM_E_INVALID_PROPERTY=(int)(0x80041031),
	WBEM_E_CALL_CANCELLED=(int)(0x80041032),
	WBEM_E_SHUTTING_DOWN=(int)(0x80041033),
	WBEM_E_PROPAGATED_METHOD=(int)(0x80041034),
	WBEM_E_UNSUPPORTED_PARAMETER=(int)(0x80041035),
	WBEM_E_MISSING_PARAMETER_ID=(int)(0x80041036),
	WBEM_E_INVALID_PARAMETER_ID=(int)(0x80041037),
	WBEM_E_NONCONSECUTIVE_PARAMETER_IDS=(int)(0x80041038),
	WBEM_E_PARAMETER_ID_ON_RETVAL=(int)(0x80041039),
	WBEM_E_INVALID_OBJECT_PATH=(int)(0x8004103A),
	WBEM_E_OUT_OF_DISK_SPACE=(int)(0x8004103B),
	WBEM_E_BUFFER_TOO_SMALL=(int)(0x8004103C),
	WBEM_E_UNSUPPORTED_PUT_EXTENSION=(int)(0x8004103D),
	WBEM_E_UNKNOWN_OBJECT_TYPE=(int)(0x8004103E),
	WBEM_E_UNKNOWN_PACKET_TYPE=(int)(0x8004103F),
	WBEM_E_MARSHAL_VERSION_MISMATCH=(int)(0x80041040),
	WBEM_E_MARSHAL_INVALID_SIGNATURE=(int)(0x80041041),
	WBEM_E_INVALID_QUALIFIER=(int)(0x80041042),
	WBEM_E_INVALID_DUPLICATE_PARAMETER=(int)(0x80041043),
	WBEM_E_TOO_MUCH_DATA=(int)(0x80041044),
	WBEM_E_SERVER_TOO_BUSY=(int)(0x80041045),
	WBEM_E_INVALID_FLAVOR=(int)(0x80041046),
	WBEM_E_CIRCULAR_REFERENCE=(int)(0x80041047),
	WBEM_E_UNSUPPORTED_CLASS_UPDATE=(int)(0x80041048),
	WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE=(int)(0x80041049),
	WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE=(int)(0x80041050),
	WBEM_E_TOO_MANY_PROPERTIES=(int)(0x80041051),
	WBEM_E_UPDATE_TYPE_MISMATCH=(int)(0x80041052),
	WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED=(int)(0x80041053),
	WBEM_E_UPDATE_PROPAGATED_METHOD=(int)(0x80041054),
	WBEM_E_METHOD_NOT_IMPLEMENTED=(int)(0x80041055),
	WBEM_E_METHOD_DISABLED=(int)(0x80041056),
	WBEM_E_REFRESHER_BUSY=(int)(0x80041057),
	WBEM_E_UNPARSABLE_QUERY=(int)(0x80041058),
	WBEM_E_NOT_EVENT_CLASS=(int)(0x80041059),
	WBEM_E_MISSING_GROUP_WITHIN=(int)(0x8004105A),
	WBEM_E_MISSING_AGGREGATION_LIST=(int)(0x8004105B),
	WBEM_E_PROPERTY_NOT_AN_OBJECT=(int)(0x8004105C),
	WBEM_E_AGGREGATING_BY_OBJECT=(int)(0x8004105D),
	WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY=(int)(0x8004105F),
	WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING=(int)(0x80041060),
	WBEM_E_QUEUE_OVERFLOW=(int)(0x80041061),
	WBEM_E_PRIVILEGE_NOT_HELD=(int)(0x80041062),
	WBEM_E_INVALID_OPERATOR=(int)(0x80041063),
	WBEM_E_LOCAL_CREDENTIALS=(int)(0x80041064),
	WBEM_E_CANNOT_BE_ABSTRACT=(int)(0x80041065),
	WBEM_E_AMENDED_OBJECT=(int)(0x80041066),
	WBEM_E_CLIENT_TOO_SLOW=(int)(0x80041067),
	WBEM_E_NULL_SECURITY_DESCRIPTOR=(int)(0x80041068),
	WBEM_E_TIMED_OUT=(int)(0x80041069),
	WBEM_E_INVALID_ASSOCIATION=(int)(0x8004106A),
	WBEM_E_AMBIGUOUS_OPERATION=(int)(0x8004106B),
	WBEM_E_QUOTA_VIOLATION=(int)(0x8004106C),
	WBEM_E_RESERVED_001=(int)(0x8004106D),
	WBEM_E_RESERVED_002=(int)(0x8004106E),
	WBEM_E_UNSUPPORTED_LOCALE=(int)(0x8004106F),
	WBEM_E_HANDLE_OUT_OF_DATE=(int)(0x80041070),
	WBEM_E_CONNECTION_FAILED=(int)(0x80041071),
	WBEM_E_INVALID_HANDLE_REQUEST=(int)(0x80041072),
	WBEM_E_PROPERTY_NAME_TOO_WIDE=(int)(0x80041073),
	WBEM_E_CLASS_NAME_TOO_WIDE=(int)(0x80041074),
	WBEM_E_METHOD_NAME_TOO_WIDE=(int)(0x80041075),
	WBEM_E_QUALIFIER_NAME_TOO_WIDE=(int)(0x80041076),
	WBEM_E_RERUN_COMMAND=(int)(0x80041077),
	WBEM_E_DATABASE_VER_MISMATCH=(int)(0x80041078),
	WBEM_E_VETO_DELETE=(int)(0x80041079),
	WBEM_E_VETO_PUT=(int)(0x8004107A),
	WBEM_E_INVALID_LOCALE=(int)(0x80041080),
	WBEM_E_PROVIDER_SUSPENDED=(int)(0x80041081),
	WBEM_E_SYNCHRONIZATION_REQUIRED=(int)(0x80041082),
	WBEM_E_NO_SCHEMA=(int)(0x80041083),
	WBEM_E_PROVIDER_ALREADY_REGISTERED=(int)(0x80041084),
	WBEM_E_PROVIDER_NOT_REGISTERED=(int)(0x80041085),
	WBEM_E_FATAL_TRANSPORT_ERROR=(int)(0x80041086),
	WBEM_E_ENCRYPTED_CONNECTION_REQUIRED=(int)(0x80041087),
	WBEM_E_PROVIDER_TIMED_OUT=(int)(0x80041088),
	WBEM_E_NO_KEY=(int)(0x80041089),
	WBEM_E_PROVIDER_DISABLED=(int)(0x8004108a)
}
#else
 { __donnot_use_enum_WBEMSTATUS=0x7FFFFFFF}
#define RPC_S_CALL_FAILED ( 1726 )
#define WBEM_NO_ERROR ( 0 )
#define WBEM_S_NO_ERROR ( 0 )
#define WBEM_S_SAME ( 0 )
#define WBEM_S_FALSE ( 1 )
#define WBEM_S_ALREADY_EXISTS ( 0x40001 )
#define WBEM_S_RESET_TO_DEFAULT ( 0x40002 )
#define WBEM_S_DIFFERENT ( 0x40003 )
#define WBEM_S_TIMEDOUT ( 0x40004 )
#define WBEM_S_NO_MORE_DATA ( 0x40005 )
#define WBEM_S_OPERATION_CANCELLED ( 0x40006 )
#define WBEM_S_PENDING ( 0x40007 )
#define WBEM_S_DUPLICATE_OBJECTS ( 0x40008 )
#define WBEM_S_ACCESS_DENIED ( 0x40009 )
#define WBEM_S_PARTIAL_RESULTS ( 0x40010 )
#define WBEM_S_NO_POSTHOOK ( 0x40011 )
#define WBEM_S_POSTHOOK_WITH_BOTH ( 0x40012 )
#define WBEM_S_POSTHOOK_WITH_NEW ( 0x40013 )
#define WBEM_S_POSTHOOK_WITH_STATUS ( 0x40014 )
#define WBEM_S_POSTHOOK_WITH_OLD ( 0x40015 )
#define WBEM_S_REDO_PREHOOK_WITH_ORIGINAL_OBJECT ( 0x40016 )
#define WBEM_S_SOURCE_NOT_AVAILABLE ( 0x40017 )
#define WBEM_E_FAILED ( 0x80041001 )
#define WBEM_E_NOT_FOUND ( 0x80041002 )
#define WBEM_E_ACCESS_DENIED ( 0x80041003 )
#define WBEM_E_PROVIDER_FAILURE ( 0x80041004 )
#define WBEM_E_TYPE_MISMATCH ( 0x80041005 )
#define WBEM_E_OUT_OF_MEMORY ( 0x80041006 )
#define WBEM_E_INVALID_CONTEXT ( 0x80041007 )
#define WBEM_E_INVALID_PARAMETER ( 0x80041008 )
#define WBEM_E_NOT_AVAILABLE ( 0x80041009 )
#define WBEM_E_CRITICAL_ERROR ( 0x8004100A )
#define WBEM_E_INVALID_STREAM ( 0x8004100B )
#define WBEM_E_NOT_SUPPORTED ( 0x8004100C )
#define WBEM_E_INVALID_SUPERCLASS ( 0x8004100D )
#define WBEM_E_INVALID_NAMESPACE ( 0x8004100E )
#define WBEM_E_INVALID_OBJECT ( 0x8004100F )
#define WBEM_E_INVALID_CLASS ( 0x80041010 )
#define WBEM_E_PROVIDER_NOT_FOUND ( 0x80041011 )
#define WBEM_E_INVALID_PROVIDER_REGISTRATION ( 0x80041012 )
#define WBEM_E_PROVIDER_LOAD_FAILURE ( 0x80041013 )
#define WBEM_E_INITIALIZATION_FAILURE ( 0x80041014 )
#define WBEM_E_TRANSPORT_FAILURE ( 0x80041015 )
#define WBEM_E_INVALID_OPERATION ( 0x80041016 )
#define WBEM_E_INVALID_QUERY ( 0x80041017 )
#define WBEM_E_INVALID_QUERY_TYPE ( 0x80041018 )
#define WBEM_E_ALREADY_EXISTS ( 0x80041019 )
#define WBEM_E_OVERRIDE_NOT_ALLOWED ( 0x8004101A )
#define WBEM_E_PROPAGATED_QUALIFIER ( 0x8004101B )
#define WBEM_E_PROPAGATED_PROPERTY ( 0x8004101C )
#define WBEM_E_UNEXPECTED ( 0x8004101D )
#define WBEM_E_ILLEGAL_OPERATION ( 0x8004101E )
#define WBEM_E_CANNOT_BE_KEY ( 0x8004101F )
#define WBEM_E_INCOMPLETE_CLASS ( 0x80041020 )
#define WBEM_E_INVALID_SYNTAX ( 0x80041021 )
#define WBEM_E_NONDECORATED_OBJECT ( 0x80041022 )
#define WBEM_E_READ_ONLY ( 0x80041023 )
#define WBEM_E_PROVIDER_NOT_CAPABLE ( 0x80041024 )
#define WBEM_E_CLASS_HAS_CHILDREN ( 0x80041025 )
#define WBEM_E_CLASS_HAS_INSTANCES ( 0x80041026 )
#define WBEM_E_QUERY_NOT_IMPLEMENTED ( 0x80041027 )
#define WBEM_E_ILLEGAL_NULL ( 0x80041028 )
#define WBEM_E_INVALID_QUALIFIER_TYPE ( 0x80041029 )
#define WBEM_E_INVALID_PROPERTY_TYPE ( 0x8004102A )
#define WBEM_E_VALUE_OUT_OF_RANGE ( 0x8004102B )
#define WBEM_E_CANNOT_BE_SINGLETON ( 0x8004102C )
#define WBEM_E_INVALID_CIM_TYPE ( 0x8004102D )
#define WBEM_E_INVALID_METHOD ( 0x8004102E )
#define WBEM_E_INVALID_METHOD_PARAMETERS ( 0x8004102F )
#define WBEM_E_SYSTEM_PROPERTY ( 0x80041030 )
#define WBEM_E_INVALID_PROPERTY ( 0x80041031 )
#define WBEM_E_CALL_CANCELLED ( 0x80041032 )
#define WBEM_E_SHUTTING_DOWN ( 0x80041033 )
#define WBEM_E_PROPAGATED_METHOD ( 0x80041034 )
#define WBEM_E_UNSUPPORTED_PARAMETER ( 0x80041035 )
#define WBEM_E_MISSING_PARAMETER_ID ( 0x80041036 )
#define WBEM_E_INVALID_PARAMETER_ID ( 0x80041037 )
#define WBEM_E_NONCONSECUTIVE_PARAMETER_IDS ( 0x80041038 )
#define WBEM_E_PARAMETER_ID_ON_RETVAL ( 0x80041039 )
#define WBEM_E_INVALID_OBJECT_PATH ( 0x8004103A )
#define WBEM_E_OUT_OF_DISK_SPACE ( 0x8004103B )
#define WBEM_E_BUFFER_TOO_SMALL ( 0x8004103C )
#define WBEM_E_UNSUPPORTED_PUT_EXTENSION ( 0x8004103D )
#define WBEM_E_UNKNOWN_OBJECT_TYPE ( 0x8004103E )
#define WBEM_E_UNKNOWN_PACKET_TYPE ( 0x8004103F )
#define WBEM_E_MARSHAL_VERSION_MISMATCH ( 0x80041040 )
#define WBEM_E_MARSHAL_INVALID_SIGNATURE ( 0x80041041 )
#define WBEM_E_INVALID_QUALIFIER ( 0x80041042 )
#define WBEM_E_INVALID_DUPLICATE_PARAMETER ( 0x80041043 )
#define WBEM_E_TOO_MUCH_DATA ( 0x80041044 )
#define WBEM_E_SERVER_TOO_BUSY ( 0x80041045 )
#define WBEM_E_INVALID_FLAVOR ( 0x80041046 )
#define WBEM_E_CIRCULAR_REFERENCE ( 0x80041047 )
#define WBEM_E_UNSUPPORTED_CLASS_UPDATE ( 0x80041048 )
#define WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE ( 0x80041049 )
#define WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE ( 0x80041050 )
#define WBEM_E_TOO_MANY_PROPERTIES ( 0x80041051 )
#define WBEM_E_UPDATE_TYPE_MISMATCH ( 0x80041052 )
#define WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED ( 0x80041053 )
#define WBEM_E_UPDATE_PROPAGATED_METHOD ( 0x80041054 )
#define WBEM_E_METHOD_NOT_IMPLEMENTED ( 0x80041055 )
#define WBEM_E_METHOD_DISABLED ( 0x80041056 )
#define WBEM_E_REFRESHER_BUSY ( 0x80041057 )
#define WBEM_E_UNPARSABLE_QUERY ( 0x80041058 )
#define WBEM_E_NOT_EVENT_CLASS ( 0x80041059 )
#define WBEM_E_MISSING_GROUP_WITHIN ( 0x8004105A )
#define WBEM_E_MISSING_AGGREGATION_LIST ( 0x8004105B )
#define WBEM_E_PROPERTY_NOT_AN_OBJECT ( 0x8004105C )
#define WBEM_E_AGGREGATING_BY_OBJECT ( 0x8004105D )
#define WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY ( 0x8004105F )
#define WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING ( 0x80041060 )
#define WBEM_E_QUEUE_OVERFLOW ( 0x80041061 )
#define WBEM_E_PRIVILEGE_NOT_HELD ( 0x80041062 )
#define WBEM_E_INVALID_OPERATOR ( 0x80041063 )
#define WBEM_E_LOCAL_CREDENTIALS ( 0x80041064 )
#define WBEM_E_CANNOT_BE_ABSTRACT ( 0x80041065 )
#define WBEM_E_AMENDED_OBJECT ( 0x80041066 )
#define WBEM_E_CLIENT_TOO_SLOW ( 0x80041067 )
#define WBEM_E_NULL_SECURITY_DESCRIPTOR ( 0x80041068 )
#define WBEM_E_TIMED_OUT ( 0x80041069 )
#define WBEM_E_INVALID_ASSOCIATION ( 0x8004106A )
#define WBEM_E_AMBIGUOUS_OPERATION ( 0x8004106B )
#define WBEM_E_QUOTA_VIOLATION ( 0x8004106C )
#define WBEM_E_RESERVED_001 ( 0x8004106D )
#define WBEM_E_RESERVED_002 ( 0x8004106E )
#define WBEM_E_UNSUPPORTED_LOCALE ( 0x8004106F )
#define WBEM_E_HANDLE_OUT_OF_DATE ( 0x80041070 )
#define WBEM_E_CONNECTION_FAILED ( 0x80041071 )
#define WBEM_E_INVALID_HANDLE_REQUEST ( 0x80041072 )
#define WBEM_E_PROPERTY_NAME_TOO_WIDE ( 0x80041073 )
#define WBEM_E_CLASS_NAME_TOO_WIDE ( 0x80041074 )
#define WBEM_E_METHOD_NAME_TOO_WIDE ( 0x80041075 )
#define WBEM_E_QUALIFIER_NAME_TOO_WIDE ( 0x80041076 )
#define WBEM_E_RERUN_COMMAND ( 0x80041077 )
#define WBEM_E_DATABASE_VER_MISMATCH ( 0x80041078 )
#define WBEM_E_VETO_DELETE ( 0x80041079 )
#define WBEM_E_VETO_PUT ( 0x8004107A )
#define WBEM_E_INVALID_LOCALE ( 0x80041080 )
#define WBEM_E_PROVIDER_SUSPENDED ( 0x80041081 )
#define WBEM_E_SYNCHRONIZATION_REQUIRED ( 0x80041082 )
#define WBEM_E_NO_SCHEMA ( 0x80041083 )
#define WBEM_E_PROVIDER_ALREADY_REGISTERED ( 0x80041084 )
#define WBEM_E_PROVIDER_NOT_REGISTERED ( 0x80041085 )
#define WBEM_E_FATAL_TRANSPORT_ERROR ( 0x80041086 )
#define WBEM_E_ENCRYPTED_CONNECTION_REQUIRED ( 0x80041087 )
#define WBEM_E_PROVIDER_TIMED_OUT ( 0x80041088 )
#define WBEM_E_NO_KEY ( 0x80041089 )
#define WBEM_E_PROVIDER_DISABLED ( 0x8004108a )
#endif
;

/* bitmap WBEM_GENERIC_FLAG_TYPE */
#define WBEM_FLAG_RETURN_WBEM_COMPLETE ( 0 )
#define WBEM_FLAG_BIDIRECTIONAL ( 0 )
#define WBEM_FLAG_RETURN_IMMEDIATELY ( 0x000010 )
#define WBEM_FLAG_FORWARD_ONLY ( 0x000020 )
#define WBEM_FLAG_NO_ERROR_OBJECT ( 0x000040 )
#define WBEM_FLAG_SEND_STATUS ( 0x000080 )
#define WBEM_FLAG_ENSURE_LOCATABLE ( 0x000100 )
#define WBEM_FLAG_DIRECT_READ ( 0x000200 )
#define WBEM_FLAG_USE_AMENDED_QUALIFIERS ( 0x020000 )
#define WBEM_FLAG_STRONG_VALIDATION ( 0x100000 )
#define WBEM_FLAG_RETURN_ERROR_OBJECT ( 0 )
#define WBEM_FLAG_DONT_SEND_STATUS ( 0 )
#define WBEM_FLAG_SEND_ONLY_SELECTED ( 0 )
#define WBEM_RETURN_WHEN_COMPLETE ( 0 )
#define WBEM_RETURN_IMMEDIATELY ( WBEM_FLAG_RETURN_IMMEDIATELY )
#define WBEM_MASK_RESERVED_FLAGS ( 0x001F000 )

enum WBEM_TIMEOUT_TYPE
#ifndef USE_UINT_ENUMS
 {
	WBEM_NO_WAIT=(int)(0),
	WBEM_INFINITE=(int)(0xFFFFFFFF)
}
#else
 { __donnot_use_enum_WBEM_TIMEOUT_TYPE=0x7FFFFFFF}
#define WBEM_NO_WAIT ( 0 )
#define WBEM_INFINITE ( 0xFFFFFFFF )
#endif
;

enum CIMTYPE_ENUMERATION
#ifndef USE_UINT_ENUMS
 {
	CIM_EMPTY=(int)(0),
	CIM_SINT16=(int)(2),
	CIM_SINT32=(int)(3),
	CIM_REAL32=(int)(4),
	CIM_REAL64=(int)(5),
	CIM_STRING=(int)(8),
	CIM_BOOLEAN=(int)(11),
	CIM_OBJECT=(int)(13),
	CIM_SINT8=(int)(16),
	CIM_UINT8=(int)(17),
	CIM_UINT16=(int)(18),
	CIM_UINT32=(int)(19),
	CIM_SINT64=(int)(20),
	CIM_UINT64=(int)(21),
	CIM_DATETIME=(int)(101),
	CIM_REFERENCE=(int)(102),
	CIM_CHAR16=(int)(103),
	CIM_FLAG_ARRAY=(int)(0x2000),
	CIM_ILLEGAL=(int)(0x0fff),
	CIM_TYPEMASK=(int)(0x2fff),
	CIM_ARR_SINT8=(int)(CIM_FLAG_ARRAY|CIM_SINT8),
	CIM_ARR_UINT8=(int)(CIM_FLAG_ARRAY|CIM_UINT8),
	CIM_ARR_SINT16=(int)(CIM_FLAG_ARRAY|CIM_SINT16),
	CIM_ARR_UINT16=(int)(CIM_FLAG_ARRAY|CIM_UINT16),
	CIM_ARR_SINT32=(int)(CIM_FLAG_ARRAY|CIM_SINT32),
	CIM_ARR_UINT32=(int)(CIM_FLAG_ARRAY|CIM_UINT32),
	CIM_ARR_SINT64=(int)(CIM_FLAG_ARRAY|CIM_SINT64),
	CIM_ARR_UINT64=(int)(CIM_FLAG_ARRAY|CIM_UINT64),
	CIM_ARR_REAL32=(int)(CIM_FLAG_ARRAY|CIM_REAL32),
	CIM_ARR_REAL64=(int)(CIM_FLAG_ARRAY|CIM_REAL64),
	CIM_ARR_BOOLEAN=(int)(CIM_FLAG_ARRAY|CIM_BOOLEAN),
	CIM_ARR_STRING=(int)(CIM_FLAG_ARRAY|CIM_STRING),
	CIM_ARR_DATETIME=(int)(CIM_FLAG_ARRAY|CIM_DATETIME),
	CIM_ARR_REFERENCE=(int)(CIM_FLAG_ARRAY|CIM_REFERENCE),
	CIM_ARR_CHAR16=(int)(CIM_FLAG_ARRAY|CIM_CHAR16),
	CIM_ARR_OBJECT=(int)(CIM_FLAG_ARRAY|CIM_OBJECT)
}
#else
 { __donnot_use_enum_CIMTYPE_ENUMERATION=0x7FFFFFFF}
#define CIM_EMPTY ( 0 )
#define CIM_SINT16 ( 2 )
#define CIM_SINT32 ( 3 )
#define CIM_REAL32 ( 4 )
#define CIM_REAL64 ( 5 )
#define CIM_STRING ( 8 )
#define CIM_BOOLEAN ( 11 )
#define CIM_OBJECT ( 13 )
#define CIM_SINT8 ( 16 )
#define CIM_UINT8 ( 17 )
#define CIM_UINT16 ( 18 )
#define CIM_UINT32 ( 19 )
#define CIM_SINT64 ( 20 )
#define CIM_UINT64 ( 21 )
#define CIM_DATETIME ( 101 )
#define CIM_REFERENCE ( 102 )
#define CIM_CHAR16 ( 103 )
#define CIM_FLAG_ARRAY ( 0x2000 )
#define CIM_ILLEGAL ( 0x0fff )
#define CIM_TYPEMASK ( 0x2fff )
#define CIM_ARR_SINT8 ( CIM_FLAG_ARRAY|CIM_SINT8 )
#define CIM_ARR_UINT8 ( CIM_FLAG_ARRAY|CIM_UINT8 )
#define CIM_ARR_SINT16 ( CIM_FLAG_ARRAY|CIM_SINT16 )
#define CIM_ARR_UINT16 ( CIM_FLAG_ARRAY|CIM_UINT16 )
#define CIM_ARR_SINT32 ( CIM_FLAG_ARRAY|CIM_SINT32 )
#define CIM_ARR_UINT32 ( CIM_FLAG_ARRAY|CIM_UINT32 )
#define CIM_ARR_SINT64 ( CIM_FLAG_ARRAY|CIM_SINT64 )
#define CIM_ARR_UINT64 ( CIM_FLAG_ARRAY|CIM_UINT64 )
#define CIM_ARR_REAL32 ( CIM_FLAG_ARRAY|CIM_REAL32 )
#define CIM_ARR_REAL64 ( CIM_FLAG_ARRAY|CIM_REAL64 )
#define CIM_ARR_BOOLEAN ( CIM_FLAG_ARRAY|CIM_BOOLEAN )
#define CIM_ARR_STRING ( CIM_FLAG_ARRAY|CIM_STRING )
#define CIM_ARR_DATETIME ( CIM_FLAG_ARRAY|CIM_DATETIME )
#define CIM_ARR_REFERENCE ( CIM_FLAG_ARRAY|CIM_REFERENCE )
#define CIM_ARR_CHAR16 ( CIM_FLAG_ARRAY|CIM_CHAR16 )
#define CIM_ARR_OBJECT ( CIM_FLAG_ARRAY|CIM_OBJECT )
#endif
;

/* bitmap WBEM_FLAVOR_TYPE */
#define WBEM_FLAVOR_FLAG_PROPAGATE_TO_INSTANCE ( 0x1 )
#define WBEM_FLAVOR_FLAG_PROPAGATE_TO_DERIVED_CLASS ( 0x2 )
#define WBEM_FLAVOR_NOT_OVERRIDABLE ( 0x10 )
#define WBEM_FLAVOR_ORIGIN_PROPAGATED ( 0x20 )
#define WBEM_FLAVOR_ORIGIN_SYSTEM ( 0x40 )
#define WBEM_FLAVOR_AMENDED ( 0x80 )

/* bitmap WCO_FLAGS */
#define WCF_DECORATIONS ( 1 )
#define WCF_INSTANCE ( 2 )
#define WCF_CLASS ( 4 )
#define WCF_CLASS_PART_INTERNAL ( 8 )

struct CIMSTRINGS {
	uint32_t count;
	const char **item;/* [ref,charset(UTF16)] */
};

/* bitmap DEFAULT_FLAGS */
#define DEFAULT_FLAG_EMPTY ( 1 )
#define DEFAULT_FLAG_INHERITED ( 2 )


struct OpenNamespace {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strNamespace;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppWorkingNamespace;/* [unique] */
		struct MInterfacePointer **ppResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppWorkingNamespace;/* [unique] */
		struct MInterfacePointer **ppResult;/* [unique] */
		WERROR result;
	} out;

};


struct CancelAsyncCall {
	struct {
		struct ORPCTHIS ORPCthis;
		struct MInterfacePointer *pSink;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct QueryObjectSink {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lFlags;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppResponseHandler;/* [ref] */
		WERROR result;
	} out;

};


struct GetObject {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppObject;/* [unique] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppObject;/* [unique] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct GetObjectAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct PutClass {
	struct {
		struct ORPCTHIS ORPCthis;
		struct MInterfacePointer *pObject;/* [ref] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct PutClassAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct MInterfacePointer *pObject;/* [ref] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct DeleteClass {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strClass;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct DeleteClassAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strClass;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct CreateClassEnum {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strSuperclass;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct CreateClassEnumAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strSuperclass;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct PutInstance {
	struct {
		struct ORPCTHIS ORPCthis;
		struct MInterfacePointer *pInst;/* [ref] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct PutInstanceAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct MInterfacePointer *pInst;/* [ref] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct DeleteInstance {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct DeleteInstanceAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct CreateInstanceEnum {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strFilter;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct CreateInstanceEnumAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strSuperClass;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct ExecQuery {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strQueryLanguage;
		struct BSTR strQuery;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct ExecQueryAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strQueryLanguage;
		struct BSTR strQuery;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct ExecNotificationQuery {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strQueryLanguage;
		struct BSTR strQuery;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct ExecNotificationQueryAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strQueryLanguage;
		struct BSTR strQuery;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct ExecMethod {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		struct BSTR strMethodName;
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [unique] */
		struct MInterfacePointer *pInParams;/* [unique] */
		struct MInterfacePointer **ppOutParams;/* [unique] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppOutParams;/* [unique] */
		struct MInterfacePointer **ppCallResult;/* [unique] */
		WERROR result;
	} out;

};


struct ExecMethodAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		struct BSTR strObjectPath;
		struct BSTR strMethodName;
		uint32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
		struct MInterfacePointer *pInParams;/* [ref] */
		struct MInterfacePointer *pResponseHandler;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemServices */
#ifndef _HEADER_IEnumWbemClassObject
#define _HEADER_IEnumWbemClassObject


struct Reset {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct IEnumWbemClassObject_Next {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
		uint32_t uCount;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **apObjects;/* [ref,length_is(*puReturned),size_is(uCount)] */
		uint32_t *puReturned;/* [ref] */
		WERROR result;
	} out;

};


struct NextAsync {
	struct {
		struct ORPCTHIS ORPCthis;
		uint32_t uCount;
		struct MInterfacePointer *pSink;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct IEnumWbemClassObject_Clone {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct Skip {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
		uint32_t nCount;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IEnumWbemClassObject */
#ifndef _HEADER_IWbemContext
#define _HEADER_IWbemContext


struct Clone {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppNewCopy;/* [ref] */
		WERROR result;
	} out;

};


struct GetNames {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct BeginEnumeration {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lFlags;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct Next {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct EndEnumeration {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct SetValue {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct GetValue {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct DeleteValue {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct DeleteAll {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemContext */
#ifndef _HEADER_IWbemLevel1Login
#define _HEADER_IWbemLevel1Login


struct EstablishPosition {
	struct {
		struct ORPCTHIS ORPCthis;
		const char *wszLocaleList;/* [unique,charset(UTF16)] */
		uint32_t dwNumLocales;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		uint32_t *reserved;/* [ref] */
		WERROR result;
	} out;

};


struct RequestChallenge {
	struct {
		struct ORPCTHIS ORPCthis;
		const char *wszNetworkResource;/* [unique,charset(UTF16)] */
		const char *wszUser;/* [charset(UTF16),unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		uint8_t *Nonce;/* [size_is(16),length_is(16),ref] */
		WERROR result;
	} out;

};


struct WBEMLogin {
	struct {
		struct ORPCTHIS ORPCthis;
		const char *wszPreferredLocale;/* [unique,charset(UTF16)] */
		uint8_t *AccessToken;/* [length_is(16),size_is(16),unique] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppNamespace;/* [ref] */
		WERROR result;
	} out;

};


struct NTLMLogin {
	struct {
		struct ORPCTHIS ORPCthis;
		const char *wszNetworkResource;/* [unique,charset(UTF16)] */
		const char *wszPreferredLocale;/* [charset(UTF16),unique] */
		int32_t lFlags;
		struct MInterfacePointer *pCtx;/* [unique] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppNamespace;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemLevel1Login */
#ifndef _HEADER_IWbemWCOSmartEnum
#define _HEADER_IWbemWCOSmartEnum

struct WBEMDATA {
	uint32_t size;
	uint8_t *data;
};

enum WTYPES
#ifndef USE_UINT_ENUMS
 {
	WTYPE_SCHEMA=(int)(1),
	WTYPE_CLASS=(int)(2),
	WTYPE_OBJECT=(int)(3)
}
#else
 { __donnot_use_enum_WTYPES=0x7FFFFFFF}
#define WTYPE_SCHEMA ( 1 )
#define WTYPE_CLASS ( 2 )
#define WTYPE_OBJECT ( 3 )
#endif
;

struct WBEMDATA4 {
	uint32_t data_size;
	uint8_t wtype;
}/* [relative_base] */;

struct WBEMDATA3 {
	struct WBEMDATA4 *data;/* [relative] */
	uint32_t data_size;
	uint8_t wtype;
}/* [relative_base] */;

struct WBEMDATA2 {
	struct WBEMDATA3 *data;/* [size_is(obj_num),relative] */
	uint32_t data_size;
	uint32_t obj_num;
}/* [relative_base] */;

struct WBEMDATA1 {
	struct WBEMDATA2 *data;/* [relative] */
	uint32_t data_size;
}/* [relative_base] */;

struct WBEMDATA0 {
	uint32_t u1_0;
	uint64_t signature;
	struct WBEMDATA1 *data;/* [relative] */
	uint32_t data_size;
	uint32_t u2_0;
	uint8_t ver_major;
	uint8_t ver_minor;
}/* [relative_base] */;


struct IWbemWCOSmartEnum_Next {
	struct {
		struct ORPCTHIS ORPCthis;
		struct GUID *gEWCO;/* [ref] */
		uint32_t lTimeOut;
		uint32_t uCount;
		uint32_t unknown;
		struct GUID *gWCO;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		uint32_t *puReturned;/* [ref] */
		uint32_t *pSize;/* [ref] */
		uint8_t **pData;/* [ref,size_is(,*pSize)] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemWCOSmartEnum */
#ifndef _HEADER_IWbemFetchSmartEnum
#define _HEADER_IWbemFetchSmartEnum


struct Fetch {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};


struct Test {
	struct {
		struct ORPCTHIS ORPCthis;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppEnum;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemFetchSmartEnum */
#ifndef _HEADER_IWbemCallResult
#define _HEADER_IWbemCallResult


struct GetResultObject {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppResultObject;/* [ref] */
		WERROR result;
	} out;

};


struct GetResultString {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct BSTR *pstrResultString;/* [ref] */
		WERROR result;
	} out;

};


struct GetResultServices {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		struct MInterfacePointer **ppServices;/* [ref] */
		WERROR result;
	} out;

};


struct GetCallStatus {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lTimeout;
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		int32_t *plStatus;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemCallResult */
#ifndef _HEADER_IWbemObjectSink
#define _HEADER_IWbemObjectSink


struct SetStatus {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lFlags;
		WERROR hResult;
		struct BSTR strParam;
		struct MInterfacePointer *pObjParam;/* [ref] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};


struct Indicate {
	struct {
		struct ORPCTHIS ORPCthis;
		int32_t lObjectCount;
		struct MInterfacePointer **apObjArray;/* [ref,size_is(lObjectCount)] */
	} in;

	struct {
		struct ORPCTHAT *ORPCthat;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_IWbemObjectSink */
#endif /* _PIDL_HEADER_IWbemClassObject */
