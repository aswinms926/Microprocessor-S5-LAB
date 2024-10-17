#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	FILE *fp;
	int i,j,staddr1;
	char name[60],line[60],staddr[60];

	fp=fopen("record.txt","r");
	fscanf(fp,"%s",line);
	for(i=2,j=0;i<8,j<6;i++,j++)
	{
		name[j]=line[i];
	}
	name[j]='\0';

	printf("the program name is %s\n",name);

	do
	{
		fscanf(fp,"%s",line);
		if(line[0]=='T')
		{
			for(i=2,j=0;i<8,j<6;i++,j++)
				{
					staddr[j]=line[i];
				}
					staddr[j]='\0';
				staddr1=strtol(staddr,NULL,16);
			
	i=12;
		while(line[i]!='\0')
		{
			if(line[i]=='^')
			{
				i++;
				continue;
			}
			else
			{
				printf("\n%x\t%c%c\n",staddr1,line[i],line[i+1]);
				staddr1++;
				i+=2;
			}
		}

	}else if(line[0]=='E')
		{
			break;
		}
	}while(!feof(fp));
}
