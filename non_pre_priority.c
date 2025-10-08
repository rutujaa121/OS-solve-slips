#include<stdio.h>
#include<stdlib.h>
void main()
{
          int p[10],at[10],bt[10],wt[10],tat[10],pr[10];
          int i,j,sum=0,temp,n;
          float avg;
          printf("enter the limit:");
          scanf("%d",&n);
          for(i=0;i<n;i++)
          {
                    printf("enter the process number:");
                    scanf("%d",&p[i]);
                    printf("enter the process arrival time:");
                    scanf("%d",&at[i]);
                    printf("enter the process burst time:");
                    scanf("%d",&bt[i]);
                    printf("enter the priority:");
                    scanf("%d",&pr[i]);
          }
          for(i=0;i<n;i++)
          {
                    if(at[i]==0)
                    {
                              temp=p[0];
                              p[0]=p[i];
                              p[i]=temp;

                              temp=at[0];
                              at[0]=at[i];
                              at[i]=temp;

                              temp=bt[0];
                              bt[0]=bt[i];
                              bt[i]=temp;
                    }
          }
          for(i=1;i<n;i++)
          {
                    for(j=i+1;j<n;j++)
                    {
                              if(pr[i]>pr[j])
                              {
                                       temp=p[i];
                                        p[i]=p[j];
                                        p[j]=temp;

                                        temp=at[i];
                                        at[i]=at[j];
                                        at[j]=temp;

                                        temp=bt[i];
                                        bt[i]=bt[j];
                                        bt[j]=temp;

                                        temp=pr[i];
                                        pr[i]=pr[j];
                                        pr[j]=temp;
                              }
                    }
          }
          for(i=1;i<n;i++)
                    for(j=i+1;j<n;j++)
          {
                    if(pr[i]==pr[j])
                    {
                              if(bt[i]>bt[j])
                              {
                                        temp=p[i];
                                        p[i]=p[j];
                                        p[j]=temp;

                                        temp=at[i];
                                        at[i]=at[j];
                                        at[j]=temp;

                                        temp=bt[i];
                                        bt[i]=bt[j];
                                        bt[j]=temp;

                                        temp=pr[i];
                                        pr[i]=pr[j];
                                        pr[j]=temp;
                              }

                    }
          }
          printf("after sorting:");
          for(i=0;i<n;i++)
          {
                    printf("\n p%d\t%d\t%d",p[i],at[i],bt[i]);
          }
          wt[0]=0;
          for(i=0;i<n;i++)
          {
                    wt[i+1]=wt[i]+bt[i];
                    sum+=(wt[i]-at[i]);
          }
          wt[n]=wt[n-1]+bt[n-1];
          printf("\n sum of waiting time is:%d",sum);
          avg=(float)sum/(float)n;
          printf("\n average of waiting time is:%f",avg);
          sum=0;
          for(i=0;i<n;i++)
          {
                    tat[i]=(wt[i]-at[i]);
                    sum+=wt[i+1]-tat[i];
          }
          printf("\n sum of turn is:%d",sum);
          avg=(float)sum/(float)n;
          printf("\n average of turn is:%f",avg);
          printf("gantt chart");
          printf("\n.......\n");
          for(i=0;i<n;i++)
          {
                    printf("%d\t",p[i]);
          }
          printf("\n.........\n");
          for(i=0;i<=n;i++)
          {
                    printf("%d\t",wt[i]);
          }
}
