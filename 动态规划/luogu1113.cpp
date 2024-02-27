/*------------------------------------------------------------------------------
 * @file    LUOGU1113.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/30 11:15:47
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1113_C_

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

#define MAX_N 10000
int dp[MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n; 
    cin >> n;
    int ans = 0;
    for(int i=1, t, j; i<=n; i++)
    {
        cin >> t >> t;
        dp[i] = t;
        while(cin >> j)
        {
            if(j == 0) break;
            dp[i] = max(dp[j] + j, dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
