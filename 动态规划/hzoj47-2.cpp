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
int v[MAX_N + 5], w[MAX_N + 5];
int dp[2][MAX_N + 5] = {0};



/*----------------------------------------------------------------------------*/
int main()
{
    int V, n;
    scanf("%d%d", &V, &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", v + i, w + i);
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=V; j++)
        {
            int ind = i % 2, rind = (i - 1) % 2;
            dp[ind][j] = dp[rind][j];
            if(j < w[i]) continue;
            dp[ind][j] = max(dp[ind][j], dp[rind][j-v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[n % 2][V]);
    return 0;
}
