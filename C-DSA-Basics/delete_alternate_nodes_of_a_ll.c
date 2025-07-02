#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *p)
{
    if((p)==NULL)
      printf("list is empty");
    else
    {
        while(p!=NULL)
        {
            printf("%d-",p->data);
            p=p->next;
        }
    }
}

struct node* delete_alt(struct node **p)
{
    int i=1;
    struct node *prev,*pres;
    prev=NULL;
    pres=(*p);
    if(pres==NULL)
    {
        printf("List is empty\n");
        return (*p);
    }
    else if(pres->next==NULL)
    {
        free(pres);
        pres=NULL;
        return (*p);
    }
    else
    {
        while(pres->next!=NULL)
        {
            prev=pres->next;
            pres=pres->next->next;
            free(pres);
            i++; 
        }
        if(i%2!=0 && pres->next==NULL)
        {
            pres=NULL;
            free(pres);
        } 
        else if(i%2==0 && pres->next==NULL)
        {
            printf("done\n");
            return (*p);
        }
    }   
}

struct node* insert_beg(struct node **p,int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(*p==NULL)
         *p=temp;
    else
    {
        temp->next=*p;
        *p=temp;
    }
    return (*p);
}
int main()
{
    struct node *first;
    first=NULL;
    while(1)
    {
        int x,ch;
        display(first);
        printf("\n1:Insert at the beginning\n2:Delete alternatively\n");
        printf("Enter the value of ch\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value of x\n");
                   scanf("%d",&x);
                   first=insert_beg(&first,x);
                   break;

            case 2:printf("Deleting alternatively\n");
                   first=delete_alt(&first);
                   display(first);
                   break;
        }
    }
}