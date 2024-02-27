/*------------------------------------------------------------------------------
 * @file    HZOJ45.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/24 11:37:19
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ45_C_

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
#include <cstring>
#include <vector>

using namespace std;

#define MAX_N 1000
char s1[MAX_N + 5], s2[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1), m = strlen(s2);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[j][j-1]);
            if(s1[i] == s2[j])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
