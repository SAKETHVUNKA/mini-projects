#include<stdio.h>

#define max 10

void read_graph(int n,int a[n][n])
{
    printf("enter the elements one by one :\n");
    for(int j=0;j<n;j++)
    {
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
    printf("%d ",node);
    for(int i=0;i<n;i++)
    {
        if((a[node][i])&&(!visited[i]))
        {
            dfs(n,a,visited,i);        
        }
    }
}

int main()
{
    int n,node=0,i;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int a[n][n];
    read_graph(n,a);
    int visited[max]={0};
    dfs(n,a,visited,node);
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            break;
        }
    }
    if(i<n)
    {
        printf("Graph not connected .\n");
    }
    else
    {
        printf("Graph is connected .\n");
    }

    return 0;
}