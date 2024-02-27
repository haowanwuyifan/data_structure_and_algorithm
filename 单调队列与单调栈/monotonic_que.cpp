/*------------------------------------------------------------------------------
 * @file    MONOTONIC_QUE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/31 17:13:33
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _MONOTONIC_QUE_C_

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

void output(vector<int> &arr)
{
    int n = arr.size(), len = 0;
    for(int i=0; i<n; i++)
    {
        len += printf("%3d", i);
    }
    printf("\n");
    for(int i=0; i<len; i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        len += printf("%3d", arr[i]);
    }
    printf("\n");
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    deque<int> q;
    for(int i=0, a; i<n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    output(arr);
    for(int i=0; i<n; i++)
    {
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if(i - q.front() == k) q.pop_front();
        printf("[%d, %d] = arr[%d] %d\n", max(i-k+1, 0), i, q.front(), arr[q.front()]);
    }
    return 0;
}
