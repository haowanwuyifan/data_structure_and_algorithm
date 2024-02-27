/*------------------------------------------------------------------------------
 * @file    HZOJ44_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/26 17:58:15
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ44_2_C_

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

#define MAX_N 1000000
int dp[MAX_N + 5], len[MAX_N + 5];
int a[MAX_N + 5];

int binary_search(int *len, int n, int x)
{
    int head = 0, tail = n, mid;
    while(head < tail)
    {
        mid = (head + tail + 1) >> 1;
        if(len[mid] < x) head = mid;
        else tail = mid - 1;
    }
    return head;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    len[0] = -1;
    for(int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        dp[i] = binary_search(len, ans, a) + 1;
        len[dp[i]] = a;
        if(dp[i] > ans) ans = dp[i];    
    }
    printf("%d\n", ans);
    return 0;
}
