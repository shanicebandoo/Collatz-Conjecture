/** Name: Shanice Bandoo
 * Panther ID: 6309619
 * Description: This program is responsible for carrying out the collatz sequence
 *              while utilizing two fork() functions. If the number is odd, the next number in the sequence
 *              would be 3n+1. If even, the next number would be n/2. The calculations of the sequence will continue 
 *              until the number 1 is achieved. The fork() functions are used to create a new process from an existing one.
 * Task 2: 
 */
 

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
printf("This is the Parent waiting!\n");

//this is the first child process
child1 = fork();
if(child1 == 0) {
    printf("From Child1, pid=%d: number=%d\n", getpid(), number);
    
    while(number != 1){
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = 3 * number + 1;
        }
        printf("From Child1: number=%d\n", number);
    }
    printf("From Child1, pid=%d: I'm done!\n", getpid());
} else if (child1 < 0){
    printf("Child1 was not forked successfully. \n");
}
wait(NULL);


//this is the second child process
child2 = fork();
if(child2 == 0) {
    printf("From Child2, pid=%d: number=%d\n", getpid(), number);
    
    while(number != 1){
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = 3 * number + 1;
        }
        printf("From Child2: number=%d\n", number);
    }
    printf("From Child2, pid=%d: I'm done!\n", getpid());
} else if (child2 < 0){
    printf("Child2 was not forked successfully. \n");
}
wait(NULL);

printf("All my Children Complete\n");

return 0;
}