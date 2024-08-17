#include<stdio.h>
void main()
{
    int max[10][10],alloc[10][10],need[10][10],maxer[10],avail[10],i,j,k,y,ind=0,n,m;

    printf("Enter the number of process and number of resources : ");
    scanf("%d%d",&n,&m);

    printf("Enter the instances of the reasources : ");
    for(j=0;j<m;j++)
    {
        scanf("%d",&maxer[j]);
        avail[j]=maxer[j];
    }

    printf("Enter the allocation matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
     printf("Enter the max matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("The need matrix is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);

        }
        printf("\n");
    }

    for(j=0;j<m;j++)
    {
       int sum=0;
        for(i=0;i<n;i++)
        {
            sum+=alloc[i][j];
        }
        avail[j]-=sum;
    }
    int finish[10],work[10],safe[10];
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safe[ind++]=i;
                    for(y=0;y<m;y++)
                    {
                        work[y]+=alloc[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
   for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            printf("System is in unsafe state\n");
            return;
        }
    }

    printf("System is in safe state. Safe sequence is: ");
    for (i = 0; i < n - 1; i++) {
        printf("P%d -> ", safe[i]);
    }
    printf("P%d\n", safe[n - 1]);


}