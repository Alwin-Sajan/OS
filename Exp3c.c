#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
main(int argc , char *argv[]){
pid_t pid;
int i;
if(argc!= 3){
printf("Insufficent arguments\n./a.out<path><cmd>\n");
exit(-1);
}
pid = fork();
switch(pid)
{
case -1:
printf("Fork failed-Error\n");
case 0:
printf("child process\n");
i=execl(argv[1],argv[2],0);
if(i<0){
printf("%s program not loaded using exec system\n",argv[2]);
exit(-1);
}

default:
wait(NULL);
printf("Child terminated\n");
}
}