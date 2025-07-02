// #include<stdio.h>
// #include<stdlib.h>

// void swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }

// int partition(int a[100],int l,int r)
// {
//     int p=a[l];
//     int i=l;
//     int j=r+1;
    
//     while(i<j)
//     {
//         do
//         {
//             j=j-1;
//         }while(p<a[j]);
//         do
//         {
//             i=i+1;
//         }while(p>a[i]);
//         swap(&a[i],&a[j]);
//     }
//     swap(&a[i],&a[j]);
//     swap(&a[l],&a[j]);
//     return j;
// }

// void quicksort(int a[100],int l,int r)
// {
//     if(l<r)
//     {
//         int s=partition(a,l,r);
//         quicksort(a,l,s-1);
//         quicksort(a,s+1,r);
//     }
// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         // a[i]=rand()%50;
//         scanf("%d",a[i]);
//     }
//     quicksort(a,0,n-1);
//     for(int i=0;i<n;i++)
//     {
//         printf("%d ",a[i]);
//     }
// }

#include <stdio.h>

void swap(int *a, int *b)
{
    // *a, *b = *b, *a;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = r + 1;

    while (i < j)
    {
        do
            i = i + 1;
        while (arr[i] < p);

        do
            j = j - 1;
        while (arr[j] > p);

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[i], &arr[j]);
    swap(&arr[l], &arr[j]);

    return j;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int s = partition(arr, l, r);
        quickSort(arr, l, s - 1);
        quickSort(arr, s + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}