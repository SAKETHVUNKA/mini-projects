#include<stdio.h>
#include<stdlib.h>

void insert(int size,int *a,int n)
{
    int mod=n%size;    
    int c=mod+1;
    if(a[mod]==-1)
    {
        a[mod]=n;
    }
    else
    {
        while(c!=mod)
        {
            if(a[c]==-1)
            {
                a[c]=n;
                break;
            }
            else
            {
                c=(c+1)%size;
            }
        }
        if(c==mod)
        {
            printf("Hash Table is full .\n");
        }
    }
}

void search(int size,int a[size],int n)
{
    int mod=n%size;
    int c=mod+1;
    if(a[mod]==n)
    {
        printf("The position of the given element is : %d .\n",mod);
    }
    else
    {
        while(c!=mod)
        {
            if(a[c]==n)
            {
                printf("The position of the given element is : %d .\n",c);
                break;
            }
            else
            {
                c=(c+1)%size;
            }
        }
    }
    if(c==mod)
    {
        printf("Element is not present in the hash table .\n");
    }
}

void delete(int size,int *a,int n)
{
    int mod=n%size;
    int c=mod+1;
    if(a[mod]==n)
    {
        a[mod]=-1;
        printf("The %d element is deleted .\n.",n);
    }
    else
    {
        while(c!=mod)
        {
            if(a[c]==n)
            {
                a[c]=-1;
                printf("The %d element is deleted .\n.",n);
                break;
            }
            else
            {
                c=(c+1)%size;
            }
        }
    }
    if(c==mod)
    {
        printf("Element is not present in the hash table .\n");
    }
}

void display(int size,int a[size])
{
    for(int i=0;i<size;i++)
    {
        if(a[i]!=-1)
            printf("%d \n",a[i]);
        else
            printf("\n");
    }
}

int main()
{
    int size,m=1;
    printf("Enter the size of the hash table : ");
    scanf("%d",&size);
    int a[size];
    int c=0;
    for(int i=0;i<size;i++)
    {
        a[i]=-1;
    }
    while(m)
    {
        int choice,ele;
        printf("Select your choice ->\n1)Enter 1 to Insert .\n2)Enter 2 to display .\n3)Enter 3 to delete .\n4)Enter 4 to Search .\n5)Enter 5 to exit .");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted .\n");
                    scanf("%d",&ele);
                    insert(size,a,ele);
                    break;
            case 2: display(size,a);
                    break;
            case 3: printf("Enter the element to be deleted .\n");
                    scanf("%d",&ele);
                    delete(size,a,ele);
                    break;
            case 4: printf("Enter the element to be searched .\n");
                    scanf("%d",&ele);
                    search(size,a,ele);
                    break;
            case 5: m=0;
                    break;
            default:printf("Enter valid choice .\n");
                    break;
        }
    }
    printf("The final hash table -> .\n");
    display(size,a);

    return 0;
}