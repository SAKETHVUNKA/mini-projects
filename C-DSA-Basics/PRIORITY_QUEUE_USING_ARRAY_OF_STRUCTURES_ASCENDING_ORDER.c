#include<stdio.h>
#include<stdlib.h>

#define max 20

typedef struct qn
{
    int ele;
    int pri;
}q;

typedef struct Q
{
    int r;
    q a[max];
}pq;

pq p1;

int isempty(pq *p)
{
    if(p->r==-1)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

void enqueue(pq *p)
{
    int ele,pri,ir=p->r;
    printf("Enter the element .\n");
    scanf("%d",&ele);
    printf("Enter the priority .\n");
    scanf("%d",&pri);
    if(p->r==max)
    {
        printf("Overflow .\n");
    }
    else if(!(isempty(p)))
    {
        (p->r)++;
        p->a[p->r].ele=ele;
        p->a[p->r].pri=pri;
    }
    else if(pri<p->a[0].pri)
    {
        for(int i=p->r;i>=0;i--)
        {
            p->a[i+1]=p->a[i];
        }
        p->a[0].ele=ele;
        p->a[0].pri=pri;
        p->r++;
    }
    else if(pri>p->a[p->r].pri)
    {
        p->r++;
        p->a[p->r].ele=ele;
        p->a[p->r].pri=pri;
    }
    else 
    {
        q new;
        new.ele=ele;
        new.pri=pri;
        int i=p->r;
        while((i>=0)&&((new.pri)<(p->a[i].pri)))
        {
            p->a[i+1]=p->a[i];
            i--;
        }
        p->a[++i]=new;
        p->r++;
    }
}

void dequeue(pq *p)
{
    int n=isempty(p);
    int i;
    if(!(n))
    {
        printf("UNDERFLOW .\n");
    }
    else
    {
        q del=p->a[0];
        for(int i=1;i<=p->r;i++)
        {
            p->a[i-1]=p->a[i];
        }
        p->r--;
    }
}

void display(pq *p)
{
    int j=isempty(p);
    if(j)
    {
        for(int i=0;i<=p->r;i++)
        {
            printf("(ele : %d , pri : %d)->",p->a[i].ele,p->a[i].pri);
        }
        printf("\n");
    }
    else
    {
        printf("UNDERFLOW .\n");
    }
}

void init(pq *p)
{
    p->r=-1;
}

int main()
{
    init(&p1);
    int choice,n=1;
    while(n)
    {
        printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : enqueue(&p1);
                     break;
            case 2 : dequeue(&p1);
                     break;
            case 3 : display(&p1);
                     break;
            case 4 : n=0;
                     break;
            default : printf("Enter a valid choice .\n");
                      break;
        }
    }

    return 1;
}