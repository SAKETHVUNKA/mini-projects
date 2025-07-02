#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *left, *right;
} NODE;

NODE *insertBeg(NODE *start)
{
    printf("\nEnter the element: ");
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &(temp->ele));
    temp->left = NULL;
    temp->right = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->right = start;
        start->left = temp;
        start = temp;
    }
    return start;
}

NODE *insertEnd(NODE *start)
{
    printf("\nEnter the element: ");
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &(temp->ele));
    temp->left = NULL;
    temp->right = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        NODE *p = start;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
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
    temp->left = NULL;
    temp->right = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        NODE *p = start;
        while (count < pos && p->right != NULL)
        {
            p = p->right;
            count++;
        }
        if (p->right == NULL)
        {
            // start = insertEnd(start);
            /* NODE *p1 = start;
            while (p1->right != NULL)
            {
                p1 = p1->right;
            }
            p1->right = temp;
            temp->left = p1; */
            /*
            p->right = temp;
            temp->left = p;
            */
            temp->right = p->right;
            temp->left = p;
            // temp->right->left = temp; same as else
            p->right = temp;
        }
        else
        {
            temp->right = p->right;
            temp->left = p;
            temp->right->left = temp;
            p->right = temp;
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
    else if (start->right == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        start = start->right;
        free(start->left);
        start->left = NULL;
    }
    return start;
}

NODE *deleteEnd(NODE *start)
{
    if (start == NULL)
    {
        printf("List is empty!");
    }
    else if (start->right == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        NODE *p = start;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->left->right = NULL;
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
        while (p->ele != key && p->right != NULL)
        {
            p = p->right;
        }
        if(p->right == NULL)
        {
            if(p->ele==key)
            {
                p->left->right=NULL;
                free(p);
                p=NULL;
            }
            else
            {
                printf("Element not found!");
            }
        }
        else if (p == start && start->right == NULL)
        {
            free(p);
            start = NULL;
        }
        else if (p == start && start->right != NULL)
        {
            start = start->right;
            free(p);
            start->left = NULL;
        }
        else
        {
            (p->left)->right = p->right;
            if (p->right != NULL)
            {
                p->right->left = p->left;
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
            p = p->right;
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

