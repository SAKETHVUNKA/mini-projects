#include<stdio.h>
#include<stdlib.h>

struct N
{
    int ele;
    struct N *next,*prev;
};

typedef struct N node;

node *l1=NULL,*l2=NULL,*l3=NULL;

node* insertatbeg(node* start,int data)
{
    if(start==NULL)
    {
        node* temp=malloc(sizeof(node));
        temp->ele=data;
        start=temp;
        temp->prev=NULL;
        temp->next=NULL;
        return start;
    }
    else
    {
        node* t=start;
        node* temp=malloc(sizeof(node));
        temp->prev=NULL;
        temp->next=NULL;
        temp->ele=data;
        while((t->next!=NULL) && (temp->ele>t->ele))
        {
            t=t->next;
        }
        if (t->next == NULL)
        {
            if (t->ele < temp->ele)
            {
                t->next = temp;
                temp->prev = t;
            }
            else if (t == start)
            {
                temp->next = t;
                t->prev = temp;
                start = temp;
            }
            else
            {
                temp->next = t;
                temp->prev = t->prev;
                t->prev->next = temp;
                t->prev = temp;
            }
        }
        else if (t == start)
        {
            temp->next = t;
            t->prev = temp;
            start = temp;
        }
        else
        {
            temp->next = t;
            temp->prev = t->prev;
            t->prev->next = temp;
            t->prev = temp;
        }
    }
    return start;
}

node* merge(node* t1,node *t2)
{
    node *start=l3;
    node *k1=t1;
    node *k2=t2;
    while(k1!=NULL)
    {
        start=insertatbeg(start,k1->ele);
        k1=k1->next;
    }
    while(k2!=NULL)
    {
        start=insertatbeg(start,k2->ele);
        k2=k2->next;
    }
    return start;
}

void display(node* start)
{
    if(start==NULL)
    {
        printf("the linked list is empty .\n");
    }
    else
    {
        node* temp=start;
        while(temp!=NULL)
        {
            printf("%d <-> ",temp->ele);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ele,c=1;
    while(c==1)
    {
    printf("Enter 1 to add to 1st list  . enter 2 to add to 2nd list . enter 3 to merge . enter 4 to display . enter 5 to exit .\n");
    scanf("%d",&ele);
    switch(ele)
    {
        case 1: scanf("%d",&ele);
                l1=insertatbeg(l1,ele);
        break;
        case 2: scanf("%d",&ele);
                l2=insertatbeg(l2,ele);
        break;
        case 3:l3=merge(l1,l2);
        break;
        case 4:display(l3);
               display(l2);
               display(l1);
        break;
        case 5:c=0;
        break;
        default:printf("enter proper option .\n");
        break;
    }
    }

    return 0;
}