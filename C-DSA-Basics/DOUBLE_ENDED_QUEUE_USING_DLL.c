#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int ele;
    struct list *r,*l;
}l;

typedef struct queue
{
    l *fr,*re;
}q;

void EnqueueBeg(q** q1)
{
    int ele;
    printf("Enter the element .\n");
    scanf("%d",&ele);
    if((*q1)->fr==NULL)
    {
        l *temp=NULL;
        temp=(l*)malloc(sizeof(l));
        temp->ele=ele;
        (*q1)->fr=temp;
        (*q1)->re=temp;
        temp->l=NULL;
        temp->r=NULL;
    }
    else
    {
        l *temp=NULL;
        temp=(l*)malloc(sizeof(l));
        temp->ele=ele;
        temp->r=(*q1)->fr;
        temp->l=NULL;
        (*q1)->fr=temp;
        temp->r->l=temp;
    }
}

void EnqueueRe(q** q1)
{
    int ele;
    printf("Enter the element .\n");
    scanf("%d",&ele);
    if((*q1)->fr==NULL)
    {
        l *temp=NULL;
        temp=(l*)malloc(sizeof(l));
        temp->ele=ele;
        (*q1)->fr=temp;
        (*q1)->re=temp;
        temp->l=NULL;
        temp->r=NULL;
    }
    else
    {
        l *p=(*q1)->re;
        l *temp=NULL;
        temp=(l*)malloc(sizeof(l));
        temp->ele=ele;
        p->r=temp;
        temp->r=NULL;
        temp->l=p;
        (*q1)->re=temp;
    }
}
 
void DequeueBeg(q** q1)
{
    if ((*q1)->fr == NULL)
    {
        printf("Queue is empty!\n");
    }
    else if ((*q1)->fr->r == NULL)
    {
        free((*q1)->fr);
        (*q1)->fr = NULL;
        (*q1)->re = NULL;
    }
    else
    {
        (*q1)->fr = (*q1)->fr->r;
        free((*q1)->fr->l);
        (*q1)->fr->l = NULL;
    }
}

void DequeueRe(q** q1)
{
    if ((*q1)->fr == NULL)
    {
        printf("List is empty!");
    }
    else if ((*q1)->fr->r == NULL)
    {
        free((*q1)->fr);
        (*q1)->fr = NULL;
        (*q1)->re = NULL;
    }
    else
    {
        l *p = (*q1)->fr;
        while (p->r != NULL)
        {
            p = p->r;
        }
        p->l->r = NULL;
        (*q1)->re=p->l;
        free(p);
    }
}

void init(q** q1)
{
    (*q1)->fr=NULL;
    (*q1)->re=NULL;
}

void display(q** q1)
{
    l* temp=(*q1)->fr;
    while(temp!=(*q1)->re)
    {
        printf("%d ->",temp->ele);
    }
    printf("%d \n",temp->ele);
}

int main()
{
    q *q1;
    int choice,n=1;
    while(n)
    {
        printf("\n1. EnqueueBeg\n2. EnqueueRe\n3. DequeueBeg\n4. DequeueRe\n5. Display\n6. Exit\n\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            EnqueueBeg(&q1);
            break;
        case 2:
            EnqueueRe(&q1);
            break;
        case 3:
            DequeueBeg(&q1);
            break;
        case 4:
            DequeueRe(&q1);
            break;
        case 5:
            display(&q1);
            break;
        case 6:
            n=0;
            break;
        default:break;
        }
    }

    return 0;
}