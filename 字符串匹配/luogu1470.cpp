/*------------------------------------------------------------------------------
 * @file    LUOGU1470.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/10 16:42:43
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1470_C_

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

#define MAX_N 200000
int node[MAX_N + 5][26];
int val[MAX_N + 5], dep[MAX_N + 5];
int cnt = 1, root = 1;
int dp[MAX_N + 5];

void insert(string &s)
{
    int p = root;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'A';
        if(node[p][ind] == 0) 
        {
            node[p][ind] = ++cnt;
            dep[cnt] = dep[p] + 1;
        }
        p = node[p][ind];
    }
    val[p] += 1;
    return ;
}

void mark(string &s, int pos)
{
    int p = root;
    for(int i=pos; s[i]; i++)
    {
        int ind = s[i] - 'A';
        p = node[p][ind];
        if(p == 0) break;
        if(val[p]) dp[pos + dep[p]] = 1;
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    string s = "", t;
    while(cin >> s)
    {
        if(s == ".") break;
        insert(s);
    }
    s = "";
    while(cin >> t) s += t;
    dp[0] = 1;
    int ans = 0;
    for(int i=0; s[i]; i++)
    {
        if(dp[0] == 0) continue;
        ans = i;
        mark(s, i);
    }
    if(dp[s.size()]) ans = s.size();
    cout << ans << endl;
    return 0;
}
