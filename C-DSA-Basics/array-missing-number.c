#include<stdio.h>
#include<stdlib.h>
void findErrorNums(int* nums, int numsSize)
{
    // int count=0,sum=0;
    // for(int i=0;i<numsSize;i++)
    // {
    //     count++;
    //     sum+=nums[i];
    // }
    // int val=(numsSize*(numsSize+1))/2;
    // int diff=abs(sum-val);
    // for(int i=0;i<numsSize;i++)
    //     {
    //         for(int j=i+1;j<numsSize;j++)
    //         {
    //             if(nums[i]==nums[j])
    //             {
    //                 int c=nums[i];
    //                 nums[0]=c;
    //                 // nums[1]=diff+c;
    //                 nums[1]=j+1;
    //                 printf("%d\n",j);
    //             }
    //         }   
    //     } 
// for(int i=0; i<2; i++)
// {
// printf("%d ", nums[i]);
// }
    // int* count=calloc(numsSize,sizeof(int));
    int count[100000]={0};
    int a=0, b=0;
    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i]] = count[nums[i]] + 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if(count[i] == 2 || count[i] == 0 && i != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
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
findErrorNums(a, count);
return 0;
}