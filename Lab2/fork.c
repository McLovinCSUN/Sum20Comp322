#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int i;
    int counter = 0;
    //convert string type to int using the atoi function
    int j = atoi(argv[1]);

    //fork is creating a new process by copying the calling process (parent)
    //at the time of fork() both memory spaces have the same content.
    pid_t child = fork();
    //after the fork, operations performed by the processes do not effect one another

    //this loop will execute however number of times inputed by user
    if(child == 0){
        for(i = 0; i < j; i++){
            //if the the child process is less than zero the parent was not able to create a child process
            //then it exits 
            if (child < 0){
                printf("Error.");
                exit (0);
            }else{
                //if the parent successed in creating a child process, the child PID is returned to the parent
                //and the child get back a zero. that is how you know it is a child process.
                counter= i+1;
                printf("Hello World from child %d\n", counter);   
            }
        }
    }else{
        //the parent is going to wait till child process j terminates
        waitpid(child,&j,0);
        printf("Parent processor of is done!\n");
    }
    return (0);
}

//tips from professor 
// if the parent can print an statement at the end it would be great 
// This parent should be good to its children and wait() for all of them to finish executing. 
// I can accept it, however it is better to print only ONE statement  
// currently it shows that the parent waits for all the childeren
// which is sufficient for this requirement : This parent should be good to its children and wait() for all of them to finish executing. 
