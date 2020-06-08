#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int i,child;
    int counter = 0;
    //convert string type to int using the atoi function
    int j = atoi(argv[1]);

    //this loop will execute however number of times inputed by user
    for(i = 0; i < j; i++){
        //creates a new child and copies all the information below
        child = fork();
        if (child < 0){
            printf("Error.");
            exit (0);
        }
        //the first time child is forked it will have a pid # != 0 but once it finishes
        //it then = to 0 going into this if statement
        if(child == 0){
            counter= i+1;
            printf("Hello World from child %d\n", counter);   
        }else{
            //the parent process is going to wait till we reach j number of times before 
            //terminating itself
            wait(&j);
        }
    }

  return (0);
}