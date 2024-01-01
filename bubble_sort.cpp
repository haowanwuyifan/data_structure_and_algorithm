#include<stdio.h>
#include<stdlib.h>
#include "test.h"

void bubble_sort(int *arr, int l, int r)
{
    for(int i=r-1, I=l+1, cnt; i>=I; i--)
    {
        cnt = 0;
        for(int j=0; i<i; j++)
        {
            if(arr[j] <= arr[j+1]) continue; 
            swap(arr[i], arr[j+1]);
            cnt += 1;
        }
        if(cnt == 0) break;
    }
    return ;
}

int main()
{
    int *arr = getRandData(SMALL_DATA_N);
    TEST(bubble_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}