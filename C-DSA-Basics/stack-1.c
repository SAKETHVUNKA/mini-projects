#include<stdio.h>
#include<stdlib.h>

int top=-1,max,n;

void push(int *a)
{
    if(top==max-1)
    {
        printf("The stack is full .\n");
    }
    else
    {
        int ele;
        top++;
        printf("Enter the element to be pushed .\n");
        scanf("%d",&ele);
        a[top]=ele;
    }
}

void pop(int *a)
{
    if(top==-1)
    {
        printf("The stack is empty .\n");
    }
    else
    {
        printf("%d\n",a[top]);
        top--;
    }
}

void search(int *a)
{
    if(top==-1)
    {
        printf("The stack is empty .\n");
    }
    else
    {
        int p=top,key;
        printf("Enter the key to be searched .\n");
        scanf("%d",&key);
        while(p!=-1 && a[p]!=key)
        {
            p--;
        }
        int pos=p;
        if(pos==-1)
        {
            printf("Element not found .\n");        
        }
        else
        {
            printf("Element found at position : %d\n",(pos+1));
        }
    }
}

void display(int *a)
{
    for(int i=top;i>-1;i--)
    {
        printf("%d\n",a[i]);
    }
}

int main()
{
    printf("enter the max size of the stack .\n");
    scanf("%d",&max);
    int s[max];
    do
    {
    x : printf("If you want to push an element press 1 .\nIf you want to pop an element press 2 .\nIf you want to search an element press 3 .\nIf you want to peek the stack press 4 .\nIf you want to display the comntents of the stack press 5 .\nIf you want to exit press 0 .\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:push(s);
            break;
            case 2:pop(s);
            break;
            case 3:search(s);
            break;
            case 4:if(top==-1)
                    {
                        printf("Stack is empty .\n");
                    }
                   else
                    {
                        printf("Top : %d \n",s[top]);
                    } 
            break;
            case 5:display(s);
            break;
            case 0: exit(0);
            default : printf("Choose a value from given list .\n");goto x;
            break;
        } 
    } while (1);
    return 0;
}