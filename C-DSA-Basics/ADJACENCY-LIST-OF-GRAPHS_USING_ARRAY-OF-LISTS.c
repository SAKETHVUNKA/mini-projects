#include<stdio.h>

void read_graph(int n,int a[n][n])
{
    for(int j=0;j<n;j++)
    {
        printf("Enter the %d row of adjacencey matrix of graph : ",j);
        for(int k=0;k<n;k++)
        {
            scanf("%d ",&a[j][k]);
        }
        printf("\n");
    }
}

void display_graph(int n,int a[n][n])
{
    printf("The adjacency matrix of the graph is : \n");
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<n;k++)
        {
            printf("%d ",a[j][k]);
        }
        printf("\n");
    }
}

int in_degree(int n,int a[n][n],int v)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(a[i][v]==1)
        {
            count++;
        }
    }
    return count;
}

int out_degree(int n,int a[n][n],int v)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(a[v][i]==1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n,choice,z=1;
    printf("Enter the number of vertices : ");
    int a[n][n];
    scanf("%d",&n);
    read_graph(n,a);
    display_graph(n,a);
    while(z)
    {
        printf("1)In_order \n2)Out_order \n3)Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element to count in-degree for: ");
                    int v;
                    scanf("%d",&v);
                    printf("\n%d\n",in_degree(n,a,v));
                    break;
            case 2: printf("\nEnter the element to count out-degree for: ");
                    int v;
                    scanf("%d",&v);
                    printf("\n%d\n",out_degree(n,a,v));
                    break;
            case 3: z=0;
                    break;
            default:printf("Enter values from the list .\n");
                    break;
        }
    }

    return 0;
}