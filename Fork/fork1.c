#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
 pid_t chpid, child1, child2,chpid1, chpid2;
 int ii, stat;

 printf("I am a process my process id is %d\n",getpid());
 printf("I am creating two child process & make them run some code\n");

 child1 = fork();
 if(child1 == 0)
 {
  printf("I am first child, my pid is %d\n",getpid());
  printf("I am tired, sleeping for 5 seconds\n");
  sleep(5);
  exit(0);
 }
 child2=fork();
 if(child2== 0)
 {
  printf("I am second child, my pid is %d\n",getpid());
  printf("I am tired, sleeping for 10 seconds\n");
  sleep(10);
  exit(0);
 }
 printf("I am parent, my children are working & sleeping, I wait for them\n");
 chpid2 = waitpid(child2, &stat, 0);

  printf("my second children terminated with status %d\n", WEXITSTATUS(stat));

  printf("Terminated child2 pid from wait = %d\n", chpid2);

 chpid1 = waitpid(child1, &stat, 0);


  printf("my first children terminated with status %d\n", WEXITSTATUS(stat));

                printf("Terminated child1 pid from wait = %d\n", chpid1);

 printf("Both children got terminated, now i will do the same\n");
}
