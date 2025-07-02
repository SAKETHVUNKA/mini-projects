/*#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int e;
    struct node* l;
    struct node* r;
};

typedef struct node n;
int k=sizeof(n);

n *insert1(n *start)
{
    int ele;
    printf("Enter the element .\n");
    if(start==NULL)
    {
        n *temp=NULL;
        temp=(n*)malloc(k);
        scanf("%d",&ele);
        temp->e=ele;
        start=temp;
        temp->l=NULL;
        temp->r=NULL;
    }
    else
    {
        n *temp=NULL;
        temp=(n*)malloc(k);
        scanf("%d",&ele);
        temp->e=ele;
        temp->r=start;
        temp->l=NULL;
        start=temp;
        temp->r->l=temp;
    }
    return start;
}

n *insertp(n* start)
{
    int ele,pos,c=0;
    n *temp=NULL;
    temp=(n*)malloc(k);
    printf("ENTER POSITION AND ELEMENT \n");
    scanf("%d %d",&pos,&ele);
    temp->e=ele;
    n *p=start;
    if(pos==-1)
    {
        start=insert1(start);
        return start;
    }
    else if(p==NULL)
    {
        printf("NO elements in the list . so the given element will be inserted at the beginning of the list .\n");
        start=insert1(start);
        return start;
    }
    else if(pos>=0)
    {
        while(p->r!=NULL && c<pos)
        {
            p=p->r;
            c++;
        }
        if(pos>c)
        {
            printf("Invalid position , out of range .\n");
            return start;
        }
        else
        {
        temp->r=p->r;
        p->r=temp;
        if(p->r!=NULL)
        {
        temp->r->l=temp;
        }
        temp->l=p;
        }
    }
    return start;
}

n *inserte(n *start)
{
    int ele;
    printf("Enter the element .\n");
    if(start==NULL)
    {
        n *temp=NULL;
        temp=(n*)malloc(k);
        scanf("%d",&ele);
        temp->e=ele;
        start=temp;
        temp->l=NULL;
        temp->r=NULL;
    }
    else
    {
        n *p=start;
        while(p->r!=NULL)
        {
            p=p->r;
        }
        n *temp=NULL;
        temp=(n*)malloc(k);
        scanf("%d",&ele);
        temp->e=ele;
        p->r=temp;
        temp->r=NULL;
        temp->l=p;
    }
    return start;
}

void dis(n *start)
{
    n *p=start;
    if(p==NULL)
    {
        printf("no elements in the list .");
    }
    else
    {
    while(p!=NULL)
    {
        printf("%d -> ",p->e);
        p=p->r;
    }
    printf("\n");
    }
}

int main()
{
    n *start;
    int ele,c=1;
    start=NULL;
    while(c==1)
    {
    printf("Enter 1 to enter at the beginning . enter 2 to enter at the end . enter 3 to display . enter 4 to enter at given position . enter 5 to exit .\n");
    scanf("%d",&ele);
    switch(ele)
    {
        case 1:start=insert1(start);
        break;
        case 2:start=inserte(start);
        break;
        case 3:dis(start);
        break;
        case 4:start=insertp(start);
        break;
        case 5:c=0;
        break;
        default:printf("enter proper option .\n");
        break;
    }
    }
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *l, *r;
} NODE;

NODE *insertBeg(NODE *start)
{
    printf("\nEnter the element: ");
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &(temp->ele));
    temp->l = NULL;
    temp->r = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->r = start;
        start->l = temp;
        start = temp;
    }
    return start;
}

NODE *insertEnd(NODE *start)
{
    printf("\nEnter the element: ");
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &(temp->ele));
    temp->l = NULL;
    temp->r = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        NODE *p = start;
        while (p->r != NULL)
        {
            p = p->r;
        }
        p->r = temp;
        temp->l = p;
    }
    return start;
}

NODE *insertPos(NODE *start, int pos)
{
    if (pos < 0)
    {
        start = insertBeg(start);
        return start;
    }
    int count = 0;
    printf("\nEnter the element: ");
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &(temp->ele));
    temp->l = NULL;
    temp->r = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        NODE *p = start;
        while (count < pos && p->r != NULL)
        {
            p = p->r;
            count++;
        }
        if (p->r == NULL)
        {
            // start = insertEnd(start);
            /* NODE *p1 = start;
            while (p1->r != NULL)
            {
                p1 = p1->r;
            }
            p1->r = temp;
            temp->l = p1; */
            /*
            p->r = temp;
            temp->l = p;
            */
            temp->r = p->r;
            temp->l = p;
            // temp->r->l = temp; same as else
            p->r = temp;
        }
        else
        {
            temp->r = p->r;
            temp->l = p;
            temp->r->l = temp;
            p->r = temp;
        }
    }
    return start;
}

NODE *deleteBeg(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
    }
    else if (start->r == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        start = start->r;
        free(start->l);
        start->l = NULL;
    }
    return start;
}

NODE *deleteEnd(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!");
    }
    else if (start->r == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        NODE *p = start;
        while (p->r != NULL)
        {
            p = p->r;
        }
        p->l->r = NULL;
        free(p);
    }
    return start;
}

NODE *delKey(NODE *start, int key)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
        return start;
    }
    else
    {
        NODE *p = start;
        while (p->ele != key && p->r != NULL)
        {
            p = p->r;
        }
        if(p->r == NULL)
        {
            if(p->ele==key)
            {
                p->l->r=NULL;
                free(p);
                p=NULL;
            }
            else
            {
                printf("Element not found!");
            }
        }
        else if (p == start && start->r == NULL)
        {
            free(p);
            start = NULL;
        }
        else if (p == start && start->r != NULL)
        {
            start = start->r;
            free(p);
            start->l = NULL;
        }
        else
        {
            (p->l)->r = p->r;
            if (p->r != NULL)
            {
                p->r->l = p->l;
            }
            free(p);
        }
    }
    return start;
}

void displayDLL(NODE *start)
{
    if (start == NULL)
    {
        printf("List is Empty!\n");
        // return; You used else ma niqqa
    }
    else
    {
        NODE *p = start;
        printf("\n");
        while (p != NULL)
        {
            printf("%d->", p->ele);
            p = p->r;
        }
        printf("\n");
    }
}

int main()
{
    NODE *start = NULL;
    int choice, pos, key;
    do
    {
        printf("\n1. Beginning\n2. End\n3. Position\n4. Delete Beginning\n5. Delete End\n6. Delete Key\n7. Display\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = insertBeg(start);
            break;
        case 2:
            start = insertEnd(start);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);
            start = insertPos(start, pos);
            break;
        case 4:
            start = deleteBeg(start);
            break;
        case 5:
            start = deleteEnd(start);
            break;
        case 6:
            printf("Enter the key: ");
            scanf("%d", &key);
            start = delKey(start, key);
            break;
        case 7:
            displayDLL(start);
            break;
        default:
            break;
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}