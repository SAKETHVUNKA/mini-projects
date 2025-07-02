#include <stdio.h>
#define max 5

typedef struct queue
{
    char qu[max];
    int fr;
    int re;
} q1;

q1 q;

void init(q1 *q)
{
    q->fr=max-1;
    q->re=max-1;
}

void enqueue(int ele)
{
    if (((q.re+1)%max)==q.fr) 
        printf("Queue is Full.\n");
    else
        q.re=((q.re)+1)%max;
        q.qu[q.re]=ele;
}

void dequeue()
{
    if (q.fr==q.re)
        printf("Queue is empty.\n");
    else
    {
        q.fr=((q.fr)+1)%max;
        printf("Deleted %d!\n", q.qu[(q.fr)]);
    }
}

void display()
{
    if (q.fr == q.re)
        printf("Queue is empty.\n");
    else
    {
        int j = (q.fr+1)%max;
        while (j!=q.re)        
        {
            printf("%d | ", q.qu[j]);
            j=(j+1)%max;
        }
        printf("%d |",q.qu[j]);
    }
}

int main()
{
    init(&q);
    int choice,x,n=1;
    while(n)
    {
        printf("\n1) Enqueue\n2) Dequeue\n3) Disp-Queue\n4) Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element to be added: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:n=0;
            break;
        default:
            printf("Enter a valid choice.\n");
            break;
        }
    }
    return 0;
}