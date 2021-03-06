#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include <unistd.h>
#include<string.h>

#define SIZE 1024

int main(){
    char file1[SIZE];
    char file2[SIZE];
    char input1[]="Hello world!";
    int inputLen =strlen(input1);
    int fp,fp2,i;
    int copyNum= inputLen - (inputLen-1);

    //creates file one
    printf("Please enter input file name: ");
    scanf("%s", file1);
    printf("\n");

    fp= open(file1, O_RDWR | O_EXCL| O_CREAT);  
    
    if (fp == -1){
        printf("Either an input file exist with same name, in this case change file name.\n");
        printf("Or an error occured creating a new input file.\n");
        printf("Please try again.\n");
        exit(0);
    }
    write(fp,input1,inputLen);

    //creates a file2
    printf("Please enter destination file name: ");
    scanf("%s", file2);
    printf("\n");
    
    fp2= open(file2, O_WRONLY | O_EXCL| O_CREAT);
    
    if (fp2 == -1){
        printf("Either an destination file exist with same name, in this case change file name.\n");
        printf("Or an error occured creating a new destination file.\n");
        printf("Please try again.\n");
        exit(0);
    }
 
    //copies file1 contents into file2
    for(i=0; i< copyNum;i++){
        read(fp,input1,inputLen);
        write(fp2,input1,inputLen);
    }

    printf("Contents in the input file was copied into the destination file! :)\n");
    printf("Goodbye.\n");
    
    close(fp);
    close(fp2);
    return 0;
}