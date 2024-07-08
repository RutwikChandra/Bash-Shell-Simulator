#include "my_header.h"


int fn_cp(char* cmd,char *option){
     
         
     if(option[0]!='-'){

      char str1[MAX_Cmdln];
       strcpy(str1, cmd);
   
   // parsing the command (separating directories)  
   char *token;
   int i=1;
   
   char *src_file_name = malloc(MAX_Cmdln);
   char *dest_file_name = malloc(MAX_Cmdln); 
    
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
    
    printf("'%s' -> '%s/%s'\n",src_file_name,dir,str3);

    fclose(src_file);
    fclose(dest_file);
    
    
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
    
    
    free(src_file_name);
    free(dest_file_name);
    
    
    }
  
  
  
  else if(reply =='n'){
   printf("file not copied to destination .....\n");
   return 1;
   }
   
  else{ 
  printf("sorry ! input cannot be other than (y/n)\nfile not copied to destination .....\n");
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
    
    
    free(src_file_name);
    free(dest_file_name);
    }

    
    }
    
    
    else if(strcmp(option,"-l")==0){
    
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
   FILE *src_file, *dest_file, *temp_file;
   
    char string[MAX_Cmdln];
    
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        printf("source file not found\n");
        return 1;
    }

     temp_file = fopen("temp", "w");
     while(fgets(string,MAX_Cmdln, src_file)!=NULL){
      fputs(string, temp_file);
     }
     
     fclose(temp_file);

    if (link(src_file_name, dest_file_name) == -1) {
        printf("Error creating hard link\n");
        remove("temp");
        return 1;
    }

    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Failed to create destination file\n");
        fclose(src_file);
        remove("temp");
        return 1;
    }
    
    temp_file = fopen("temp", "r");
    
     while(fgets(string,MAX_Cmdln, temp_file)!=NULL){
      fputs(string, dest_file);
     }
     
    fclose(temp_file); 
    remove("temp");

    fclose(src_file);
    fclose(dest_file);
   
    
    free(src_file_name);
    free(dest_file_name);
    
    
    
    }
    
    else if(strcmp(option,"-T")==0){
    
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
  
  printf("cannot overwrite directory with non-direcory \n");
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
    
    
    free(src_file_name);
    free(dest_file_name);
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
    
    
    free(src_file_name);
    free(dest_file_name);
    }

    
    
    }
    
    
    else{
    printf("command not found\n");
    }
    
}

