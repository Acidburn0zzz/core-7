/* 

   Copyright (C) Cfengine AS

   This file is part of Cfengine 3 - written and maintained by Cfengine AS.
 
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License  
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of Cfengine, the applicable Commerical Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.
*/


/*****************************************************************************/
/*                                                                           */
/* File: cf3globals.c                                                        */
/*                                                                           */
/* Created: Thu Aug  2 11:08:10 2007                                         */
/*                                                                           */
/*****************************************************************************/

#include "cf3.defs.h"

/*****************************************************************************/
/* flags                                                                     */
/*****************************************************************************/

int SHOWREPORTS = false;
int SHOW_PARSE_TREE = false;
int USE_GCC_BRIEF_FORMAT = false;

/*****************************************************************************/
/* operational state                                                         */
/*****************************************************************************/

int VERBOSE = false;
int INFORM = false;
int PARSING = false;
int CFPARANOID = false;
int REQUIRE_COMMENTS = CF_UNDEFINED;
int LOOKUP = false;
int IGNORE_MISSING_INPUTS = false;
int IGNORE_MISSING_BUNDLES = false;
int FIPS_MODE = false;
int ALWAYS_VALIDATE = false;
bool ALLCLASSESREPORT = false;

struct utsname VSYSNAME;

FILE *FREPORT_HTML = NULL;
FILE *FREPORT_TXT = NULL;
FILE *FKNOW = NULL;
int XML = false;

int CFA_MAXTHREADS = 10;
int CFA_BACKGROUND = 0;
int CFA_BACKGROUND_LIMIT = 1;
int AM_BACKGROUND_PROCESS = false;
int CF_PERSISTENCE = 10;

char *THIS_BUNDLE = NULL;
char THIS_AGENT[CF_MAXVARSIZE] = {0};
enum cfagenttype THIS_AGENT_TYPE;
time_t PROMISETIME = 0;
time_t CF_LOCKHORIZON = SECONDS_PER_WEEK * 4;

int LICENSES = 0;
int AM_NOVA = false;
int AM_CONSTELLATION = false;
int AM_PHP_MODULE = false;
char EXPIRY[CF_SMALLBUF] = {0};
char LICENSE_COMPANY[CF_SMALLBUF] = {0};
int KEYTTL = 0;

// These are used to measure graph complexity in know/agent

int CSV=false;
int CF_TOPICS = 0; // objects
int CF_OCCUR = 0; // objects
int CF_EDGES = 0; // links or promises between them

Rlist *MOUNTEDFSLIST = NULL;
PromiseIdent *PROMISE_ID_LIST = NULL;
Item *PROCESSTABLE = NULL;
Item *PROCESSREFRESH = NULL;
Item *ROTATED = NULL;
Item *FSTABLIST = NULL;
Item *ABORTBUNDLEHEAP = NULL;
Item *DONELIST = NULL;
Rlist *SERVER_KEYSEEN = NULL;

char *CBUNDLESEQUENCE_STR;

int EDIT_MODEL = false;
int CF_MOUNTALL = false;
int FSTAB_EDITS;
int ABORTBUNDLE = false;
int BOOTSTRAP = false;

char HASHDB[CF_BUFSIZE] = {0};

/*****************************************************************************/
/* Measurements                                                              */
/*****************************************************************************/

double METER_KEPT[meter_endmark];
double METER_REPAIRED[meter_endmark];

double Q_MEAN;
double Q_SIGMA;

/*****************************************************************************/
/* Internal data structures                                                  */
/*****************************************************************************/

PromiseParser P = {0};
Bundle *BUNDLES = NULL;
Body *BODIES = NULL;
Scope *VSCOPE = NULL;
Rlist *VINPUTLIST = NULL;
Rlist *BODYPARTS = NULL;
Rlist *SUBBUNDLES = NULL;
Rlist *ACCESSLIST = NULL;

Rlist *SINGLE_COPY_LIST = NULL;
Rlist *AUTO_DEFINE_LIST = NULL;
Rlist *SINGLE_COPY_CACHE = NULL;
Rlist *CF_STCK = NULL;

Item *EDIT_ANCHORS = NULL;

int CF_STCKFRAME = 0;
int LASTSEENEXPIREAFTER = SECONDS_PER_WEEK;

char POLICY_SERVER[CF_BUFSIZE] = {0};

char WEBDRIVER[CF_MAXVARSIZE] = {0};
char DOCROOT[CF_MAXVARSIZE] = {0};
char BANNER[2*CF_BUFSIZE] = {0};
char FOOTER[CF_BUFSIZE] = {0};
char STYLESHEET[CF_BUFSIZE] = {0};

/*****************************************************************************/
/* Windows version constants                                                 */
/*****************************************************************************/

unsigned int WINVER_MAJOR = 0;
unsigned int WINVER_MINOR = 0;
unsigned int WINVER_BUILD = 0;


/*****************************************************************************/
/* Constants                                                                 */
/*****************************************************************************/

SubTypeSyntax CF_NOSTYPE = {NULL,NULL,NULL};

/*********************************************************************/
/* Object variables                                                  */
/*********************************************************************/

const char *DAY_TEXT[] =
   {
   "Monday",
   "Tuesday",
   "Wednesday",
   "Thursday",
   "Friday",
   "Saturday",
   "Sunday",
   NULL
   };

const char *MONTH_TEXT[] =
   {
   "January",
   "February",
   "March",
   "April",
   "May",
   "June",
   "July",
   "August",
   "September",
   "October",
   "November",
   "December",
   NULL
   };

const char *SHIFT_TEXT[] =
   {
   "Night",
   "Morning",
   "Afternoon",
   "Evening",
   NULL
   };

/*****************************************************************************/

const char *CF_DATATYPES[] = /* see enum cfdatatype */
   {
   "string",
   "int",
   "real",
   "slist",
   "ilist",
   "rlist",
   "(menu option)",
   "(option list)",
   "(ext body)",
   "(ext bundle)",
   "class",
   "clist",
   "irange [int,int]",
   "rrange [real,real]",
   "counter",
   "<notype>",
   };

/*****************************************************************************/

const char *CF_AGENTTYPES[] = /* see enum cfagenttype */
   {
   CF_COMMONC,
   CF_AGENTC,
   CF_SERVERC,
   CF_MONITORC,
   CF_EXECC,
   CF_RUNC,
   CF_KNOWC,
   CF_REPORTC,
   CF_KEYGEN,
   CF_HUBC,
   "<notype>",
   };

/*****************************************************************************/
/* Compatability infrastructure                                              */
/*****************************************************************************/

double FORGETRATE = 0.7;

int IGNORELOCK = false;
int DONTDO = false;
int DEBUG = false;
int AUDIT = false;
int LOGGING = false;

char  VFQNAME[CF_MAXVARSIZE] = {0};
char  VUQNAME[CF_MAXVARSIZE] = {0};
char  VDOMAIN[CF_MAXVARSIZE] = {0};

char  VYEAR[5] = {0};
char  VDAY[3] = {0};
char  VMONTH[4] = {0};
char  VSHIFT[12] = {0};

char PADCHAR = ' ';
char PURGE = 'n';

int ERRORCOUNT = 0;
char VPREFIX[CF_MAXVARSIZE] = {0};
char VINPUTFILE[CF_BUFSIZE] = {0};

char CONTEXTID[32] = {0};
char CFPUBKEYFILE[CF_BUFSIZE] = {0};
char CFPRIVKEYFILE[CF_BUFSIZE] = {0};
char AVDB[CF_MAXVARSIZE] = {0};
char CFWORKDIR[CF_BUFSIZE] = {0};
char PIDFILE[CF_BUFSIZE] = {0};

char *DEFAULT_COPYTYPE = NULL;

RSA *PRIVKEY = NULL, *PUBKEY = NULL;
char PUBKEY_DIGEST[CF_MAXVARSIZE] = {0};

#if defined HAVE_PTHREAD_H && (defined HAVE_LIBPTHREAD || defined BUILDTIN_GCC_THREAD)
pthread_attr_t PTHREADDEFAULTS;

# ifndef PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
#  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP PTHREAD_MUTEX_INITIALIZER
# endif

pthread_mutex_t MUTEXES[] =
   {
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP,
   };

pthread_mutex_t *cft_system = &MUTEXES[0];
pthread_mutex_t *cft_lock = &MUTEXES[1];
pthread_mutex_t *cft_count = &MUTEXES[2];
pthread_mutex_t *cft_output = &MUTEXES[3];
pthread_mutex_t *cft_dbhandle = &MUTEXES[4];
pthread_mutex_t *cft_policy = &MUTEXES[5];
pthread_mutex_t *cft_getaddr = &MUTEXES[6];
pthread_mutex_t *cft_report = &MUTEXES[7];
pthread_mutex_t *cft_vscope = &MUTEXES[8];
pthread_mutex_t *cft_server_keyseen = &MUTEXES[9];
pthread_mutex_t *cft_server_children = &MUTEXES[10];
#endif

char VIPADDRESS[18] = {0};
int  CFSIGNATURE = 0;

Item *IPADDRESSES = NULL;

int PR_KEPT = 0;
int PR_REPAIRED = 0;
int PR_NOTKEPT = 0;

double VAL_KEPT = 0;
double VAL_REPAIRED = 0;
double VAL_NOTKEPT = 0;

/*******************************************************************/
/* Context Management                                              */
/*******************************************************************/

AlphaList VHEAP;
AlphaList VADDCLASSES;
Item *VNEGHEAP = NULL;

Rlist *GOALS = NULL;
Rlist *GOALCATEGORIES = NULL;

/*******************************************************************/
/*                                                                 */
/* Checksums                                                       */
/*                                                                 */
/*******************************************************************/

/* These string lengths should not exceed CF_MAXDIGESTNAMELEN
   characters for packing */

const char *CF_DIGEST_TYPES[10][2] =
     {
     {"md5","m"},
     {"sha224","c"},
     {"sha256","C"},
     {"sha384","h"},
     {"sha512","H"},
     {"sha1","S"},
     {"sha","s"},   /* Should come last, since substring */
     {"best","b"},
     {"crypt","o"},
     {NULL,NULL}
     };

const int CF_DIGEST_SIZES[10] =
     {
     CF_MD5_LEN,
     CF_SHA224_LEN,
     CF_SHA256_LEN,
     CF_SHA384_LEN,
     CF_SHA512_LEN,
     CF_SHA1_LEN,
     CF_SHA_LEN,
     CF_BEST_LEN,
     CF_CRYPT_LEN,
     0
     };

enum cfhashes CF_DEFAULT_DIGEST;
int CF_DEFAULT_DIGEST_LEN;

/***********************************************************/

Audit *AUDITPTR;
Audit *VAUDIT = NULL; 
CF_DB  *AUDITDBP = NULL;

char CFLOCK[CF_BUFSIZE] = {0};
char CFLOG[CF_BUFSIZE] = {0};
char CFLAST[CF_BUFSIZE] = {0}; 
char LOGFILE[CF_MAXVARSIZE] = {0};

time_t CFSTARTTIME;
time_t CFINITSTARTTIME;
char  STR_CFENGINEPORT[16] = {0};
unsigned short SHORT_CFENGINEPORT;
time_t CONNTIMEOUT = 10;	   /* seconds */
pid_t ALARM_PID = -1;
int SKIPIDENTIFY = false;
int EDITFILESIZE = 10000;
int VIFELAPSED = 1;
int VEXPIREAFTER = 120;
int CHECKSUMUPDATES = false;
char BINDINTERFACE[CF_BUFSIZE] = {0};
int MINUSF = false;
int EXCLAIM = true;

mode_t DEFAULTMODE = (mode_t) 0755;

char *VREPOSITORY = NULL;
char REPOSCHAR = '_';

Item *VDEFAULTROUTE=NULL;
Item *VSETUIDLIST = NULL;
Item *SUSPICIOUSLIST = NULL;
enum classes VSYSTEMHARDCLASS = unused1;
Item *NONATTACKERLIST = NULL;
Item *MULTICONNLIST = NULL;
Item *TRUSTKEYLIST = NULL;
Item *DHCPLIST = NULL;
Item *ALLOWUSERLIST = NULL;
Item *SKIPVERIFY = NULL;
Item *ATTACKERLIST = NULL;
Item *ABORTHEAP = NULL;

Item *VREPOSLIST=NULL;

 /*******************************************************************/
 /* Anomaly                                                         */
 /*******************************************************************/

Sock ECGSOCKS[ATTR] = /* extended to map old to new using enum*/
   {
   {"137","netbiosns",ob_netbiosns_in,ob_netbiosns_out},
   {"138","netbiosdgm",ob_netbiosdgm_in,ob_netbiosdgm_out},
   {"139","netbiosssn",ob_netbiosssn_in,ob_netbiosssn_out},
   {"194","irc",ob_irc_in,ob_irc_out},
   {"5308","cfengine",ob_cfengine_in,ob_cfengine_out},
   {"2049","nfsd",ob_nfsd_in,ob_nfsd_out},
   {"25","smtp",ob_smtp_in,ob_smtp_out},
   {"80","www",ob_www_in,ob_www_out},
   {"21","ftp",ob_ftp_in,ob_ftp_out},
   {"22","ssh",ob_ssh_in,ob_ssh_out},
   {"443","wwws",ob_wwws_in,ob_wwws_out}
   };

char *TCPNAMES[CF_NETATTR] =
   {
   "icmp",
   "udp",
   "dns",
   "tcpsyn",
   "tcpack",
   "tcpfin",
   "misc"
   };

char *OBS[CF_OBSERVABLES][2] =
    {
    {"users","Users with active processes"},
    {"rootprocs","Sum privileged system processes"},
    {"otherprocs","Sum non-privileged process"},
    {"diskfree","Free disk on / partition"},
    {"loadavg","Kernel load average utilization (sum over cores)"},
    {"netbiosns_in","netbios name lookups (in)"},
    {"netbiosns_out","netbios name lookups (out)"},
    {"netbiosdgm_in","netbios name datagrams (in)"},
    {"netbiosdgm_out","netbios name datagrams (out)"},
    {"netbiosssn_in","netbios name sessions (in)"},
    {"netbiosssn_out","netbios name sessions (out)"},
    {"irc_in","IRC connections (in)"},
    {"irc_out","IRC connections (out)"},
    {"cfengine_in","cfengine connections (in)"},
    {"cfengine_out","cfengine connections (out)"},
    {"nfsd_in","nfs connections (in)"},
    {"nfsd_out","nfs connections (out)"},
    {"smtp_in","smtp connections (in)"},
    {"smtp_out","smtp connections (out)"},
    {"www_in","www connections (in)"},
    {"www_out","www connections (out)"},
    {"ftp_in","ftp connections (in)"},
    {"ftp_out","ftp connections (out)"},
    {"ssh_in","ssh connections (in)"},
    {"ssh_out","ssh connections (out)"},
    {"wwws_in","wwws connections (in)"},
    {"wwws_out","wwws connections (out)"},
    {"icmp_in","ICMP packets (in)"},
    {"icmp_out","ICMP packets (out)"},
    {"udp_in","UDP dgrams (in)"},
    {"udp_out","UDP dgrams (out)"},
    {"dns_in","DNS requests (in)"},
    {"dns_out","DNS requests (out)"},
    {"tcpsyn_in","TCP sessions (in)"},
    {"tcpsyn_out","TCP sessions (out)"},
    {"tcpack_in","TCP acks (in)"},
    {"tcpack_out","TCP acks (out)"},
    {"tcpfin_in","TCP finish (in)"},
    {"tcpfin_out","TCP finish (out)"},
    {"tcpmisc_in","TCP misc (in)"},
    {"tcpmisc_out","TCP misc (out)"},
    {"webaccess","Webserver hits"},
    {"weberrors","Webserver errors"},
    {"syslog","New log entries (Syslog)"},
    {"messages","New log entries (messages)"},
    {"temp0","CPU Temperature 0"},
    {"temp1","CPU Temperature 1"},
    {"temp2","CPU Temperature 2"},
    {"temp3","CPU Temperature 3"},
    {"cpu","%CPU utilization (all)"},
    {"cpu0","%CPU utilization 0"},
    {"cpu1","%CPU utilization 1"},
    {"cpu2","%CPU utilization 2"},
    {"cpu3","%CPU utilization 3"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    {"spare","unused"},
    };
