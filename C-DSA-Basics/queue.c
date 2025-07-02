#include<stdio.h>
#define max 20

typedef struct QUEUE
{
    int a[20];
    int f;
    int r;
}q;
q q1;

void enqueue(int *a,int ele)
{
    if(q1.r==max-1)
    {
        printf("Queue is full .\n");
    }
    else
    {
        a[++(q1.r)]=ele;
    }
}

void dequeue(int *a)
{
    if(q1.f>q1.r)
    {
        printf("The queue is empty .\n");
    }
    else
    {
        printf("%d \n",a[q1.f]);
        for(int i=q1.f;i<q1.r;i++)
        {
            a[i]=a[i+1];
        }
        (q1.r)--;
    }
}

void display(int *a)
{
    if(q1.r==-1)
    {
        printf("Queue is empty .\n");
        return ;
    }
    for(int i=0;i<=q1.r;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    q1.r=-1;
    q1.f=0;
    int n=1,e,ele;
    while(n)
    {
        printf("If you want to enqueue press 1 .\nIf you want to dequeue press 2 .\nIf you want to print the list press 3 .\nIf you want to exit press 4.\n");
        scanf("%d",&e);
        switch(e)
        {
            case 1: printf("enter the element : ");
                    scanf("%d",&ele);
                    enqueue(q1.a,ele);
                    break;
            case 2: dequeue(q1.a);
                    break;
            case 3: display(q1.a);
                    break;
            case 4: n=0;
                    break;
            default :printf("Enter valid option .\n");
                    break;
        }
    }

    return 0;
}