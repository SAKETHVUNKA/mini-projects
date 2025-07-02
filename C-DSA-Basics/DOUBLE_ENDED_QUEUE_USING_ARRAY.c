#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct queue
{
    int qu[MAX];
    int f, r;
}Q;

void innit(Q **q)
{
    (*q) = (Q *)malloc(sizeof(Q));
    (*q)->f = -1;
    (*q)->r = -1;
}

int isFull(Q **q)
{
    if ((*q)->r == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Q **q)
{
    if ((*q)->f==-1)
        return 1;
    else
        return 0;
}

void enqueueBeg(Q **q)
{
    if (isFull((q)))
    {
        printf("Overflow.\n");
        printf("isfull\n");
    }
    else if (isEmpty((q)))
    {
        ((*q)->f)++;
        ((*q)->r)++;
        printf("Element to be added: ");
        scanf("%d", &(((*q)->qu)[(*q)->r]));
    }
    else
    {
        for (int i = ((*q)->r); i >=((*q)->f); i--)
        {
            ((*q)->qu)[i + 1] = ((*q)->qu)[i];
        }
        printf("Element to be added: ");
        scanf("%d", &(((*q)->qu)[0]));
        ((*q)->r)++;
    }
}

void enqueueEnd(Q **q)
{
    if (isFull((q)))
    {
        printf("Overflow.\n");
    }
    else if (isEmpty((q)))
    {
        ((*q)->f)++;
        ((*q)->r)++;
        printf("Element to be added: ");
        scanf("%d", &(((*q)->qu)[(*q)->r]));
    }
    else
    {
        ((*q)->r)++;
        printf("Element to be added: ");
        scanf("%d", &(((*q)->qu)[(*q)->r]));
    }
}

void dequeueBeg(Q **q)
{
    if (isEmpty((q)))
        printf("Underflow.\n");
    else
    {
        printf("Deleted %d.\n", (((*q)->qu)[(*q)->f]));
        for (int i = ((*q)->f); i < ((*q)->r); i++)
        {
            ((*q)->qu)[i] = ((*q)->qu)[i + 1];
        }
        ((*q)->r)--;
        if((*q)->r==-1)
        {
            (*q)->f=-1;
        }
    }
}

void dequeueEnd(Q **q)
{
    if (isEmpty((q)))
        printf("Underflow.\n");
    else
    {
        printf("Deleted %d.\n", (((*q)->qu)[(*q)->r]));
        ((*q)->r)--;
        if((*q)->r==-1)
        {
            (*q)->f=-1;
        }
    }
}

void displayQueue(Q **q)
{
    if ((*q)->f == -1)
        printf("Queue is empty.\n");
    else
    {
        int j = (*q)->f;
        while (j <= (*q)->r)
        {
            printf("%d | ", (*q)->qu[j++]);
        }
    }
}

int main()
{
    Q *q;
    innit(&q);
    int choice,n;
    while(n)
    {
        printf("\n1)  Enqueue Beginning\n2)  Enqueue End\n3)  Dequeue Beginning\n4)  Dequeue End\n5)  Display Queue\n6)  Exit\n\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: enqueueBeg(&q);
                break;
        case 2: enqueueEnd(&q);
                break;
        case 3: dequeueBeg(&q);
                break;
        case 4: dequeueEnd(&q);
                break;
        case 5: displayQueue(&q);
                break;
        case 6 : n=0;
                 break;
        default : break;
        }
    }
    return 0;
}