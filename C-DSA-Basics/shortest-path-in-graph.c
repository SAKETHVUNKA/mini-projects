#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph 
{
    int n; /* Number of vertices in graph */
    int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

//creates the graph
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while(1)
        {
            //edge between two vertex
            scanf("%d %d\n", &i, &j);
            if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }
            adj_mat->adj[i][j] = 1;
        }
    }

//helper functions for inserting an element into a queue 
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}

//helper function to delete from a queue 
int delete(int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

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

void bfs(Graph *adj_mat, int source, int dest, int *prev)
{
    int q[MAX_NODES]={0};
    int pqr=-1;
    int initial=1;
    int visited[MAX_NODES]={-100};
    append(q,source,&pqr);
    visited[source]=1;
    int delele;
    while((pqr>=0)||(initial))
    {
        initial=0;
        delele=delete(q,&pqr);
        for(int m=0;m<(adj_mat->n);m++)
        {
            if((adj_mat->adj[delele][m])&&(visited[m]==-100))
            {
                append(q,m,&pqr);
                visited[m]=1;
                prev[m]=delele;
            }
        }
    }
}

//bfs function to calculate the minimum distance 
//You are required to complete this function
int find_dist(Graph * adj_mat, int source, int dest)
{
    int predecessor[MAX_NODES]={-100};
    bfs(adj_mat,source,dest,predecessor);
    int path[MAX_NODES];
    int length = 0;
    for (int i = dest; i != -100; i = predecessor[i])
    {
        path[length++] = i;
    }
    /*int intermediate;
    for(int j=0;j<(length/2);j++)
    {
        intermediate = path[j];
        path[j]=path[length-j-1];
        path[length-j-1]=intermediate;
    }*/
    if(path[length-1]==source)
    {
        return (length);
    }
    else
    {
        return -1;
    }
}

int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d",result);
    return 0;
}