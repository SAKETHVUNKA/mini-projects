#include<stdio.h>
#define max 50

int main()
{
    int element,n=9,c,p,i,j,a[max];
    //={10,25,369,12,5,143,85,26,987};
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        printf("Enter the elements : ");
        scanf("%d",&a[j]);
    }
    for(i=1;i<n;i++)
    {
        c=i;
        p=(c-1)/2;
        int ele=a[c];
        while((c>0) && (ele>a[p]))
        {
            a[c]=a[p];
            c=p;
            p=(c-1)/2;
        }
        a[c]=ele;
    }
    for(j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
    
    for(int i=n-1;i>0;i--)
    {
        element=a[i];
        a[i]=a[0];
        p=0;
        if(i==1)
        {
            c=-1;
        }
        else
        {
            c=1;
        }
        if((i>2)&&(a[2]>a[1]))
        {
            c=2;
        }
        while((c>0)&&((a[c])>element))
        {
            a[p]=a[c];
            p=c;
            c=(2*p)+1;
            if((c+1<=i-1)&&(a[c+1]>a[c]))
            {
                c++;
            }
            if(c>(i-1))
            {
                c=-1;
            }
        }
        a[p]=element;
    }
    for(j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");

    return 0;
}
//Restriction - it should be a complete binary tree
//parental dominance - min heap and max heap