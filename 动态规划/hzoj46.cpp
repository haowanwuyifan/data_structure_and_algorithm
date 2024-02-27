/*------------------------------------------------------------------------------
 * @file    HZOJ46.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/24 12:15:26
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ46_C_

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
char s[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    scanf("%s", s+1);
    int n = strlen(s);
    for(int l = 1; l<=n; l++)
    {
        for(int i=1; i<=n-1; i++)
        {
            int j = i + l - 1;
            if(s[i] == s[j] && dp[i+1][j-1]==0)
            {
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = l;
                for(int k = i; k<j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
