#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
void main(){
DIR *dirp;
struct dirent *dp;
if((dirp=opendir("/home/student/Alwin"))==NULL){
printf("NO FOLDER EXISTS\n");
exit(1);
}
for(dp=readdir(dirp);dp!=NULL;dp=readdir(dirp)){
if(dp->d_type==DT_REG){
printf("%s\n",dp->d_name);
}
}
closedir(dirp);
}