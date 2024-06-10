/*------------------------------------------------------------------------------
 * @file    DRAFT.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/11 19:12:37
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _DRAFT_C_

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

vector<int> skill;
vector<int> cut;
vector<int> vis;

void init(int n)
{
    skill.clear();
    cut.clear();
    vis.clear();
    for(int i=0; i<n; i++)
    {
        vis.push_back(0);
    }
}

void dfs(int time, int n, int m, int* ans)
{
    if(time == n)
    {
        if(m > 0)
        {
            *ans = -1;
        }
        return ;
    }
    for(int i=0; i<n; i++)
    {
        if(vis[i] == 0)
        {
            int p = (m <= cut[i]) ? m - 2 * skill[i] : m - skill[i];
            if(p <= 0)
            {
                if(*ans > 0) *ans = min(*ans, time + 1);
                else *ans = time + 1;
                break;
            }
            vis[i] = 1;
            dfs(i+1, n, p, ans);
            vis[i] = 0;
        }
    }
    return ;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i=0, A, x; i<n; i++)
    {
        cin >> A >> x;
        skill.push_back(A);
        cut.push_back(x);
    }
    int ans = 0;
    dfs(0, n, m, &ans);
    cout << ans << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
