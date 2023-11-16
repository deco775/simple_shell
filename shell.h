#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/*reading and writing buffers*/
#define BUFF_SIZE_READ 1024
#define FLUSH_BUFF -1
#define BUFF_SIZE_WRITE 1024

/*chaining the commands */
#define NOM_COMND 0
#define AND_COMND 2
#define CHAIN_COMND 3
#define OR_COMND 1

/*corvertin the numbers*/
#define LOWCASE_CONV 1
#define UNS_CONV 2

/* it will be 1 if system getline is used*/
#define GETLINE_U_S_E 0
#define STRTOK_U_S_E 0

#define FILE_HIS ".simple_shell_history"
#define MAX_HIS 4096

extern char **envrn;

typedef struct strlist
{
	char *strin;
	int numbr;
	struct strlist *next;
} t_lst;

typedef struct infpas
{
	char *pathway;
	char **argumntV;
	char *argumnt;
	int argc;
	int numbr_err;
	unsigned int lineCnt;
	int lncntFlag;
	char *name_F;
	t_lst *env;
	t_lst *hstry;
	t_lst *alias;
	t_lst **envrnmnt;
	int chngedEvn;
	int s_tatus;

	char **buffCMD;
	int buffCMDtype;
	int fd_read;
	int counthstry;
} tsl_inf;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}

typedef struct inblt
{
	int (*funct)(tsl_inf*);
	char *type;

} table_inblt;

int hsh(tsl_inf *, char **);
int inblt_fnd(tsl_inf *);
void comnd_fnd(tsl_inf *);
void comnd_fork(tsl_inf *);

int isComnd(tsl_inf *, char *);
char *charDup(char *, int, int);
char *pathFnd(tsl_inf *, char *, char *);

int hsh_loop(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *strtWith(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_dupstr( const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchar(char *,char);

char **tow_str(char *, char, unsigned int);
char **tow_str2(char *, char);

char *_memset(char *, char, unsigned int);
void frfree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int freebuff(void **);

int int_actv(tsl_inf *);
int isDelm(char, char *);
int is_alph(int);
int a_toi(char *);

int atoi_err(char *);
void errPrint(tsl_inf *, char *);
int delPrint(int, int);
char *numConvt(long int, int, int);
void commntRemove(char *);

int myExt(tsl_inf *);
int mineCD(tsl_inf *);
int meHlp(tsl_inf *);

int mHstry(tsl_inf *);
int mAlas(tsl_inf *);

ssize_t inptGet(tsl_inf *);
int lnget(tsl_inf *, char **, size_t *);
void int_singHandl(int);

void infClr(tsl_inf *);
void infSet(tsl_inf *, char **);
void inffFree(tsl_inf *, int);

char *_getenv(tsl_inf *, const char *);
int  _myenv(tsl_inf *);
int  _myenv(tsl_inf *);
int _myunsetenv(tsl_inf *);
int envList_poplt(tsl_inf *);

char **envGet(tsl_inf *);
int _unsetenv(tsl_inf *, char *);
int _setenv(tsl_inf *, char *, char *);

char *hstryFile_get(tsl_inf *info);
int hstryWrte(tsl_inf *info);
int hstryRead(tsl_inf *info);
int hstryLs_bld(tsl_inf *info, char *buf, int linecount);
int hstryRenm(tsl_inf *info);

t_lst *nodeAdd(t_lst **, const char *, int);
t_lst *endNode_add(t_lst **, const char *, int);
size_t strlsPrint(const t_lst *);
int nodedel_index(t_lst **, unsigned int);
void lsFree(t_lst **);

size_t lengLs(const t_lst *);
char **lsTostr(t_lst *);
size_t lsPrintt(const t_lst *);
t_lst *strtsNode(t_lst *, char *, char);
ssize_t nodeGet_indx(t_lst *, t_lst *);

int issChn(tsl_inf *, char *, size_t);
void chnCheck(tsl_inf *, char *, size_t *, size_t, size_t);
int alsReplc(tsl_inf *);
int varsReplc(tsl_inf *);
int strReplc(char **, char *);

#endif
