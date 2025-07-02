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

void bfs(int n,int a[n][n],int q[max],int visited[max],int r,int f)
{
    while(f<=r)
    {
        int x=q[f++];
        printf("%d ",x);
        for(int i=0;i<n;i++)
        {
            if((a[x][i])&&(!visited[i]))
            {
                q[++r]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int n,choice,z=1;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int a[n][n];
    read_graph(n,a);
    int visited[max]={0};
    int q[max]={0},f=0,r=-1;
    q[++r]=0;
    visited[0]=1;
    bfs(n,a,q,visited,r,f);

    return 0;
}
//handle multiple sub-graphs case