#include <stdio.h>
#define max 5

struct queue
{
    char qu[max];
    int fr;
    int re;
} q;

void enqueue(int ele)
{

    if ((q.re == max - 1) && (q.fr == max))
    {
        q.re = -1;
        q.fr = 0;
        q.qu[++(q.re)] = ele;
    }
    else if (q.re == max - 1)
        printf("Queue is Full.\n");
    else
        q.qu[++(q.re)] = ele;
}

void dequeue()
{
    if (q.fr > q.re)
        printf("Queue is empty.\n");
    else
        printf("Deleted %d!\n", q.qu[(q.fr)++]);
}

void displayQu()
{
    if (q.fr > q.re)
        printf("Queue is empty.\n");
    else
    {
        int j = q.fr;
        while (j <= q.re)
        {
            printf("%d | ", q.qu[j++]);
        }
    }
}

int main()
{
    q.fr = 0;
    q.re = -1;
    int choice, x;
    do
    {
        printf("\n1) Enqueue\n2) Dequeue\n3) Disp-Queue\n");
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
            displayQu();
            break;
        default:
            printf("Enter a valid choice.😕\n");
            break;
        }
    } while (1);
    return 0;
}