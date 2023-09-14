//Rraheem Was Here!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int number;
    pid_t child1, child2;

    printf("Please enter a number: ");
    scanf("%d", &number);

    printf("collatz %d\n", number);

    while(number != 1){
        if (number % 2 == 0) {
            //this is the first child process
            child1 = fork();
            if(child1 == 0) {
                printf("From Child1, pid=%d: number=%d is even\n", getpid(), number);
                exit(0);
            } else if (child1 < 0){
                printf("Child1 was not forked successfully. \n");
            }
            wait(NULL);
            number = number / 2;
        } else {
            //this is the second child process
            child2 = fork();
            if(child2 == 0) {
                printf("From Child2, pid=%d: number=%d is odd\n", getpid(), number);
                exit(0);
            } else if (child2 < 0){
                printf("Child2 was not forked successfully. \n");
            }
            wait(NULL);
            number = 3 * number + 1;
        }
        
    }
    printf("All my Children Complete\n");
    printf("Rraheem was here!");
    return 0;
}

    
