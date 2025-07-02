#include<stdio.h>
#include<stdlib.h>

typedef struct QN
{
    int ele,pri;
    struct QN *next;
}qn;

typedef struct q
{
    qn *f,*r;
}Q;

Q q1;

void enqueue(Q *q)
{
    qn *temp=(qn*)malloc(sizeof(qn));
    int ele,pri;
    printf("Enter the element and its priority .\n");
    scanf("%d %d",&ele,&pri);
    temp->ele=ele;
    temp->pri=pri;
    temp->next=NULL;
    if(q->f==NULL)
    {
        q->f=temp;
        q->r=temp;
    }
    else if((temp->pri)<=((q->r)->pri))
    {
        q->r->next=temp;
        q->r=temp;
    }
    else
    {
        qn *p=q->f;
        qn *befp=NULL;
        while(((p->pri)>=(temp->pri))&&(p!=NULL))
        {
            befp=p;
            p=p->next;
        }
        if(befp==NULL)
        {
            temp->next=p;
            q->f=temp;
        }
        else
        {
            temp->next=p;
            befp->next=temp;
        }
    }
}

void dequeue(Q *q)
{
    if(q->f==NULL)
    {
        printf("Underflow .\n");
    }
    else{
        qn *p=q->f;
        printf("Element %d having a priority %d is removed .\n",q->f->ele,q->f->pri);
        q->f=q->f->next;
        free(p);
    }
}

void display(Q *q)
{
    if(q->f==NULL)
    {
        printf("Underflow .\n");
    }
    else
    {
    qn *p=q->f;
    printf("\n");
    while(p!=NULL)
    {
        printf("(element : %d , priority : %d)->",p->ele,p->pri);
        p=p->next;
    }
    printf("\n");
    }
}

void init(Q *q)
{
    q->f=NULL;
    q->r=NULL;
}

int main()
{
    init(&q1);
    int choice,n=1;
    while(n)
    {
        printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : enqueue(&q1);
                     break;
            case 2 : dequeue(&q1);
                     break;
            case 3 : display(&q1);
                     break;
            case 4 : n=0;
                     break;
            default : printf("Enter a valid choice .\n");
                      break;
        }
    }

    return 0;
}