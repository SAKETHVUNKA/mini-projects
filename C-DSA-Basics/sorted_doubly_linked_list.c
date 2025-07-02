#include<stdio.h>
#include<stdlib.h>

struct N
{
    int ele;
    struct N *next,*prev;
};

typedef struct N node;

node* insertatbeg(node* start)
{
    if(start==NULL)
    {
        node* temp=malloc(sizeof(node));
        int data;
        scanf("%d",&data);
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
        int data;
        scanf("%d",&data);
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
    node* start=NULL;
    int ele,c=1;
    while(c==1)
    {
    printf("Enter 1 to enter at the beginning . enter 2 to display . enter 3 to exit .\n");
    scanf("%d",&ele);
    switch(ele)
    {
        case 1:start=insertatbeg(start);
        break;
        case 2:display(start);
        break;
        case 3:c=0;
        break;
        default:printf("enter proper option .\n");
        break;
    }
    }

    return 0;
}