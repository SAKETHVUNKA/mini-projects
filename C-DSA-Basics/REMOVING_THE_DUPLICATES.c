#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num=0;

typedef struct sll
{
    char data;
    struct sll *s;
}s1;

s1 *temp=NULL;
s1 *final=NULL;
s1 *init=NULL;

void display(s1 *init)
{
    printf("Elements :\n");
    s1 *p=final;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->s;
    }
    printf("\n");
}

s1* push(s1 *init)
{
    char a[20],ele;
    printf("Enter the string .\n");
    scanf("%s",&a);
    int i=0;
    while(a[i]!='\0')
    {
        ele=a[i];
        s1* temp=malloc(sizeof(s1));
        temp->data=ele;
        temp->s=init;
        init=temp;
        num++;
        i++;
    }
    return init;
}

s1* remd(s1 *init)
{
    s1 *pointer=init;
    char c;
    while(pointer!=NULL)
    {
        c=pointer->data;
        s1 *intemp=pointer->s;
        pointer->s=final;
        final=pointer;
        int num=0;
        while(intemp!=NULL)
        {
            if(intemp->data!=c)
            {
                s1 *remove=intemp;
                intemp=intemp->s;
                remove->s=temp;
                temp=remove;
            }
            else
            {
                s1 *delete=intemp;
                if(intemp!=NULL)
                {
                intemp=intemp->s;
                init=intemp;
                }
                free(delete);
                delete=NULL;
                num++;
            }
        }
        if(num%2!=0)
        {
            s1 *k=final;
            final=final->s;
            free(k);
            k=NULL;
        }
        while(temp!=NULL)
        {
            s1 *t=temp;
            temp=temp->s;
            t->s=intemp;
            intemp=t;
        }
        pointer=intemp;
    }
    return init;
}

int main()
{
    init=push(init);
    init=remd(init);
    display(init);
    return 0;
}