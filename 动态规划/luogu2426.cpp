/*------------------------------------------------------------------------------
 * @file    LUOGU2426.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/01 12:08:55
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU2426_C_

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

#define MAX_N 100
int dp[MAX_N + 5];
int x[MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> x[i];
    }
    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + x[i];
        for(int j=0; j<i-1; j++)
        {
            dp[i] = max(dp[i], dp[j] + abs(x[j+1] - x[i]) * (i - j));
        }
    }   
    cout << dp[n] << endl;
    return 0;
}
