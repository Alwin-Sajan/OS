#include <stdio.h>
#include <stdlib.h>
struct node
{
 int id,bursttime,waittime,turnaroundtime;
 struct node *next;
 }*head,*current;
 void addprocess(int i,int bt)
 {
struct node *new=(struct node *)malloc(sizeof(struct node));
new->id=i;
new->bursttime=bt;
current->next=new;
new->next=NULL;
current=new;
}
 void gantt()
 {
 int i=0;
 printf("process id\tburst time\tstarting time\tending time\t wait time\tturnaround time\n");
 current=head->next;
 while(current!=NULL)
 {
  printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",current->id,current->bursttime,i,(i+current->bursttime),current->waittime,current->turnaroundtime);
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
    printf("average turnaround time=%f\n",avggt);
    }
    void main()
    {
     int n,i,bt;
     head=(struct node *)malloc(sizeof(struct node));
     current=head;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
      printf("enter the burst time for process %d\n",(i+1));
      scanf("%d",&bt);
      addprocess(i,bt);
      }
      calcwaitturntime();
      gantt();
      avg(n);
}