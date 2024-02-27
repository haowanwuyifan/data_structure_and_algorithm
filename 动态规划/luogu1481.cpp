/*------------------------------------------------------------------------------
 * @file    LUOGU1481.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/30 11:54:12
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1481_C_

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

#define MAX_N 2000
string word[MAX_N + 5];
int dp[MAX_N + 5];

bool is_prefix(int j, int i)
{
    if(word[j].size() >= word[i].size()) return false;
    for(int k=0; word[j][k]; k++)
    {
        if(word[j][k] - word[i][k]) return false;
    }
    return true;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> word[i];
    }
    for(int i=0; i<n; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(is_prefix(j, i))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
