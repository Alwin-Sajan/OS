#include<stdio.h>
#include<stdlib.h>
int files[90],indbik[90],ind,n;
void recurse1();
void recurse2();
void recurse1()
{
    printf("enter the index block\t");
    scanf("%d",&ind);
    if(files[ind]!=1)
    {
        printf("enter the number of blocks and the number of files needed for the index %d on the disk ",ind);
        scanf("%d",&n);
    }
    else
    {
        printf("%d is already allocated \n",ind);
        recurse1();
    }
    recurse2();
}
void recurse2()
{
    int ch;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&indbik[i]);
        if(files[indbik[i]]==0)
        {
            flag++;
        }
    }
    if(flag==n)
    {
        for(int j=0;j<n;j++)
        {
            files[indbik[j]]=1;
        }
        printf("allocated\n");
        printf("file indexed\n");
        for(int k=0;k<n;k++)
        {
            printf("%d-->%d:%d\n",ind,indbik[k],files[indbik[k]]);
        }
    }
    else
    {
        printf("file in the index is already allocated\n");
        printf("enter another indexed file\n");
        recurse2();
    }
    printf("do you want to enter more files?\n");
    printf("enter 1 for YES,enter 0 for NO\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        recurse1();
    }
    else
    {
        exit(0);
    }
    return;
}
int main()
{
    for(int i=0;i<50;i++)
    {
        files[i]=0;
    }
    recurse1();
    return 0;
}
