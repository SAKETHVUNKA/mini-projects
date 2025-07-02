#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *link;
} NODE;

void displayList(NODE *start)
{
    if (start == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    else
    {
        printf("\nList Elements:\n");
        NODE *p = start;
        printf("%d->", p->ele);
        while (p->link != start)
        {
            p = p->link;
            printf("%d->", p->ele);
        }
        printf("start\n");
    }
}

NODE *insertBeg(NODE *start)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter the element: ");
    scanf("%d", &(temp->ele));
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
        temp->link = start;
        // or start->link=start;
    }
    else
    {
        NODE *p = start;
        while (p->link != start)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = start;
        start = temp;
    }
    return start;
}

NODE *insertEnd(NODE *start)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter the element: ");
    scanf("%d", &(temp->ele));
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
        temp->link = start;
        // or start->link=start;
    }
    else
    {
        NODE *p = start;
        while (p->link != start)
        {
            p = p->link;
        }
        // p->link = temp;
        // temp->link = start;
        // or
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

NODE *insertPos(NODE *start, int pos)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter the element: ");
    scanf("%d", &(temp->ele));
    temp->link = NULL;
    int count = 0;
    if (start == NULL)
    {
        start = temp;
        temp->link = start;
        // or start->link=start;
    }
    else if (pos < 0)
    {
        start = insertBeg(start);
    }
    else
    {
        NODE *p = start;
        while ((count < pos) && (p->link != start))
        {
            p = p->link;
            count++;
        }
        // p->link = temp;
        // temp->link = start;
        // or
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

NODE *deleteBeg(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
    }
    else if (start->link == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        NODE *p = start;
        while (p->link != start)
        {
            p = p->link;
        }
        start = start->link;
        free(p->link);
        p->link = start;
        // or
        //  p->link=start->link;
        //  free(start);
        //  start=p->link;
    }
    return start;
}

NODE *deleteEnd(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
    }
    else if (start->link == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        NODE *p = start;
        while (p->link->link != start)
        {
            p = p->link;
        }
        free(p->link);
        // or remove else if and do if else here
        p->link = start;
    }
    return start;
}

NODE *deleteKey(NODE *start, int key)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NODE *p = start;
        if (p->ele == key)
        {
            start = deleteBeg(start);
        }
        else
        {
            while (p->link != start && p->link->ele != key)
            {
                p = p->link;
            }
            if (p->link == start && p->ele == key)
            {
                start = deleteEnd(start);
            }
            else if (p->link->ele == key)
            {
                NODE *n = p->link->link;
                free(p->link);
                p->link = n;
            }
            else
            {
                printf("Element not found!\n");
            }
        }
    }
    return start;
}

NODE *deleteAll(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        if (start->link == start)
        {
            start = deleteBeg(start);
        }
        else
        {
            NODE *p = start;
            NODE *befp = NULL;
            while (p->link != start)
            {
                befp = p;
                p = p->link;
                free(befp);
            }
            start = NULL;
        }
    }
    return start;
}

int main()
{
    NODE *start = NULL;
    int choice,pos,key,n=1;
    while(n)
    {
        printf("\n1) Beginning\n2) End\n3) Position\n4) Delete Beginning\n5) Delete End\n6) Delete Key\n7) Delete All\n8) Display\n9) Exit\n\nEnter the choice:");
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
            start = deleteKey(start, key);
            break;
        case 7:
            start = deleteAll(start);
            break;
        case 8:
            displayList(start);
            break;
        case 9:n=0;
            break;
        default:
            break;
        }
    }
    return 0;
}