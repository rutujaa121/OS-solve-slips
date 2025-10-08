#include<stdio.h>
#include<stdlib.h>
int allocation[20][20],max[20][20],available[20],need[20][20],safe[10],s=0;
int finish[10], work[10], cnt=0, flag=0, temp=0;
int p,r,j,i,ch,ind,req[10];

void check()
{
	temp=0;
	s=0;
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	need[i][j]=max[i][j]-allocation[i][j];
	printf("\n Need Table is:: \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		printf("%d\t",need[i][j]);
		printf("\n");
	}
	for(i=0;i<p;i++)
	finish[i]=0;
	for(i=0;i<r;i++)
	work[i]=available[i];
	while(temp<2)
	{
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				if(finish[i]==0 && need[i][j] <= work[j])
				flag=1;
				else
				{
					flag=0;
					break;
				}
				
				if(flag==1)
				{
					for(j=0;j<r;j++)
					work[j]=work[j]+allocation[i][j];
					finish[i]=1;
					safe[s++]=i;
				}
			}
			temp ++;
		}
		flag=0;
		for(i=0;i<p;i++)
		{
			if(finish[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\n System is in deadlock stake ");
		}
		else
		{
			printf("\n System is in safe state ");
			printf("\n Safe Sequence is: ");
			for(i=0;i<p;i++)
			printf("p%d\t",safe[i]);
		}
	}
}

int main()
{
	system("Clear");
	printf("\n ************\t BANKERS ALGORITHM \t************");
	printf("\n \n Enter the number of resourses and processes: ");
	scanf("%d%d",&r,&p);
	printf("\n Enter the allocation table: \n");
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	scanf("%d",& allocation[i][j]);
	
	printf("\n Enter the max Table: \n");
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	scanf("%d",&max[i][j]);
	printf("\n Enter the vector available: ");
	for(i=0;i<p;i++)
	scanf("%d",&available[i]);
	check();
	
}
