/*------------------------------------------------------------------------------
 * @file    HZOJ47-1.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/23 17:25:29
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ47-1_C_

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

#define MAX_N 10
#define MAX_V 10000
int dp[MAX_N + 5] = {0};



/*----------------------------------------------------------------------------*/
int main()
{
    int V, n;
    scanf("%d%d", &V, &n);
    for(int i=1, v, w; i<n; i++)
    {
        scanf("%d%d", &v, &w);
        for(int j=V; j>=v; j--)
        {
            dp[j] = max(dp[j], dp[j-v] + w);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
