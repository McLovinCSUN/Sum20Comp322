#include<stdio.h>
#include<stdlib.h>
//#include<string.h>


int main(){
    char fileName[100];
    char file2[100]="copyFile";
    char copy,c;

    printf("Please enter file name: ");
    scanf("%s", fileName);

    FILE *fp= fopen(fileName, "r" ); //creates file one
    
    if (fp == NULL){
        printf("error.\n");
        exit (0);
    }

    fprintf(fp, "This is what is inside file one.\n"); //input something random into file one 
    
    FILE *fp2= fopen(file2, "w" ); //creates a file
    
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
    fprintf(fp2, "File one copied into file two.\n");//write into file two
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