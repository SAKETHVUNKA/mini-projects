#include<stdio.h>
#include<stdlib.h>

int num=0;

typedef struct sll
{
    int data;
    struct sll *s;
}s1;

s1* push(s1 *start)
{
    int ele;
    printf("Enter the element .\n");
    scanf("%d",&ele);
    s1* temp=malloc(sizeof(s1));
    temp->data=ele;
    temp->s=start;
    start=temp;
    num++;
    return start;
}

s1* pop(s1 *start)
{
    if(start==NULL)
    {
        printf("The stack is empty .\n");
        return start;
    }
    else
    {
        s1 *temp;
        temp=start;
        start=start->s;
        free(temp);
        temp=NULL;
        num--;
        return start;
    }
}

void peek(s1 *start)
{
    s1 *p=start;
    if(p==NULL)
    {
        printf("The stack is empty .\n");
    }
    else
    {
        while(p->s!=NULL)
        {
            p=p->s;
        }
        printf("%d \n",p->data);
    }
}

void search(s1 *start)
{
    if(start==NULL)
    {
        printf("The stack is empty .\n");
    }
    else
    {
        int key,pos=-1;
        s1 *p=start;
        printf("Enter the key to be searched .\n");
        scanf("%d",&key);
        while(p!=NULL && p->data!=key)
        {
            p=p->s;
            pos++;
        }
        if(p==NULL)
        {
            printf("Element not found .\n");        
        }
        else
        {
            printf("Element found at position : %d\n",(num-pos-1));
        }
    }
}

void display(s1 *start)
{
    if(start==NULL)
    {
       printf("The stack is empty .\n");
        return;
    }
    printf("Elements :\n");
    s1 *p=start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->s;
    }
}

int main()
{
    s1 *start=NULL;
    do
    {
        int n;
    x : printf("If you want to push an element press 1 .\nIf you want to pop an element press 2 .\nIf you want to search an element press 3 .\nIf you want to peek the stack press 4 .\nIf you want to display the comntents of the stack press 5 .\nIf you want to exit press 0 .\n ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:start=push(start);
            break;
            case 2:start=pop(start);
            break;
            case 3:search(start);
            break;
            case 4:peek(start); 
            break;
            case 5:display(start);
            break;
            case 0:exit(0);
            break;            
            default : printf("Choose a value from given list .\n");goto x;
            break;
        } 
    } while (1);
    return 0;
}