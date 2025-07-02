#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char a[15];
    struct node *link;
}n;

typedef struct total
{
    n *fr,*re;
}t;

void Enqueue(t *q,char a1[])
{
    n *temp = (n *)malloc(sizeof(n));
    strcpy(temp->a,a1);
    temp->link = NULL;
    if (q->fr == NULL)
    {
        q->fr = temp;
        q->re=temp;
        temp->link = q->fr;
    }
    else
    {
        q->re->link=temp;
        temp->link=q->fr;
        q->re=temp;
    }
}

void Dequeue(t *q,int s)
{
    n *befp,*p;
    befp=NULL;
    p=q->fr;
    while(p->link!=p)
    {
        for(int j=0;j<s-1;j++)
        {
            befp=p;
            p=p->link;
        }
        befp->link=p->link;
        free(p);
        p=befp->link;
    }    
    printf("The Winner is : %s",p->a);
    printf("\n");
}

void init(t *q)
{
    q->fr=NULL;
    q->re=NULL;
}

int main()
{
    t q;
    init(&q);
    int num,skip;
    printf("Enter the number of persons and the skip number .\n");
    scanf("%d %d",&num,&skip);
    for(int i=0;i<num;i++)
    {
        char a[15];
        printf("Enter the namre of person %d : ",i+1);
        scanf("%s",&a);
        Enqueue(&q,a);
    }
    Dequeue(&q,skip);
    return 0;
}