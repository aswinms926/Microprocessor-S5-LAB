#include <stdio.h>
// d = distance and td = total_distance 
void main()
{
   int head,size,n,a[30],dir,i,temp,d=0,td=0,visited[20]={0},j;
   printf("EnTer the head position : ");
   scanf("%d",&head);
   
   printf("EnTer the max disk size : ");
   scanf("%d",&size);
   size=size-1;
   
   printf("EnTer the number of disk req : ");
   scanf("%d",&n);
   
   printf("EnTer the disk req : ");
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
   
   printf("enter the direction of head (0: L to R or 1 : R to L) : ");
   scanf("%d",&dir);
   
   for(i=0;i<n;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if(a[j]>a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
   if(!dir)
   {
   for(i=0;i<n;i++)
   {
   if(a[i]>head)
   {
       d=a[i]-head;
       printf("head movement from %d tp %d : %d\n",head,a[i],d);
       td+=d;
       head =a[i];
       visited[i]=1;
   }
   }
   if(size > head)
   {
       d=size-head;
              printf("head movement from %d tp %d : %d\n",head,size,d);
              td+=d;
              head=size;
   }
   d=size-0;
                 printf("head movement from %d tp 0 : %d\n",head,d);
                 td+=d;
                 head=0;


   for(i=0;i<n;i++)
   {
       if(head <a[i] && !visited[i])
       {
           d=a[i]-head;
                         printf("head movement from %d tp %d : %d\n",head,a[i],d);
                         td+=d;
                         head=a[i];

       }
   }

   }
   else
   {
       for(i=n-1;i>=0;i--)
   {
       if(head >a[i])
       {
           d=head-a[i];
                         printf("head movement from %d tp %d : %d\n",head,a[i],d);
                         td+=d;
                         head=a[i];
                        visited[i]=1;
       }
   }
   if(head >0)
   {
       d=head-0;
                                printf("head movement from %d tp 0 : %d\n",head,d);
                                td+=d;
                                head=0;
                                

   }
   d=size-head;
                                   printf("head movement from 0 tp %d : %d\n",size,d);
                                   td+=d;
                                   head=size;

   for(i=n-1;i>=0;i--)
   {
   if(a[i]<head && !visited[i])
   {
       d=head-a[i];
       printf("head movement from %d tp %d : %d\n",head,a[i],d);
       td+=d;
       head =a[i];
        
   }
   }
   
   }
   printf("\ntotal distance travelled by head is %d",td);
    
   }
   
   
