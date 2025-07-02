#include<stdlib.h>
#include<stdio.h>

#define max 40
int found=0;

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;

int dfs(unsigned int n,int a[max][max],int visited[max],int dvisited[max],int node)
{
    visited[node]=1;
    dvisited[node]=1;
    for(int i=0;i<n;i++)
    {
        if(a[node][i]==1)
        {
        if (i==node)
        {
            
        }
        else if(!visited[i])
        {
            if(dfs(n,a,visited,dvisited,i))
            {
                return 1;
            }   
        }
        else if(dvisited[i])
        {
            return 1;
        }
        }
    }
    dvisited[node]=0;
    return 0;
}

void matrix_create(const edge *edges,unsigned int n,int a[max][max])
{
    for(int i=0;i<n;i++)
    {
        int m=edges[i].first;
        int n=edges[i].second;
        a[m][n]=1;
    }
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
    int a[max][max]={0};
    int visited[max]={0};
    int dvisited[max]={0};
    matrix_create(edges,n,a);
    for(int i=0;i<order;i++)
    {
        if(!visited[i])
        {
            if(dfs(order,a,visited,dvisited,i))
            {
                return 1;
            }
        }
    }
    return 0;
}

/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }   
    ans=cycle_finder(edges, n, order);
    printf("\n");
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}
