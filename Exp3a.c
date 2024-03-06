#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
pid_t p;
printf("Process ID :%d\n",getpid());
printf("Parent process ID : %d\n\n",getppid());
p = fork();
if(p==-1){
printf("ERROR\n");
}
else if(p==0){
printf("CHILD PROCESS\n");
printf("Process ID : %d\n",getpid());
printf("Parent process ID: %d\n\n ",getppid());
}
else if(p>0){
printf("PARENT PROCESS\n");
printf("Process ID : %d\n",getpid());
printf("Parent process ID : %d\n\n",getppid());
}
}