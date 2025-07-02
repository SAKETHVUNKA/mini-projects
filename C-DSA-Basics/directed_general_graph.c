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

int connected(int n,int a[n][n])
{
    for(int i=0;i<n;i++)
    {
        int visited[max]={0};
        dfs(n,a,visited,i);
        for(int j=0;j<n;j++)
        {
            if(visited[j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n,r;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int a[n][n];
    read_graph(n,a);
    r=connected(n,a);
    if(r==1)
    {
        printf("Graph is Unconnected .\n");
    }
    else
    {
        printf("Graph is Connected .\n");
    }

    return 0;
}