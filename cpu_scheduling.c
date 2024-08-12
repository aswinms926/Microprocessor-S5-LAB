#include<stdio.h>

void fcfs();
void sjf();
void rr();
void priority();
void swap(int *,int *);

int main()
{
    int choice;
    while(1)
    {
    printf("\n\n1.FCFS\t2.SJF\t3.RR\t4.PRIORITY\t5.EXIT\n");
    printf("Enter Choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        fcfs();
        break;
    case 2:
        sjf();
        break;
    case 3:
        rr();
        break;
    case 4:
        priority();
        break;
    case 5:
        printf("Successfully Terminated");
		return 0;
        break;
    
    default:
        break;
    }
    }
}


void fcfs()
{
    int n;
	
	printf("Enter the number of process\n");
	scanf("%d",&n);
	int btime[n];
	int wtime[n];
	int ttime[n];
	int i;
	float totalw=0;
	float totalt=0;
	
	for(i=0; i<n; i++)
	{
		printf("Enter the burst Time of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&btime[i]);
	}
	
	wtime[0]=0;
	for(i=1; i<n;i++)
	{
		wtime[i]=wtime[i-1]+btime[i-1];
	}
	
	for(i=0; i<n; i++)
	{
		ttime[i]=btime[i]+wtime[i];
	}
	
	printf("\n ProcessID	Burst time	Waiting time	TA time");
	for(i=0; i<n; i++)
	printf("\n P[%d]\t\t %d\t\t%d\t\t%d",i,btime[i],wtime[i],ttime[i]);
	
	for(i=0; i<n; i++)
	{
	totalw=wtime[i]+totalw;
	totalt=ttime[i]+totalt;
	}
	float avgwt=totalw/n;
	float avgtt=totalt/n;
	int temp=0;
	printf("\nAverage Waiting Time:%f", avgwt);
	printf("\nAverage Turn Around Time:%f", avgtt);
	
	printf("\n======================================\n");
	for( i=0; i<n; i++)
	{
		printf("   P%d   ",i);
	}
	
	printf("\n======================================\n");
	for( i=0; i<=n; i++)
	{
		printf("%d\t",temp);
		temp=temp+btime[i];
	}
}


void sjf()
{
    int n;
	
	printf("Enter the number of process\n");
	scanf("%d",&n);
	int btime[n];
	int wtime[n];
	int ttime[n];
    int temp=0;
	int i,j;
    int pid[n];
	float totalw=0;
	float totalt=0;
	
	for(i=0; i<n; i++)
	{
		printf("Enter the burst Time of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&btime[i]);
        pid[i]=i;
	}

    for(i=0; i<n-1; i++)
	{
	for(j=0; j<n-i-1; j++)
	{
		if(btime[j]>btime[j+1])
		{
		//Swapping
            swap(&btime[j],&btime[j+1]);
            swap(&pid[j], &pid[j+1]);
        }
	}
    }

	wtime[0]=0;
	for(i=1; i<n;i++)
	{
		wtime[i]=wtime[i-1]+btime[i-1];
	}
	
	for(i=0; i<n; i++)
	{
		ttime[i]=btime[i]+wtime[i];
	}
	
	printf("\n ProcessID	Burst time	Waiting time	TA time");
	for(i=0; i<n; i++)
	printf("\n P[%d]\t\t %d\t\t%d\t\t%d",pid[i],btime[i],wtime[i],ttime[i]);
	
	for(i=0; i<n; i++)
	{
	totalw=wtime[i]+totalw;
	totalt=ttime[i]+totalt;
	}
	float avgwt=totalw/n;
	float avgtt=totalt/n;
	printf("\nAverage Waiting Time:%f", avgwt);
	printf("\nAverage Turn Around Time:%f", avgtt);
	
	printf("\n======================================\n");
	for( i=0; i<n; i++)
	{
		printf("   P%d   ",pid[i]);
	}
	
	printf("\n======================================\n");
	for( i=0; i<=n; i++)
	{
		printf("%d\t",temp);
		temp=temp+btime[i];
	}
   
    		
}

void rr()
{
     int i, limit, total = 0, x, counter = 0, time_quantum , j=0 , k=0,sum=0;
   int wait_time = 0, turnaround_time = 0, burst_time[10], temp[10] , gc[50] , id[50];
   float average_wait_time, average_turnaround_time;
   printf("\nEnter Total Number of Processes: ");
   scanf("%d", &limit);
   x  = limit;
   for(i = 0; i < limit; i++) 
   {
       printf("\nEnter Burst Time of Process P[%d]: ", i);
       scanf("%d", &burst_time[i]);
       temp[i] = burst_time[i];
   }
   printf("\nEnter Time Quantum: ");
   scanf("%d", &time_quantum);
   printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
   for(total = 0, i = 0; x != 0;) 
   {
       if(temp[i] <= time_quantum && temp[i] > 0) 
       {
           total = total + temp[i];
           gc[j++]=temp[i];
           id[k++]=i;
           temp[i] = 0;
           counter = 1;
       }
       else if(temp[i] > time_quantum) 
       {
           temp[i] = temp[i] - time_quantum;
           gc[j++]=time_quantum;
           id[k++]=i;
           total = total + time_quantum;
       }

        if(temp[i] == 0 && counter == 1) 
       {
           x--;
           printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i , burst_time[i], total, total - burst_time[i]);
           wait_time = wait_time + total - burst_time[i];
           turnaround_time = turnaround_time + total ;
           counter = 0;
       }
       if(i == limit - 1) 
           i = 0;
       else 
           i++;
   }
   printf("\nGantt chart");
   printf("\n-----------------------------------------------------------------\n");
   for (i = 0; i < k; i++)
      printf("    P%d\t",id[i]);
    printf("\n-----------------------------------------------------------------\n");
   int temp12=0;
   for (int m = 0; m <= j; m++)
   {
      printf("%d\t",temp12);
      temp12+=gc[m];
   }
   average_wait_time = wait_time * 1.0 / limit;
   average_turnaround_time = turnaround_time * 1.0 / limit;
   printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
   printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);

}


void priority()
{
    int n;
	
	printf("Enter the number of process\n");
	scanf("%d",&n);
	int btime[n];
	int wtime[n];
	int ttime[n];
    int priority[n];
    int temp=0;
	int i,j;
    int pid[n];
	float totalw=0;
	float totalt=0;
	
	for(i=0; i<n; i++)
	{
		printf("Enter the burst Time of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&btime[i]);
        printf("Enter the Priority value of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&priority[i]);
        pid[i]=i;
	}

     for(i=0; i<n-1; i++)
	{
	for(j=0; j<n-i-1; j++)
	{
		if(priority[j]>priority[j+1])
		{
		//Swapping
            swap(&priority[j],&priority[j+1]);
            swap(&btime[j],&btime[j+1]);
            swap(&pid[j], &pid[j+1]);
        }
	}
    }

	wtime[0]=0;
	for(i=1; i<n;i++)
	{
		wtime[i]=wtime[i-1]+btime[i-1];
	}
	
	for(i=0; i<n; i++)
	{
		ttime[i]=btime[i]+wtime[i];
	}
	
	printf("\n ProcessID	Burst time Priority  Waiting time	TA time");
	for(i=0; i<n; i++)
	printf("\n P[%d]\t\t %d\t\t%d\t\t%d\t\t%d",pid[i],btime[i],priority[i],wtime[i],ttime[i]);
	
	for(i=0; i<n; i++)
	{
	totalw=wtime[i]+totalw;
	totalt=ttime[i]+totalt;
	}
	float avgwt=totalw/n;
	float avgtt=totalt/n;
	printf("\nAverage Waiting Time:%f", avgwt);
	printf("\nAverage Turn Around Time:%f", avgtt);
	
	printf("\n======================================\n");
	for( i=0; i<n; i++)
	{
		printf("   P%d   ",pid[i]);
	}
	
	printf("\n======================================\n");
	for( i=0; i<=n; i++)
	{
		printf("%d\t",temp);
		temp=temp+btime[i];
	}
    
}


void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}