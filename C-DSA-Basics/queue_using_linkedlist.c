#include<stdio.h>
#include<stdlib.h>

typedef struct Q
{
    int ele;
    struct Q *link;
}q;

void enqueue(q** f,q** r)
{
    q* temp=malloc(sizeof(q));
    printf("Enter the element .\n");
    scanf("%d",&(temp->ele));
    if((*f)==NULL&&(*r)==NULL)
    {
        (*f)=temp;
        (*r)=temp;
        temp->link=NULL;
    }
    else
    {
        (*r)->link=temp;
        (*r)=temp;
        temp->link=NULL;
    }
}

void dequeue(q** f,q** r)
{
    if((*f)==NULL)
    {
        printf("Queue is empty .\n");
    }
    else if((*f)==(*r))
    {
        free((*f));
        (*f)=NULL;
        (*r)=NULL;
    }
    else
    {
    q* p=(*f);
    (*f)=(*f)->link;
    free(p);
    p=NULL;
    }
}

void display(q** f,q** r)
{
    if((*f)==NULL && (*r)==NULL)
    {
        printf("Queue is empty .\n");
    }
    else
    {
    q* t=(*f);
    while(t!=NULL)
    {
        printf("%d -> ",t->ele);
        t=t->link;
    }
    printf("\n");
    }
}

void init(q **f,q **r)
{
    (*f)=NULL;
    (*r)=NULL;
}

int main()
{
    q *f,*r;
    init(&f,&r);
    int n,c;
    while(n)
    {
        printf("Enqueue 1 .\nDequeue 2 .\nDisplay 3.\nExit 4 .\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: enqueue(&f,&r);
                    break;
            case 2: dequeue(&f,&r);
                    break;
            case 3: display(&f,&r);
                    break;
            case 4: n=0;
                    break;
            default :printf("Enter valid option .\n");
                    break;
        }
    }
    return 0;
}