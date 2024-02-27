/*------------------------------------------------------------------------------
 * @file    HZOJ44.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/24 11:13:50
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ44_C_

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
#include <ctype.h>
#include <vector>

using namespace std;

#define MAX_N 1000000
int val[MAX_N + 5];
int dp[MAX_N + 5] = {0};
int pre[MAX_N + 5] = {0};

 /*----------------------------------------------------------------------------*/

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", val);
    }
    val[0] = INT32_MIN;
    int ans = 0, ind = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(val[j] >= val[i]) continue;
            if(dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if(dp[i] > ans)
        {
            ans = dp[i];
            ind = i;
        }
    }
    printf("%d\n", ans);
    while(ind)
    {
        printf("%d(%d)->", ind, val[ind]);
        ind = pre[ind];
    }
    printf("\n");
    return 0;
}
