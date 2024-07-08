#include "my_header.h"


int fn_mv(char* cmd,char *option){
     
         
     if(option[0]!='-'){

      char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);;
   char *dest_file_name = malloc(MAX_Cmdln);; 
    
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==2){
    strcpy(src_file_name,token);
    }
    
    if(i==3){
    strcpy(dest_file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
  
  // get the file name from the source path and store it in str2[]
  char* str2 ;
  str2 = basename(src_file_name);
  
  //checking wheather source path and destination path are directories or not
  struct stat st1;
  struct stat st2;
  
  
  if(stat(src_file_name, &st1)==-1){
  printf("source file not found\n");
  return 1;
  }
  
  if (S_ISDIR(st1.st_mode)){
  printf("cp: -r not specified; omitting directory '%s'\n",src_file_name);
  return 1;
  }
  
  
  if(stat(dest_file_name, &st2)!=-1){ 
    
  // if it is a directory, create the path for the destination file.
  if (S_ISDIR(st2.st_mode)) {
  
  strcat(dest_file_name,"/");
  strcat(dest_file_name,str2);
  }
  }
  
  
   
  // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    
    }
    
    else if(strcmp(option,"-v")==0){
    
    char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);;
   char *dest_file_name = malloc(MAX_Cmdln);; 
    
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(src_file_name,token);
    }
    
    if(i==4){
    strcpy(dest_file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
  
  // get the file name from the source path and store it in str2[]
  char* str2 ;
  str2 = basename(src_file_name);
  
  
  //checking wheather source path and destination path are directories or not
  struct stat st1;
  struct stat st2;
  
  
  if(stat(src_file_name, &st1)==-1){
  printf("source file not found\n");
  return 1;
  }
  
  if (S_ISDIR(st1.st_mode)){
  printf("cp: -r not specified; omitting directory '%s'\n",src_file_name);
  return 1;
  }
  
  
  if(stat(dest_file_name, &st2)!=-1){ 
    
  // if it is a directory, create the path for the destination file.
  if (S_ISDIR(st2.st_mode)) {
  
  strcat(dest_file_name,"/");
  strcat(dest_file_name,str2);
  }
  }
  
  
   
  // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

     char dir[100];
     char* str3;
     str3 = basename(dest_file_name) ;
    
    strcpy(dir,dirname(dest_file_name));
    
    printf("moved '%s' -> '%s/%s'\n",src_file_name,dir,str3);

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    
    
    }
    
    
    else if(strcmp(option,"-i")==0){
    
    char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);;
   char *dest_file_name = malloc(MAX_Cmdln);; 
    
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(src_file_name,token);
    }
    
    if(i==4){
    strcpy(dest_file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
  
  // get the file name from the source path and store it in str2[]
  char* str2 ;
  str2 = basename(src_file_name);
  
  //checking wheather source path and destination path are directories or not
  struct stat st1;
  struct stat st2;
  
  
  if(stat(src_file_name, &st1)==-1){
  printf("source file not found\n");
  return 1;
  }
  
  if (S_ISDIR(st1.st_mode)){
  printf("cp: -r not specified; omitting directory '%s'\n",src_file_name);
  return 1;
  }
  
  
  if(stat(dest_file_name, &st2)!=-1){ 
    
  // if it is a directory, create the path for the destination file.
  if (S_ISDIR(st2.st_mode)) {
  
  strcat(dest_file_name,"/");
  strcat(dest_file_name,str2);
  }
  }
  
  
  char reply='x' ;
  
  if(stat(dest_file_name, &st2)!=-1){
  
  str2 = basename(dest_file_name);
  printf("There is an existing file with name '%s'. Do you want to overwrite it ?(y/n) : ",str2);
  scanf(" %c",&reply);
  
  if(reply=='y'){
  
  // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    
    
    }
  
  
  
  else if(reply =='n'){
   printf("file not be moved to destination .....\n");
   return 1;
   }
   
  else{ 
  printf("sorry ! input cannot be other than (y/n)\nfile not be moved to destination .....\n");
  return 1;
  }
  
  }
  
  else{
       // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    }

    
    }
    
    
    else if(strcmp(option,"-f")==0){
    
      char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);;
   char *dest_file_name = malloc(MAX_Cmdln);; 
    
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==2){
    strcpy(src_file_name,token);
    }
    
    if(i==3){
    strcpy(dest_file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
  
  // get the file name from the source path and store it in str2[]
  char* str2 ;
  str2 = basename(src_file_name);
  
  //checking wheather source path and destination path are directories or not
  struct stat st1;
  struct stat st2;
  
  
  if(stat(src_file_name, &st1)==-1){
  printf("source file not found\n");
  return 1;
  }
  
  if (S_ISDIR(st1.st_mode)){
  printf("cp: -r not specified; omitting directory '%s'\n",src_file_name);
  return 1;
  }
  
  
  if(stat(dest_file_name, &st2)!=-1){ 
    
  // if it is a directory, create the path for the destination file.
  if (S_ISDIR(st2.st_mode)) {
  
  strcat(dest_file_name,"/");
  strcat(dest_file_name,str2);
  }
  }
  
  
   
  // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    
    }
    
    else if(strcmp(option,"-n")==0){
    
    char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);;
   char *dest_file_name = malloc(MAX_Cmdln);; 
    
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
    
    if(i==3){
    strcpy(src_file_name,token);
    }
    
    if(i==4){
    strcpy(dest_file_name,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }
  
  
  // get the file name from the source path and store it in str2[]
  char* str2 ;
  str2 = basename(src_file_name);
  
  //checking wheather source path and destination path are directories or not
  struct stat st1;
  struct stat st2;
  
  
  if(stat(src_file_name, &st1)==-1){
  printf("source file not found\n");
  return 1;
  }
  
  if (S_ISDIR(st1.st_mode)){
  printf("cp: -r not specified; omitting directory '%s'\n",src_file_name);
  return 1;
  }
  
  
  if(stat(dest_file_name, &st2)!=-1){ 
    
  // if it is a directory, create the path for the destination file.
  if (S_ISDIR(st2.st_mode)) {
  
  strcat(dest_file_name,"/");
  strcat(dest_file_name,str2);
  }
  }
  
  
  
  
  if(stat(dest_file_name, &st2)!=-1){
  
  str2 = basename(dest_file_name);
  printf("There is an existing file with name '%s'.file cannot be overwritten..\n",str2);
  return 1;
  }
  
  else{
       // copying the source file to the destination file.
   FILE *src_file, *dest_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        return 1;
    }

    while (fgets(string,MAX_Cmdln, src_file) != NULL) {
        fputs(string, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    remove(src_file_name);
    
    free(src_file_name);
    free(dest_file_name);
    }

    
    
    }
    
    
    else{
    printf("command not found\n");
    }
    
}

