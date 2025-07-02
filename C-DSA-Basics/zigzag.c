#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#define C 3 
// Utility function to print matrix // in zig-zag form
void zigZagMatrix(int arr[][C], int n, int m) 
{
    int i=0,j=0,count=0,max=m*n;
    while(count<max)
    {
        while((i>0)&&(j>0)&&(i<n-1)&&(j<m-1))
        {

        }
    }
}

int main() 
{
    int matrix[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }; 
    zigZagMatrix(matrix, 3, 3); 
    return 0; 
}