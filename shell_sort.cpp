#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "test.h"

void ungarded_insert_sort(int *arr, int l, int r, int step)
{
    int ind = l;
    for(int i=l+step; i<r; i+=step)
    {
        if(arr[i] < arr[ind]) ind = i;
    }
    while(ind > l)
    {
        swap(arr[ind], arr[ind - step]);
        ind -= step;
    }
    for(int i=l+2*step; i<r; i+=step)
    {
        int j = i;
        while(arr[j] < arr[j-step])
        {
            swap(arr[j], arr[j-step]);
            j -= step;
        }
    }
    return ;
}

void shell_sort(int *arr, int l, int r)
{
    int k = 2, n = r - l, step;
    do
    {
        step = n / k == 0 ? 1 : n / k;
        for(int i=l, I=l+step; i<I; i++)
        {
            ungarded_insert_sort(arr, i, r, step);
        }
        k *= 2;
    }while(step != 1);
}

void shell_sort_hibbard(int *arr, int l, int r)
{
    int step = 1, n = r - l;
    while(step*2 + 1 <= n / 2) step = step * 2 + 1;
    do{
        for(int i=l, I=step+l; i<I; i++)
        {
            ungarded_insert_sort(arr, i, r, step);
        }
        step /= 2;
    }while(step > 1);
    return ;
}

int main()
{
    int *arr = getRandData(BIG_DATA_N);
    TEST(shell_sort, arr, BIG_DATA_N);
    TEST(shell_sort_hibbard, arr, BIG_DATA_N);
    return 0;
}