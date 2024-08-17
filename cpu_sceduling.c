#include<stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
    int ch;
    while(1)
    {
    printf("Enter your choise : 1)fcfs\t2)sjf\t3)priority\t4)round_robin\t5)exit : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
        int p[30],bt[30],tat[30],wt[30],tot_tat=0,tot_wt=0,i,n;
    printf("Enter the number of process : ");
    scanf("%d",&n);

    
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    printf("\nfcfs");
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else
        {
            tat[i]=tat[i-1]+bt[i];
        }
        tot_tat=tot_tat+tat[i];

    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
        
    }
    printf("\nPROCESS\t\tBURSTTIME\tTURNAROUNDTIME\tWAITINGTIME\n");
    for(i=0;i<n;i++)
    {
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d\n",p[i]+1,bt[i],tat[i],wt[i]);

        

    }
    printf("tot_tat=%d\n",tot_tat);
         printf("avg tot_tat=%d\n",tot_tat/n);
         printf("tot_wt=%d\n",tot_wt);
         printf("avg tot_wt=%d\n",tot_wt/n);

          printf("\n-------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("P[%d]\t\t",i+1);
            
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
           
            printf("%d\t\t",wt[i]);
        }

                printf("\n-------------------------------------------------------");

        printf("\n");
        break;
        }



        case 2 :
        {
       int p[30],bt[30],tat[30],wt[30],tot_tat=0,tot_wt=0,i,n,j;
    printf("Enter the number of process : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    printf("\nfcfs");
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else
        {
            tat[i]=tat[i-1]+bt[i];
        }
        tot_tat=tot_tat+tat[i];

    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
        
    }
    printf("\nPROCESS\t\tBURSTTIME\tTURNAROUNDTIME\tWAITINGTIME\n");
    for(i=0;i<n;i++)
    {
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d\n",p[i]+1,bt[i],tat[i],wt[i]);

        

    }
    printf("tot_tat=%d\n",tot_tat);
         printf("avg tot_tat=%d\n",tot_tat/n);
         printf("tot_wt=%d\n",tot_wt);
         printf("avg tot_wt=%d\n",tot_wt/n);

          printf("\n-------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("P[%d]\t\t",i+1);
            
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
           
            printf("%d\t\t",wt[i]);
        }

                printf("\n-------------------------------------------------------");

        printf("\n");
        break;
        }



        case 3 :
        {
       int j,pr[30],p[30],bt[30],tat[30],wt[30],i,n,tot_tat,tot_wt;

    printf("Enter the number of process : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the burst time and priority of process %d : ",i+1);
        scanf("%d%d",&bt[i],&pr[i]);
        p[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                swap(&pr[i],&pr[j]);
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else{
            tat[i]=tat[i-1]+bt[i];
        }
        tot_tat=tot_tat+tat[i];
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
         wt[i]=wt[i-1]+bt[i-1];
         tot_wt=tot_wt+wt[i];
    }
    printf("\nPROCESS\t\t\tBT\t\ttat\t\twt\t\tpr\n");
    for(i=0;i<n;i++)
    {
        printf("process[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i]+1,bt[i],tat[i],wt[i],pr[i]);
    }
    printf("\n-------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]\t\t",i+1);
    }
    printf("\n");
     for(i=0;i<n;i++)
    {
        printf("%d\t\t",wt[i]);
    }

        printf("\n-------------------------------------------------------------\n");
        break;
        }




        case 4:
        {
       int limit,x,i,t,total,counter=0,tat,wt,bt[100],temp[100],gantt[100],gi=0;

    printf("Enter the number of process : ");
    scanf("%d",&limit);
x=limit;
       
        for(i=0;i<limit;i++)
        {
             printf("Enter the burst time of %d : ",i+1);
                scanf("%d",&bt[i]);
                temp[i]=bt[i];
        }
         printf("Enter the t : ");
    scanf("%d",&t);
    printf("process\t\t\tbt\t\ttat\t\twt\n");
    for(i=0,total=0;x!=0;)
    {
        if(temp[i]<=t && temp[i]>0)
        {
            total+=temp[i];
            gantt[gi++]=i;
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0)
        {
            temp[i]-=t;
            gantt[gi++]=i;
            total+=t;
            
        }
        if(temp[i]==0 && counter==1)
        {
            x--;
            printf("process[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],total,total-bt[i]);
            tat+=total;
            wt=wt+total-bt[i];
            counter=0;
        }
        if(i==limit-1)
        {
            i=0;
        }
        else{
            i++;
        }
    }
    printf("-------------------------------------------------------------------------------------\n");
    for(i=0;i<gi;i++)
    {
        printf("p[%d]\t\t",gantt[i]+1);
    }
        printf("\n--------------------------------------------------------------------------------\n");
         printf("Total Turnaround Time = %d\n", tat);
                printf("Average Turnaround Time = %.2f\n", (float)tat / limit);
                printf("Total Waiting Time = %d\n", wt);
                printf("Average Waiting Time = %.2f\n", (float)wt / limit);
        break;




        case 5:
        printf("exiting !!!!!!!!!!!");
        exit(0);


        default :
        printf("error try again !!");
        break;


    }
    }
    }
}
