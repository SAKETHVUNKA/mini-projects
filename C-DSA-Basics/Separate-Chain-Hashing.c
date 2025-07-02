#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int key;
    struct Node *next;
}node;

void insert(int n,int size,node* a[size])
{
    node* temp=malloc(sizeof(node));
    temp->key=n;
    temp->next=NULL;
    int mod=n%size;
    if(a[mod]==NULL)
    {
        a[mod]=temp;
    }
    else
    {
        node *p=a[mod];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void display(int size,node *a[size])
{
    for(int i=0;i<size;i++)
    {
        node *p=a[i];
        while(p!=NULL)
        {
            printf("%d , ",p->key);
            p=p->next;
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the hash table : ");
    scanf("%d",&size);
    node *a[size];
    for(int i=0;i<size;i++)
    {
        a[i]=NULL;
    }
    insert(10,size,a);
    insert(11,size,a);
    insert(20,size,a);
    insert(30,size,a);
    insert(22,size,a);
    insert(7,size,a);

    display(size,a);
    
    return 0;
}