#include<stdio.h>
#include<stdlib.h>
struct node
{
int id,bursttime,waittime,turnaroundtime,priority;
struct node*next;
}*head,*current;
void addprocess(int i,int bt,int pri)
{
struct node*new=(struct node*)malloc(sizeof(struct node));
new->id=i;
new->bursttime=bt;
new->priority=pri;
current->next=new;
new->next=NULL;
current=new;
}
void gantt()
{
int i=0;
printf("process-id\tpriority\tburst-time\tstarting-time\tending-time\twait-time\tturn-around-time\n");
current=head->next;
while(current!=NULL)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",current->id,current->priority,current->bursttime,i,(i+current->bursttime),current->waittime,current->turnaroundtime);
i=i+current->bursttime;
current=current->next;
}
}
void calcwaitturntime()
{
(head->next)->waittime=0;
(head->next)->turnaroundtime=(head->next)->bursttime;
current=head->next;
while(current->next!=NULL)
{
(current->next)->waittime=current->waittime+current->bursttime;
(current->next)->turnaroundtime=(current->next)->waittime+(current->next)->bursttime;
current=current->next;
}
}
void sort()
{
int i,burst,prior;
current=head->next;
while(current)
{
struct node *min=current;
struct node *r=current->next;
while(r){
if(min->priority>r->priority)
{
min=r;
}
r=r->next;
}
i=current->id;
burst=current->bursttime;
prior=current->priority;
current->id=min->id;
current->bursttime=min->bursttime;
current->priority=min->priority;
min->id=i;
min->bursttime=burst;
min->priority=prior;
current=current->next;
}
}
void avg(int n)
{
float avgw=0;
float avgt=0;
float avggw,avggt;
current=head->next;
while(current!=NULL)
{
avgw=avgw+current->waittime;
avgt=avgt+current->turnaroundtime;
current=current->next;
}
avggw=avgw/n;
avggt=avgt/n;
printf("average waiting time=%f\n",avggw);
printf("average turnaroundtime=%f\n",avggt);
}
void main()
{
int n,i,bt,pri;
head=(struct node*)malloc(sizeof(struct node));
current=head;
printf("Enter the number of processes\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the burst time for process %d\n",i);
scanf("%d",&bt);
printf("Enter the priority for process %d\n",i);
scanf("%d",&pri);
addprocess(i,bt,pri);
}
sort();
calcwaitturntime();
gantt();
avg(n);
}