/*------------------------------------------------------------------------------
 * @file    HZOJ50.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/25 17:48:18
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ50_C_

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

#define MAX_N 32
#define MAX_M 100000
int dp[MAX_N + 5][MAX_M + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) dp[1][i] = i;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j] = j;
            for(int k=1; k<=j; k++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i-1][k-1], dp[i][j-k]) + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
