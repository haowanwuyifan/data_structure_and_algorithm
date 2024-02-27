/*------------------------------------------------------------------------------
 * @file    HZOJ48.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/23 18:16:56
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ48_C_

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

#define MAX_V 10000
int dp[MAX_V + 5] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    int n, V;
    scanf("%d%d", &n, &V);
    for(int i=1, c, v; i<=n; i++)
    {
        scanf("%d%d", &c, &v);
        for(int j=c; j<=V; j++)
        {
            dp[j] = max(dp[j], dp[j-c] + v);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
