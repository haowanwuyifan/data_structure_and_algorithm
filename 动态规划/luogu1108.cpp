/*------------------------------------------------------------------------------
 * @file    LUOGU1108.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/29 18:10:35
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1108_C_

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

#define MAX_N 5000
#define INF 0x7fffffff
int val[MAX_N + 5];
int dp[MAX_N + 5];
int f[MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n, max_len = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", val + i);
    }
    val[0] = INF;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(val[j] <= val[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        for(int j=0; i<i; j++)
        {
            if(val[j] < val[i]) continue;
            if(val[j] > val[i] && dp[i] == dp[j] + 1) f[i] += f[j]; 
            else if(val[j] == val[i] && dp[j] == dp[i]) f[j] = 0;
        }
        max_len = max(max_len, dp[i]);
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(dp[i] == max_len) ans += f[i];
    }
    printf("%d %d\n", max_len, ans);
    return 0;
}
