#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <libgen.h>

#define MAX_Cmdln 1024
#define MAX_line_len 1000*(sizeof(char))

void sortStrings(char arr[][50], int n) ;
void fn_ls(char* command,char* option) ;
int fn_cp(char* cmd,char *option) ;
int fn_mv(char* cmd,char *option) ;
void add_clr(char* line,char* str) ;
int fn_grep(char* cmd,char* option) ;
int fn_ps(char* cmd,char* option) ;
