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
        //fork is creating a new process by copying the calling process (parent)
        //at the time of fork() both memory spaces have the same content.
        child = fork();
        //after the fork, operations performed by the processes do not effect one another

        //if the the child process is less than zero the parent was not able to create a child process
        //then it exits 
        if (child < 0){
            printf("Error.");
            exit (0);
        }

        //if the parent successed in creating a child process, the child PID is returned to the parent
        //and the child get back a zero. that is how you know it is a child process. 
        if(child == 0){
            counter= i+1;
            printf("Hello World from child %d\n", counter);   
        }else{
            //the parent is going to wait till child process j terminates 
            wait(&j);
        }
    }

  return (0);
}