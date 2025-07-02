#include<stdio.h>

#define max 10

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

void dfs(int n,int a[n][n],int visited[max],int node)
{
    visited[node]=1;
    for(int i=0;i<n;i++)
    {
        if((a[node][i])&&(!visited[i]))
        {
            dfs(n,a,visited,i);        
        }
    }
}

int path(int n,int a[n][n])
{
    int s,d;
    int visited[max]={0};
    printf("Enter the source and destination :");
    scanf("%d %d",&s,&d);
    dfs(n,a,visited,s);
    if(visited[d]==1)
    {
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
        printf("Path is available .\n");
    }
    else
    {
        printf("path is unavailable .\n");
    }

    return 0;
}