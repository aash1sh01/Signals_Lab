//Modified the code as per the feedback
/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

int count = 0;
int time = 0;
bool flag = false;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  flag = true; //exit after printing
}
void sigintHandler(int sig_num)
{
  printf("\n %d no of alarms occured for %d seconds.\n", count,time);
  exit(1);
}
int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigintHandler);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    if (check){
      printf("Turing was right!\n");
      check = false;
      alarm(1);
      count ++;
      sec ++;
    }
  }
    
    //busy wait for signal to be delivered
  
  return 0; //never reached
}