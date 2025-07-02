#include<stdio.h>

int gcdmod(int m,int n)
{
    int count=0,r; 
    while(n!=0)
    {
        count++;
        r=m%n;
        m=n;
        n=r;
    }
    printf("Count mod : %d .\n",count);
    return m;
}

int gcdsub(int m,int n)
{
    int count=0,r; 
    while(n!=m)
    {
        count++;
        if(m>n)
        {
            m=m-n;
        }
        else
        {
            n=n-m;
        }
    }
    printf("Count sub : %d .\n",count);
    return m;
}

int main()
{
    printf("Enter the numbers : \n");
    int a,b,c1,c2;
    scanf("%d %d",&a,&b);
    c1=gcdmod(a,b);
    c2=gcdsub(a,b);
    printf("GCD is : %d , %d .\n",c1,c2);

    return 0;
}