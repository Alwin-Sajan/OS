#include<stdio.h>
#include<stdlib.h>
void recurse(int files[])
{
    int flag=0,sb,len,j,k,ch;
    printf("enter the starting block and the length of the files:");
    scanf("%d%d",&sb,&len);
    for(j=sb;j<(sb+len);j++)
    {
        if(files[j]==0)
        {
            flag++;
        }
    }
    if(len==flag)
    {
        for(k=sb;k<(sb+len);k++)
        {
            if(files[k]==0)
            {
                files[k]=1;
                printf("%d\t%d\n",k,files[k]);
            }
        }
        if(k!=(sb+len-1))
        {
            printf("the file is allocated in the disk\n");
        }
    }
    else
    {
        printf("the file is not allocated to the disk\n");
       
    }
     printf("do you want to enter more files?\n");
        printf("press 1 for YES ,0 for NO");
        scanf("%d",&ch);
        if(ch==1)
        {
            recurse(files);
        }
        else
        {
            exit(0);
        }
        return;
}
int main()
{
    int files[50];
    for(int i=0;i<50;i++)
    {
        files[i]=0;
    }
    printf("Files allocated are:\n");
    recurse(files);
    return 0;
}
