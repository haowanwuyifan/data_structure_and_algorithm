/*------------------------------------------------------------------------------
 * @file    LUOGU1032.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/07 11:43:54
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1032_C_

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
#define MAX_NUM 100
int trans_cnt = 0, ans = MAX_NUM, ans_k;
string a, b;
string from[10], to[10];
map<string, int> dp;

void dfs(string &now, int step)
{
    if(step > ans_k) return;
    dp[now] = step;
    if(step > 10) return ;
    if(now == b)
    {
        ans = step;
        return ;
    }
    for(int i=0; i<trans_cnt; i++)
    {
        int pos = -1;
        pos = now.find(from[i]);
        while(pos != -1)
        {
            string changed = now;
            changed.erase(pos, from[i].size());
            changed.insert(pos, to[i]);
            if(dp.find(changed) == dp.end() || dp[changed] > step + 1)
            {
                dfs(changed, step + 1);
            }
            pos = now.find(from[i], pos + 1);
        }
    }
}

/*----------------------------------------------------------------------------*/
int main()
{
    cin >> a >>b;
    while(cin >> from[trans_cnt] >> to[trans_cnt]) trans_cnt ++;
    for(int i=1; i<=10; i++)
    {
        ans = i;
        dp.clear();
        dfs(a, 0);
        if(ans != MAX_NUM) break;
    }
    if(ans == MAX_NUM) cout << "NO ANSWER!" << endl;
    cout << ans << endl;
    return 0;
}
