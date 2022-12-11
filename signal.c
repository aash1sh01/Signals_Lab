/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

bool flag = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  flag = true;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){ //busy wait for signal to be delivered
     if (flag){
       printf("Turing was right!\n");
       flag=false;
       alarm(1);
     }
  }
  
  return 0; //never reached
}