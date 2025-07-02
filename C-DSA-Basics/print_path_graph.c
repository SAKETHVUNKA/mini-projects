#include<stdio.h>
#include<stdlib.h>

#define max 10
int l=0;

void read_graph(int n,int a[n][n])
{
    for(int j=0;j<n;j++)
    {
        printf("enter the elements of %d row :\n",j);
        for(int k=0;k<n;k++)
        {
            scanf("%d",&a[j][k]);
        }
    }
    printf("\n");
}

int dfs(int n,int a[n][n],int visited[max],int node,int dest,int apath[max])
{
    visited[node]=1;
    for(int i=0;i<n;i++)
    {
        if((a[node][i])&&(!visited[i]))
        {
            l++;
            apath[l]=i;
            if((i==dest)||(dfs(n,a,visited,i,dest,apath)))
            {
                return 1;
            }
        }
    }
    l--;
    return 0;
}

int path(int n,int a[n][n])
{
    int s,d;
    int apath[max];
    int visited[max]={0};
    printf("Enter the source and destination :");
    scanf("%d %d",&s,&d);
    apath[l]=s;
    int k=dfs(n,a,visited,s,d,apath);
    if(k==1)
    {
        for(int m=0;m<l;m++)
        {
            printf("%d->",apath[m]);
        }
        printf("%d",d);
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n,r;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int a[n][n];
    read_graph(n,a);
    r=path(n,a);
    if(r==1)
    {
        printf("Path is Available .\n");
    }
    else
    {
        printf("Path is Unavailable .\n");
    }

    return 0;
}