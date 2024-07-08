#include "my_header.h"


void fn_ls(char* command,char* option){

if(option==NULL){
    struct dirent *de;
    DIR *dr;
    int i=0;
    char arr[100][50];
    
    dr = opendir(".");
    if (dr == NULL) {
        printf("Error opening the directory\n");
        }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
        
          strcpy(arr[i],de->d_name);
           i++;
            
        }
    }
    
     int n=i;  
    
     sortStrings(arr, n);
       

   for(i = 0; i < n; i++) {
        printf("%s  ", arr[i]);
    }
    printf("\n");

    closedir(dr);
    
    }
    

else if(strcmp(option,"-1")==0){

    struct dirent *de;
    DIR *dr;
    int i=0;
    char arr[100][50];
    
    dr = opendir(".");
    if (dr == NULL) {
        printf("Error opening the directory\n");
        }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
        
          strcpy(arr[i],de->d_name);
           i++;
            
        }
    }
    
     int n=i;  
    
     sortStrings(arr, n);
       

   for(i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    

    closedir(dr);
    }
    
   else if(strcmp(option,"-Q")==0){
    struct dirent *de;
    DIR *dr;
    int i=0;
    char arr[100][50];
    
    dr = opendir(".");
    if (dr == NULL) {
        printf("Error opening the directory\n");
        }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
        
          strcpy(arr[i],de->d_name);
           i++;
            
        }
    }
    
     int n=i;  
    
     sortStrings(arr, n);
       

   for(i = 0; i < n; i++) {
        printf("\"%s\"  ", arr[i]);
    }
    printf("\n");

    closedir(dr);
    
    }
    
   else if(strcmp(option,"-l")==0){
   
    DIR *dr;
    int i=0;
    char arr[100][50];
    char buffer[80];
    
    struct dirent *de;
    struct passwd *pw;
    struct group  *gr;
    struct stat st; 
    
    dr = opendir(".");
    if (dr == NULL) {
        printf("Error opening the directory\n");
        }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
        
          strcpy(arr[i],de->d_name);
           i++;
            
        }
    }
    
     int n=i;  
    
     sortStrings(arr, n);
       
      for (int i = 0; i < n; i++) {
        if (stat(arr[i], &st) == -1) {
            printf("Error: Unable to get file information for %s\n", arr[i]);
        }
        else {
            
    printf((S_ISDIR(st.st_mode)) ? "d" : "-");
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf((st.st_mode & S_IRGRP) ? "r" : "-");
    printf((st.st_mode & S_IWGRP) ? "w" : "-");
    printf((st.st_mode & S_IXGRP) ? "x" : "-");
    printf((st.st_mode & S_IROTH) ? "r" : "-");
    printf((st.st_mode & S_IWOTH) ? "w" : "-");
    printf((st.st_mode & S_IXOTH) ? "x" : "-");
    
     printf(" %ld ", st.st_nlink);
     
        pw = getpwuid(st.st_uid);
        printf("%s ", pw->pw_name);
        gr = getgrgid(st.st_gid);
        printf("%s", gr->gr_name);
        printf("%8ld", st.st_size);
            
        strftime(buffer, 80, "%b %d %H:%M", localtime(&st.st_mtime));
        printf(" %s", buffer);
       
       printf(" %s", arr[i]);
        }
        
        printf("\n");
    }
  

    closedir(dr);
    
    
    }
    
    
    else if(strcmp(option,"-s")==0){
    
    struct dirent *de;
    struct stat st; 
    DIR *dr;
    int i=0;
    char arr[100][50];
    
    dr = opendir(".");
    if (dr == NULL) {
        printf("Error opening the directory\n");
        }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
        
          strcpy(arr[i],de->d_name);
           i++;
            
        }
    }
    
     int n=i;  
    
     sortStrings(arr, n);
       
    for (int i = 0; i < n; i++) {
        if (stat(arr[i], &st) == -1) {
            printf("Error: Unable to get file information for %s\n", arr[i]);
        }
        else {
        printf(" %ld  %s  ", st.st_blocks/2, arr[i]);
        }
   
        }
        
        printf("\n");
    closedir(dr);
    
    }
    
    else{
    printf("command not found \n");
    }
    

}


