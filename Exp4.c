#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
void main()
{
int id;
int *p,val;
char *arr[100];
key_t key=ftok("hel.c",45);
id=shmget(key,50,IPC_CREAT|0777);
if(id<0){
printf("ERROR\N");
}
else{
printf("Shared memory segment id:%d\n",id);
}
if((p=shmat(id,0,0))<0){
printf("ERROR\n");}
else{
printf("Starting address:%d\n",p);
printf("Enter a string\n");
scanf("%s",arr);
strncpy(p,arr,sizeof(arr));
printf("Content:%s\n",p);
}
if((val=shmdt(p))<0){
printf("ERROR\n");
}
else{
printf("Shared memory detatched\n");
}
}