#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_Cmdln 1024

int main() {
    char* cmd;
    char cwd[MAX_Cmdln];
    char *delimiter = " ";
    char *command, *directory;
    char prompt[MAX_Cmdln];

    while(1) {
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
        // If the user input is empty, prompt the user again
        if (strcmp(cmd, "") != 0) {
            
            
        // Parse the user input
        char str[MAX_Cmdln];
        strcpy(str, cmd);
        command = strtok(str, delimiter);
        directory = strtok(NULL, delimiter);

        // Exit the shell if the user enters 'exit'
        if(strcmp(command, "exit") == 0) {
            printf("exiting myshell.....\n");
            free(cmd);
            break;
        }

        // Add the command to history
        add_history(cmd);

        // Execute the command
        if(strcmp(command, "cd") == 0) {
            chdir(directory);
        }
        
        else if(strcmp(command,"help")==0){
        system("bash -c help");
        }
        
         else {
            system(cmd);
        }

        // Free the memory allocated for the input command
        free(cmd);
        
        }
        else{
        free(cmd);
        }
    }

    return 0;
}

