#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char fileName[100];
   
    char c;

    printf("Please enter file name: ");
    scanf("%s", fileName);

    FILE *fp= fopen(fileName, "w" );
    
    if (fp == NULL){
        printf("error.\n");
        exit (0);
    }

    fprintf(fp, "eat my ass i logged something\n");
    fclose(fp);
    
    //reading
    fp = fopen(fileName, "r+");
    while ((c = getc(fp)) != EOF) {
        printf("%c", c);
     }
     fclose(fp);

     return 0;

}