#include "my_header.h"


int fn_ps(char* cmd,char* option){

if(option==NULL){


DIR *dir;
    struct dirent *ent;
    char path[PATH_MAX];
    char pid[PATH_MAX];
    char command[PATH_MAX];
    char tty[PATH_MAX];
    char time[PATH_MAX];
    FILE *fp;

    printf("%-5s %-12s %-7s %s\n", "PID", "TTY", "TIME", "COMMAND");

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir error");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            int i;
            for (i = 0; ent->d_name[i]; i++) {
                if (!isdigit(ent->d_name[i])) {
                    break;
                }
            }

            if (ent->d_name[i] == '\0') {
                snprintf(path, PATH_MAX, "/proc/%s/comm", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fgets(command, PATH_MAX, fp);
                fclose(fp);
                command[strcspn(command, "\n")] = '\0';

                snprintf(path, PATH_MAX, "/proc/%s/stat", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fscanf(fp, "%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %s", pid, tty, time);
                fclose(fp);
if(strcmp(command,"bash")==0){
                printf("%-5s %-12s %-7s %s\n", pid, tty, time, command);
                }
                 if(strcmp(command,"out.o")==0){
                printf("%-5s %-12s %-7s %s\n", pid, tty, time, "out.o");
                }
                
            }
        }
    }

    closedir(dir);





}

else if(strcmp(option,"-e")==0){

DIR *dir;
    struct dirent *ent;
    char path[PATH_MAX];
    char pid[PATH_MAX];
    char command[PATH_MAX];
    char tty[PATH_MAX];
    char time[PATH_MAX];
    FILE *fp;

    printf("%-5s %-12s %-7s %s\n", "PID", "TTY", "TIME", "COMMAND");

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir error");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            int i;
            for (i = 0; ent->d_name[i]; i++) {
                if (!isdigit(ent->d_name[i])) {
                    break;
                }
            }

            if (ent->d_name[i] == '\0') {
                snprintf(path, PATH_MAX, "/proc/%s/comm", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fgets(command, PATH_MAX, fp);
                fclose(fp);
                command[strcspn(command, "\n")] = '\0';

                snprintf(path, PATH_MAX, "/proc/%s/stat", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fscanf(fp, "%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %s", pid, tty, time);
                fclose(fp);

                printf("%-5s %-12s %-7s %s\n", pid, tty, time, command);
            }
        }
    }

    closedir(dir);


}

else if(strcmp(option,"-A")==0){

DIR *dir;
    struct dirent *ent;
    char path[PATH_MAX];
    char pid[PATH_MAX];
    char command[PATH_MAX];
    char tty[PATH_MAX];
    char time[PATH_MAX];
    FILE *fp;

    printf("%-5s %-12s %-7s %s\n", "PID", "TTY", "TIME", "COMMAND");

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir error");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            int i;
            for (i = 0; ent->d_name[i]; i++) {
                if (!isdigit(ent->d_name[i])) {
                    break;
                }
            }

            if (ent->d_name[i] == '\0') {
                snprintf(path, PATH_MAX, "/proc/%s/comm", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fgets(command, PATH_MAX, fp);
                fclose(fp);
                command[strcspn(command, "\n")] = '\0';

                snprintf(path, PATH_MAX, "/proc/%s/stat", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fscanf(fp, "%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %s", pid, tty, time);
                fclose(fp);

                printf("%-5s %-12s %-7s %s\n", pid, tty, time, command);
            }
        }
    }

    closedir(dir);


}


else if(strcmp(option,"-p")==0){

 char str1[MAX_Cmdln];
       strcpy(str1, cmd);
 char *token;
   int i=1;
  char pr_id[10] ; 
      
  token = strtok(str1, " ");

  if (token == NULL) {
    puts("empty string!");
    
  }

  while (token) {
   
    
    if(i==3){
    strcpy(pr_id,token);
    }
    
    token = strtok(NULL, " ");
    i++;
  }

DIR *dir;
    struct dirent *ent;
    char path[PATH_MAX];
    char pid[PATH_MAX];
    char command[PATH_MAX];
    char tty[PATH_MAX];
    char time[PATH_MAX];
    FILE *fp;

    printf("%-5s %-12s %-7s %s\n", "PID", "TTY", "TIME", "COMMAND");

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir error");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            int i;
            for (i = 0; ent->d_name[i]; i++) {
                if (!isdigit(ent->d_name[i])) {
                    break;
                }
            }

            if (ent->d_name[i] == '\0') {
                snprintf(path, PATH_MAX, "/proc/%s/comm", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fgets(command, PATH_MAX, fp);
                fclose(fp);
                command[strcspn(command, "\n")] = '\0';

                snprintf(path, PATH_MAX, "/proc/%s/stat", ent->d_name);

                if ((fp = fopen(path, "r")) == NULL) {
                    perror("fopen error");
                    exit(EXIT_FAILURE);
                }

                fscanf(fp, "%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %s", pid, tty, time);
                fclose(fp);
if(strcmp(pid,pr_id)==0){
                printf("%-5s %-12s %-7s %s\n", pid, tty, time, command);
                }
            }
        }
    }

    closedir(dir);


}

else{
printf("command not found\n");

}


}
