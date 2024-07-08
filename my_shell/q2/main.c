#include "my_header.h"

int main(){

char* cmd;
    char cwd[MAX_Cmdln];
    char *delimiter = " ";
    char *command, *option;
    char prompt[MAX_Cmdln];
    
while(1){

 // Set the command prompt
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    char color[10] = "\x1b[32m"; // Set the color to green
    strcpy(prompt, color);
    strcat(prompt, getenv("USER"));
    strcat(prompt, ":");
    strcat(prompt, cwd);
    strcat(prompt, "$\x1b[0m "); // Reset the color to default and add a space
} else {
    perror("getcwd() error");
}

// Read the user input
cmd = readline(prompt);


 // Parse the user input
        char str[MAX_Cmdln];
        strcpy(str, cmd);
        command = strtok(str, delimiter);
        option = strtok(NULL, delimiter);


 // Add the command to history
        add_history(cmd);

   if (strcmp(cmd, "") == 0) {
  continue ;
  free(cmd);
 }

 // Exit the shell if the user enters 'exit'
        if(strcmp(command, "exit") == 0) {
            printf("exiting myshell.....\n");
            free(cmd);
            break;
        }
   
 //to change directory      
        else if(strcmp(command, "cd") == 0) {
            chdir(option);
        }

 //command ls
       else if(strcmp(command,"ls")==0){ 
          fn_ls(command,option);
       }
       
       
 //command cp      
       else if( strcmp(cmd,"cp")==0){
       printf("cp: missing file operand\n");
       continue;
       }
       
       else if(strcmp(command,"cp")==0){
          fn_cp(cmd,option);
       }
       
       
 //command mv     
       else if( strcmp(cmd,"mv")==0){
       printf("mv: missing file operand\n");
       continue;
       }
       
       else if(strcmp(command,"mv")==0){
          fn_mv(cmd,option);
       }
       
       
 //command grep      
       else if(strcmp(command,"grep")==0){
          fn_grep(cmd,option);
       }
       
 //command ps     
       else if(strcmp(command,"ps")==0){
          fn_ps(cmd,option);
       }
      
 //if user enter any other commands      
       else{
        printf("command not found \n");
       }
       
 //free command
   free(cmd);
}

return 0;
}
