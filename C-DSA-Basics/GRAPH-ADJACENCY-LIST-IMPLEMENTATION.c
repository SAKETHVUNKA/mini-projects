#include<stdio.h>
#include<stdlib.h>

#define max 10

typedef struct NODE
{
    int key;
    struct NODE *link;
}node;

node a[max];

node *insertrear(node *a,int ele)
{
    node *temp=malloc(sizeof(node));
    temp->key=ele;
    temp->link=NULL;
    if(a==NULL)
    {
        return temp;
    }
    else
    {
        node *curr=a;
        while(curr->link!=NULL)
        {
            curr=curr->link;
        }
        curr->link=temp;
        return a;
    }
}

void readgraph(int n)
{
    int m,ele,id;
    for(int i=0;i<n;i++)
    {
        printf("Enter the key of new vertice : ");
        scanf("%d",&id);
        a[i].key=id;
        printf("Enter the number of adjacent nodes to %d node : ",a[i].key);
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            printf("Enter the vertex connected : ");
            scanf("%d",&ele);
            a[i].link=insertrear(a[i].link,ele);
        }
    }
}

void displaygraph(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d -> ",a[i].key);
        node *temp=a[i].link;
        while(temp!=NULL)
        {
            printf("%d,",temp->key);
            temp=temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    readgraph(n);
    displaygraph(n);

    return 0;
}