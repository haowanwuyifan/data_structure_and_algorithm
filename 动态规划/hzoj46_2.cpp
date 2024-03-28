/*------------------------------------------------------------------------------
 * @file    HZOJ46_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/26 12:15:20
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ46_2_C_

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

#define MAX_N 500000
int dp[MAX_N + 5];
char s[MAX_N + 5];
vector<int> g[MAX_N + 5];

int is_palindrome(int i, int j)
{
    while(i < j)
    {
        if(s[i] != s[j]) return 0;
        i++, j--;
    }
    return 1;
}

void extract(int i, int j)
{
    while(s[i] == s[j])
    {
        g[i].push_back(j-1);
        i++, j--;
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    cin >> (s + 1);    
    int len = strlen(s);
    dp[0] = -1;
    for(int i=1; i<=len; i++)
    {
        extract(i, i);
        extract(i, i + 1);
    }
    for(int i=1; s[i]; i++)
    {
        dp[i] = i;
        for(auto j : g[i])
        {
            dp[i] = min(dp[i], dp[j] + 1);
        }

    }
    cout << dp[len] << endl;
    return 0;
}
