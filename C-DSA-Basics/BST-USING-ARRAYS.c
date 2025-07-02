//parent -> p then left-child -> 2p+1 and right-child ->2p+2
#include<stdio.h>

#define max 10

typedef struct BST
{
    int ele;
    int flag;    
}bst;

void init(bst b[])
{
    for(int i=0;i<max;i++)
    {
        b[i].flag=0;
    }
}

void insert(bst b[])
{
    printf("Enter the root node element : \n");
    int ele,n=0;
    scanf("%d",&ele);
    b[0].ele=ele;
    b[0].flag=1;
    printf("Do you want to enter new node ?.\nPress 1 to insert a value.\nPress 0 to stop inserting.\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the value to inserted : ");
        scanf("%d",&ele);
        int p=0;
        while((p<max)&&(b[p].flag))
        {
            if(ele>b[p].ele)
            {
                p=(2*p)+2;
            }
            else
            {
                p=(2*p)+1;
            }
        }
        b[p].ele=ele;
        b[p].flag=1;
        printf("Do you want to enter new node ?.\nPress 1 to insert a value.\nPress 0 to stop inserting.\n");
        scanf("%d",&n);
    }
    
}

void display(bst b[])
{
    for(int i=0;i<max;i++)
    {
        if(b[i].flag==1)
        {
            printf(" %d ",b[i].ele);
        }
    }
    printf("\n");
}

void delete(bst b[])
{
    int eled,k=0;
    printf("Element to be deleted : ");
    scanf("%d",&eled);
    for(int i=0;i<max;i++)
    {
        if(b[i].flag==1)
        {
            if(b[i].ele==eled)
            {
                b[i].ele=0;
                b[i].flag=0;
                k=1;
            }
        }
    }
    if(k==1)
    {
        printf("Element deleted .\n");
    }
    else
    {
        printf("Element not found .\n");
    }
}

int main()
{
    bst b[max];
    init(b);
    int ch,n=1;
    while(n)
    {
        printf("1) Insert\n2) Display\n3) Delete.\n4) Exit.\nEnter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insert(b);
                break;
        case 2: display(b);
                break;
        case 3: delete(b);
                break;
        case 4: n=0;
                break; 
        default:printf("Enter valid option .\n");
                break;
        }
    }
    return 0;
}