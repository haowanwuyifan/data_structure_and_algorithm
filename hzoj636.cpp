/*------------------------------------------------------------------------------
 * @file    HZOJ636.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/27 12:35:39
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ636_C_

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
#define MAX_N 100000
int indeg[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);
int ans[MAX_N + 5], cnt = 0;


/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0, x, y; i<m; i++)
    {
        scanf("%d%d", &x, &y);
        indeg[y] += 1;
        g[x].push_back(y);
    }
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(indeg[i]) continue;
        q.push(i);
        ans[i] = 1;
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0, I=g[now].size(); i<I; i++)
        {
            int t = g[now][i];
            indeg[t] -= 1;
            if(indeg[t] == 0) q.push(t);
            ans[t] = max(ans[now] + 1, ans[t]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
