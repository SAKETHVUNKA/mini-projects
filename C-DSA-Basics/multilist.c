#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int col;
    int ele;
    struct node *next;
}NODE;

typedef struct list
{
    struct list *down;
    NODE *head,*tail;
}LIST;

void initlist(LIST **p1)
{
    *p1==NULL;
}

void createlist(LIST **p1)
{
    int choice,row=0;
    LIST *p=*p1;
    do
    {
    LIST *temp=(LIST*)malloc(sizeof(LIST));
    temp->down=NULL;
    temp->head=NULL;
    temp->tail=NULL;
    if(*p1==NULL)
    {
        *p1=temp;
        p=temp;
    }
    else
    {
        p->down=temp;
        p=temp;
    }
    p=*p1;
    printf("\n Do you want to enter another row ?\n");
    scanf("%d",&choice);
    } while (choice);

}

void displaylist(LIST **p1)
{
    LIST *p=*p1;
    NODE *q;
    int row=0;
    while(p!=NULL)
    {
        q=p->head;
        while(q!=NULL)
        {
            printf("row = %d , value = %d ",row,q->col,q->ele);
            q=q->next;
        }
        p=p->down;
        row++;
        printf("\n");
    }
}

int main()
{
    LIST *p1;
    initlist(&p1);
    createlist(&p1);
    displaylist(&p1);

    return 0;
}