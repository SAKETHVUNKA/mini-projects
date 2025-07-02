#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *link;
}n;

typedef struct total
{
    n *fr,*re;
}t;

void init(t *q)
{
    q->fr=NULL;
    q->re=NULL;
}

void display(t *q)
{
    if (q->fr == NULL)
    {
        printf("List is empty .\n");
        return;
    }
    else
    {
        printf("\nQueue Elements:\n");
        n* temp;
        temp=q->fr;
        while(temp!=q->re)
        {
            printf("%d -> ",temp->ele);
            temp=temp->link;
        }
        printf("%d -> Front",temp->ele);
    }
}

void Enqueue(t *q)
{
    n *temp = (n *)malloc(sizeof(n));
    printf("Enter the element: ");
    scanf("%d", &(temp->ele));
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

void Dequeue(t *q)
{
    if (q->fr == NULL)
    {
        printf("Underflow\n");
    }
    else if (q->fr->link == q->fr)
    {
        free(q->fr);
        q->fr = NULL;
        q->re = NULL;
    }
    else
    {
       n *temp=q->fr;
       q->fr=q->fr->link;
       q->re->link=q->fr;
       printf("%d is deleted .\n",temp->ele);
       free(temp);
       temp=NULL; 
    }
}

int main()
{
    t q;
    init(&q);
    int choice,n=1;
    while(n)
    {
        printf("\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n\nEnter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: Enqueue(&q);
                break;
        case 2: Dequeue(&q);
                break;
        case 3: display(&q);
                break;
        case 4: n=0;
                break;
        default:break;
        }
    }
    return 0;
}