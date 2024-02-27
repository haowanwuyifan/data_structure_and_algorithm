/*------------------------------------------------------------------------------
 * @file    HZOJ50_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/25 18:06:02
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ50_2_C_

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
#define MAX_K 1000
int dp[MAX_N + 5][MAX_K + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if(n == 1)
    {
        printf("%lld\n", m);
        return 0;
    }
    for(int i=1; i<=MAX_K; i++) dp[1][i] = i;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=MAX_K; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1;
            if(dp[i][j] > m) break;
        }
    }
    int k = 1;
    while(dp[n][k] < m) k += 1;
    printf("%d\n", k);
    return 0;
}
