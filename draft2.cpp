/*------------------------------------------------------------------------------
 * @file    DRAFT2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/11 20:10:05
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _DRAFT2_C_

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



/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 5, vector<int>(2, 0));
    string s;
    cin >> s;
    dp[0][0] = 0, dp[0][1] = 0;
    for(int i=1; i<=n; i++)
    {
        if(s[i - 1] == '0')
        {
            dp[i][1] = 0;
            
        }
        else if(s[i - 1] == '1')
        {
            dp[i][0]  = 0;

        }
    }


    return 0;
}
