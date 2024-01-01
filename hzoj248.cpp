/*------------------------------------------------------------------------------
 * @file    HZOJ248.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/01 16:44:56
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ248_C_

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define MAX_N 500000
int arr[MAX_N + 5], temp[MAX_N + 5];



int merge_sort(int *arr, int l, int r)
{
    if(r-l <= 1) return 0;
    int mid = (l + r) / 2;
    int a = merge_sort(arr, l, mid);
    int b = merge_sort(arr, mid, r);
    int c = 0, p1 = l, p2 = mid, k = 0;
    while(p1 < mid || p2 < r)
    {
        if(p2 == r || (p1 < mid && arr[p1] <= arr[p2]))
        {
            temp[k++] = arr[p1++];
        }
        else
        {
            temp[k++] = arr[p2++];
            c += (mid - p1);
        }
    }
    for(int i=l; i<r; i++) arr[i] = temp[i-l];
    return a+b+c;
}

void solve(int n)
{
    for(int i=0; i<n; i++) scanf("%d", arr + i);
    printf("%d\n", merge_sort(arr, 0, n));
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        solve(n);
    }
    return 0;
}
