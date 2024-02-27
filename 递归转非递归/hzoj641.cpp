/*------------------------------------------------------------------------------
 * @file    HZOJ641.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/27 12:19:49
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ641_C_

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
int indeg[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);
int ans[MAX_N + 5];
int cnt = 0;

/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++)
    {
        cin >> a >> b;
        indeg[b] += 1;
        g[a].push_back(b);
    }
    set<int> q;
    for(int i=0; i<=n; i++)
    {
        if(indeg[i] == 0) q.insert(i);
    }
    while(q.size() > 0)
    {
        int now = *q.begin();
        ans[cnt++] = now;
        q.erase(q.begin());
        for(int i=0, I=g[now].size(); i<I; i++)
        {
            int t = g[now][i];
            indeg[t] -= 1;
            if(indeg[t] == 0) q.insert(t);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
