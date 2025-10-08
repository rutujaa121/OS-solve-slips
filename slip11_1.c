#include<stdio.h>
#include<stdlib.h>

void main()
{
	int p[10],at[10],bt[10],wt[10],tat[10];
	int i,j,n,temp,sum=0;
	float avg=0;
	printf("Enter the limit: ");
	scanf("%d",&n);
	printf("Enter the process with their arrival and burst time: ");
	for(i=0;i<n;i++)
	{
		printf("\n Enter the process: ");
		scanf("%d",&p[i]);
		
		printf("\n Enter the arrival time: ");
		scanf("%d",&at[i]);
		
		printf("\n Enter the burst time: ");
		scanf("%d",&bt[i]);
	}
	for(i=0; i<n; i++)
	for(j=i+1; j<n; j++)
	{
		if(at[i]>at[j])
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			
			temp=at[i];
			at[i]=at[j];
			at[j]=temp;
			
			temp=bt[i];
			bt[i]=at[j];
			bt[j]=temp;
		}
	}
	printf("after sorting: ");
	for(i=0;i<n;i++)
	{
		printf("\np%d\t%d\t%d: ",p[i],at[i],bt[i]);
	}
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		wt[i+1]=wt[i]+bt[i];
		sum +=(wt[i]-at[i]);
	}
	wt[n]=wt[n-1]+bt[n-1];
	printf("\n sum of waiting time is: %d",sum);
	avg=(float)sum/(float)n;
	printf("\n average of waiting is: %f",avg);
	sum=0;
	for(i=0;i<n;i++)
	{
		tat[i]=(wt[i]-at[i]);
		sum+=wt[i+1]-tat[i];
	}
	printf("\n sum of turn around time is: %d",sum);
	avg=(float)sum/(float)n;
	printf("\n average of turnaround time is: %f",avg);
	printf("Gantt Chart");
	printf("\n******************************\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t",p[i]);
	}
	printf("\n *****************************\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\t",wt[i]);
	}
}
