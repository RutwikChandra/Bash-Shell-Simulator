#include "my_header.h"

void sortStrings(char arr[][50], int n) {
    int i, j,k ;
    char temp[50];   
    
    for(i = 0; i < n; i++){
    if(isupper(arr[i][0])){
    arr[i][0]=tolower( arr[i][0]);
    k=strlen(arr[i]);
    arr[i][k]='1';
    arr[i][k+1]='\0';
    }
    else{
    k=strlen(arr[i]);
    arr[i][k]='0';
    arr[i][k+1]='\0';
    }
    } 
    
    // bubble sort algorithm
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    
    for(i=0;i <n;i++){
    k=strlen(arr[i]);
    if(arr[i][k-1]=='1'){
    arr[i][0]=toupper(arr[i][0]);
    arr[i][k-1]='\0';
    }
    else{
     arr[i][k-1]='\0';
    }
    }
}
