#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{   
    for(int j=0;j<=(log(heap->size)/log(2));j++)
    {
        int n=(int)pow(2,j);
        int m=n-2;
        for(int i=heap->size-1;i>m;i--)
        {
            int ele=heap->arr[i];
            int c=i;
            int p=(c-1)/2;
            if((c%2)==0)
            {
                if(((c-1)>m)&&(heap->arr[c-1]<heap->arr[c]))
                {
                    c=c-1;
                }
            }
            else if((c%2)==1)
            {
                if(((c+1)<heap->size)&&(heap->arr[c+1]<heap->arr[c]))
                {
                    c=c+1;
                }
            }
            while((c>m)&&(heap->arr[c]<heap->arr[p]))
            {
                if(c%2==0)
                {
                    if(((c-1)>m)&&(heap->arr[c-1]<heap->arr[c]))
                    {
                        c=c-1;
                    }
                }
                else if((c%2)==1)
                {
                    if(((c+1)<heap->size)&&(heap->arr[c+1]<heap->arr[c]))
                    {
                        c=c+1;
                    }
                }
                int element=heap->arr[c];
                heap->arr[c]=heap->arr[p];
                heap->arr[p]=element;
                c=p;
                p=(c-1)/2;
            }
        }
    }
}

void print_minheap(MinHeap* heap) 
{
    for(int i=0;i<heap->size;i++)
    {
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}