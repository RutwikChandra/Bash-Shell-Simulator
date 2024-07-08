#include "my_header.h"

int fn_grep(char* cmd,char* option){

if(option[0]!='-'){

char str1[MAX_Cmdln];
strcpy(str1,cmd);


   char *token;
   int i=1;
   char *sub_str = malloc(MAX_line_len);
   char *file_name = malloc(MAX_Cmdln);
   char *line = malloc(MAX_line_len);
   
   token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==2){
    strcpy(sub_str,token);
    }
    
    if(i==3){
    strcpy(file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
 

FILE *fp;

fp = fopen(file_name,"r");
if (fp == NULL) {
        printf("Error: No such file or directory \n");
        return 1;
    }


 while (fgets(line,100, fp) != NULL) {
      if(strstr(line,sub_str)!=NULL){  
      add_clr(line,sub_str);
      }
    }

fclose(fp);

free(sub_str);
free(file_name);
free(line);

}

else if(strcmp(option,"-n")==0){

char str1[MAX_Cmdln];
strcpy(str1,cmd);


   char *token;
   int i=1;
   char *sub_str = malloc(MAX_line_len);
   char *file_name = malloc(MAX_Cmdln);
   char *line = malloc(MAX_line_len);
   int count=1;
   
   token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(sub_str,token);
    }
    
    if(i==4){
    strcpy(file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
 

FILE *fp;

fp = fopen(file_name,"r");
if (fp == NULL) {
        printf("Error: No such file or directory \n");
        return 1;
    }


 while (fgets(line,100, fp) != NULL) {
      if(strstr(line,sub_str)!=NULL){  
      printf("%d:  ",count);
      add_clr(line,sub_str);
      }
      
      count++;
    }

fclose(fp);

free(sub_str);
free(file_name);
free(line);


}

else if(strcmp(option,"-H")==0){

char str1[MAX_Cmdln];
strcpy(str1,cmd);


   char *token;
   int i=1;
   char *sub_str = malloc(MAX_line_len);
   char *file_name = malloc(MAX_Cmdln);
   char *line = malloc(MAX_line_len);
   
   token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(sub_str,token);
    }
    
    if(i==4){
    strcpy(file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
 

FILE *fp;

fp = fopen(file_name,"r");
if (fp == NULL) {
        printf("Error: No such file or directory \n");
        return 1;
    }


 while (fgets(line,100, fp) != NULL) {
      if(strstr(line,sub_str)!=NULL){ 
      printf("%s:  ",file_name); 
      add_clr(line,sub_str);
      }
    }

fclose(fp);

free(sub_str);
free(file_name);
free(line);


}


else if(strcmp(option,"-o")==0){

char str1[MAX_Cmdln];
strcpy(str1,cmd);


   char *token;
   int i=1;
   char *sub_str = malloc(MAX_line_len);
   char *file_name = malloc(MAX_Cmdln);
   char *line = malloc(MAX_line_len);
   
   token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(sub_str,token);
    }
    
    if(i==4){
    strcpy(file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
 

FILE *fp;

fp = fopen(file_name,"r");
if (fp == NULL) {
        printf("Error: No such file or directory \n");
        return 1;
    }


 while (fgets(line,100, fp) != NULL) {
      if(strstr(line,sub_str)!=NULL){ 
      printf("%s\n",sub_str); 
      
      }
    }

fclose(fp);

free(sub_str);
free(file_name);
free(line);


}


else if(strcmp(option,"-c")==0){

char str1[MAX_Cmdln];
strcpy(str1,cmd);


   char *token;
   int i=1;
   char *sub_str = malloc(MAX_line_len);
   char *file_name = malloc(MAX_Cmdln);
   char *line = malloc(MAX_line_len);
   int count =0;
   
   token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(sub_str,token);
    }
    
    if(i==4){
    strcpy(file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
 

FILE *fp;

fp = fopen(file_name,"r");
if (fp == NULL) {
        printf("Error: No such file or directory \n");
        return 1;
    }


 while (fgets(line,100, fp) != NULL) {
      if(strstr(line,sub_str)!=NULL){ 
       count++;
      }
    }

printf("%d\n",count);
fclose(fp);

free(sub_str);
free(file_name);
free(line);


}



else{
printf("command not found\n");
}

}
