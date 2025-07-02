#include<stdio.h>
void main()
{
int a,b,c,d,e,f,g,h;
scanf("%d",&a);
b=a;
for(c=0;c<=b;c++)
{
	for(d=0;d<((2*a)-1);d++)
	{
		if(d>((a-c)-2) && d<((a+c)))
		{
		if(c%2==0 && d%2==0)
        printf("*");
        else if(c%2==0 && d%2!=0)
        printf(" ");
 	    else if(c%2!=0&& d%2!=0)
        printf("*");
        else if(c%2!=0 && d%2==0)
        printf(" ");
        else
        printf(" ");
		}
		else
			printf(" ");
	}
	printf("\n");
}
}