#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node* link;
};
typedef struct node n;

/*IF WE USE GLOBAL AVRIABLES THEN 
IT'S NOT REQUIRE A RETURN START POINTER IF WE HAVEN'T PASSED THE POINTER AS AN ARGUMENT IN FUNCTION CALL .
IT'S REQUIRED TO RETUEN THE START POINTER IF WE HAVE PASSED THE POINTER AS AN ARGUMENT IN FUNCTION CALL . */

n *display(n *start)
{
    printf("List elements .\n");
    if(start==NULL)
    {
        printf("List is empty .\n");
    }
    n* p=start;
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->link;
    }
    printf("\n");
}    

n *create_list(n *start,int n1)
{
    n *temp;
    for(int i=0;i<n1;i++)
    {
        temp=(n *)malloc(sizeof(n));
        printf("enter %d element .\n",i);
        scanf("%d",&(temp->data));
        temp->link=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            temp->link=start;
            start=temp;
        }
    }

    return start;
}

n* concat(n* s1,n* s2)
{
    if(s1==NULL)
    {
        return s2;
    }
    else if(s2==NULL)
    {
        return s1;
    }
    else
    {
        n* p1=s1;
        while(p1->link!=NULL)
        {
            p1=p1->link;
        }
        p1->link=s2;
        return s1;
    }
}

int main()
{
    int n1,n2;
    printf("Enter the number of elements in 1st and 2nd linked list .\n");
    scanf("%d %d",&n1,&n2);
    printf("Enter list 1 .\n");
    n* start1=NULL;
    n* start2=NULL;
    start1=create_list(start1,n1);
    start2=create_list(start2,n2);
    start1=concat(start1,start2);
    printf("the concatenated list is :\n");
    display(start1);
    return 0;
}

