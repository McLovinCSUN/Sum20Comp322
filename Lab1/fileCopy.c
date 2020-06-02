#include<stdio.h>
#include<stdlib.h>

int main(){
    char fileName[100];
    char copy,c;

    printf("Please enter file name: ");
    scanf("%s", fileName);

    //creates file one
    FILE *fp= fopen(fileName, "r" ); 
    
    if (fp == NULL){
        printf("error.\n");
        exit (0);
    }

    //input something random into file one 
    fprintf(fp, "This is what is inside file one.\n"); 
    
    //creates a file
    FILE *fp2= fopen("file2", "w" ); 
    
    if (fp2 == NULL){
        printf("error.\n");
        exit (0);
    }

    //read from file one and copy its contents into to file 2
    copy = fgetc(fp);
    while (copy !=EOF){
        fputc(copy,fp2);
        copy = fgetc(fp);
    }

    //write into file two
    fprintf(fp2, "File one copied into file two.\n");

    fclose(fp);
    fclose(fp2);

    //reads what is inside file two
    fp2 = fopen("copyFile", "r+");
    while ((c = getc(fp2)) != EOF) {
        printf("%c", c);
     }
     fclose(fp2);

     return 0;
}