#include<stdio.h>
#define max 50

typedef struct PQ
{
    int a[max];
    int n;
}pq;

void init(pq *ppq)
{
    ppq->n=0;
}

void enqueue(pq *ppq)
{
    int i,j,c,p;
    for(i=1;i<(ppq->n);i++)
    {
        c=i;
        p=(c-1)/2;
        int ele=ppq->a[c];
        while((c>0) && (ele<ppq->a[p]))
        {
            ppq->a[c]=ppq->a[p];
            c=p;
            p=(c-1)/2;
        }
        ppq->a[c]=ele;
    }
    for(j=0;j<(ppq->n);j++)
    {
        printf("%d ",ppq->a[j]);
    }
    printf("\n");
}

void sort(pq *ppq)
{
    int i,j,c,p,element;
    for(i=((ppq->n)-1);i>0;i--)
    {
        element=ppq->a[i];
        ppq->a[i]=ppq->a[0];
        p=0;
        if(i==1)
        {
            c=-1;
        }
        else
        {
            c=1;
        }
        if((i>2)&&((ppq->a[2])<(ppq->a[1])))
        {
            c=2;
        }
        while((c>0)&&((ppq->a[c])<element))
        {
            ppq->a[p]=ppq->a[c];
            p=c;
            c=(2*p)+1;
            if((c+1<=i-1)&&((ppq->a[c+1])<(ppq->a[c])))
            {
                c++;
            }
            if(c>(i-1))
            {
                c=-1;
            }
        }
        ppq->a[p]=element;
    }
    for(j=0;j<(ppq->n);j++)
    {
        printf("%d ",ppq->a[j]);
    }
    printf("\n");
}

int main()
{
    pq q;
    init(&q);
    printf("Enter the number of nodes : ");
    scanf("%d",&(q.n));
    for(int j=0;j<(q.n);j++)
    {
        printf("Enter the elements : ");
        scanf("%d",&(q.a[j]));
    }
    enqueue(&q);
    sort(&q);

    return 0;
}
