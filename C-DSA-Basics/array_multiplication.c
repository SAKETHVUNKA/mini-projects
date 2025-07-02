#include<stdio.h>
void main()
{
int r1,r2,c1,c2,a1[100][100],a2[100][100],c[100][100],sum,i=0,j=0,k=0;
scanf("%d %d",&r1,&c1);
scanf("%d %d",&r2,&c2);
for(int i=0;i<r1;i++)
{
	for(int j=0;j<c1;j++)
	{
		scanf("%d",&a1[i][j]);
	}
}
for(int i=0;i<r2;i++)
{
	for(int j=0;j<c2;j++)
	{
		scanf("%d",&a2[i][j]);
	}
}
for(i=0;i<r1;i++)
{
	for(j=0;j<c2;j++)
	{
		sum=0;
		for(k=0;k<r2;k++)
		{
			sum=sum+a1[i][k]*a2[k][j];
		}
		c[i][j]=sum;
	}
}
for(int i=0;i<r1;i++)
{
	for(int j=0;j<c2;j++)
	printf("%d\t",c[i][j]);
	printf("\n");
}
}
