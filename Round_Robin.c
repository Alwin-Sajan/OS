#include<stdio.h>
int q[100];
int front=-1;
int rear=-1;
struct process
{
 int id;
 int bt;
 int rt;
 int tat;
 int wt;
}a[10];
void insert(int m)
{
 if((front==-1)&&(rear==-1))
 {
  front=0;
  rear=rear+1;
  q[rear]=m;
 }
 else
 {
  rear=rear+1;
  q[rear]=m;
 }
}
int delete()
{
 int m;
 m=q[front];
 front=front+1;
 return m;
}
int main()
{
 int n,i,qu,j,p,t=0;
 float avgwt=0,avgtat=0;
 printf("enter the number of processor\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("enter burst time for process %d\n",i);
  scanf("%d",&a[i].bt);
  a[i].id=i;
  a[i].rt=a[i].bt;
  a[i].tat=0;
  insert(i);
 }
 printf("enter the time quantum\n");
 scanf("%d",&qu);
 printf("Gantt Chart\n");
 while(front<=rear)
 {
  p=delete();
  printf("%d\t",p);
  if(a[p].rt<=qu)
  {
   a[p].tat=t+a[p].rt;
   t=t+a[p].rt;
   a[p].rt=0;
  }
  else
  {
   a[p].rt=a[p].rt-qu;
   t=t+qu;
  }
  if(a[p].rt>0)
  {
   insert(p);
  }
 }
 printf("\nprocess\t\tburst-time\t\tturn-around time\twaiting time\n");
 for(i=1;i<=n;i++)
 {
  a[i].wt=a[i].tat-a[i].bt;
  printf("%d\t\t\t%d\t\t%d\t\t\t%d\n",a[i].id,a[i].bt,a[i].tat,a[i].wt);
  avgwt=avgwt+a[i].wt;
  avgtat=avgtat+a[i].tat;
 }
 printf("average turn-around-time=%f\n",avgtat/n);
 printf("average waiting time=%f\n",avgwt/n);
}