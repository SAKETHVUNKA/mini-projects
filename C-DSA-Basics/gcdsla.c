#include<stdio.h>
#include<stdlib.h>
int findGCD(int* nums, int numsSize)
{
    int max=nums[0],min=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(max<nums[i])
        {
            max=nums[i];
        }
        if(min>nums[i])
        {
            min=nums[i];
        }
    }
    int r; 
    while(min!=0)
    {
        r=max%min;
        max=min;
        min=r;
    }
    return max;
}
int main() 
{
int a[100000];
int i, count;
scanf("%d", &count);
for (i = 0; i < count; i++)
{
scanf("%d", &a[i]);
}
printf("%d", findGCD(a, count));
return 0;
}