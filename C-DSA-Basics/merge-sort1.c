#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Merge(int B[100],int C[100],int a[100],int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        if(B[i]<C[j])
        {
            a[k]=B[i];
            i++;
        }
        else
        {
            a[k]=C[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        for(int m=j;m<q;m++)
        {
            a[k]=C[m];
            k++;
        }
    }
    else if(j==q)
    {
        for(int m=i;m<p;m++)
        {
            a[k]=B[m];
            k++;
        }
    }
}

void Mergesort(int a[100],int l,int r)
{
    if((r+1)>1)
    {
        int B[100],C[100];
        int semi=l+(r-l)/2;
        for(int i=0;i<=semi;i++)
        {
            B[i]=a[i];
            printf("%d ",B[i]);
        }
        printf("\n");
        for(int i=semi+1;i<=r;i++)
        {
            C[i-semi]=a[i];
            printf("%d ",C[i-semi]);
        }
        printf("\n");
        Mergesort(B,0,semi);
        Mergesort(C,0,semi);
        Merge(B, C, a,semi,r);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
