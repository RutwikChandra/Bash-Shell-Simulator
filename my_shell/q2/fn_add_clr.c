#include "my_header.h"

void add_clr(char* line,char* sub_str){

char* ptr;
int n = strlen(sub_str);
char red[] = "\x1b[31m";
char def_clr[]= "\x1b[0m" ;
int k;

 while ((ptr = strstr(line, sub_str))!=NULL) {
        k = (ptr-line);
        printf("%.*s", k, line);
        printf("%s%.*s%s", red, n, ptr, def_clr);
        line = ptr + n;
    }

    printf("%s", line);

}
