/*------------------------------------------------------------------------------
 * @file    HZOJ257.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/13 16:55:28
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ257_C_

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
#define MAX_N 1000

int C[MAX_N + 5] = {0};
int fa[MAX_N + 5] = {0};
int cnt[MAX_N + 5] = {1};
int vis[MAX_N + 5] = {0};
double w[MAX_N + 5] = {0};
int n, r;
long long ans = 0;

int find_x()
{
    int x = -1;
    for(int i=1; i<=n; i++)
    {
        if(i == r || vis[i] == 1) continue;
        if(x == -1 || w[x] <w[i]) x = i;
    }
    return x;
}

int find_father(int x)
{
    if(vis[fa[x]]) return find_father(fa[x]);
    return fa[x];
}


/*----------------------------------------------------------------------------*/
int main()
{
    cin >> n >> r;
    for(int i=1; i<=n; i++)
    {
        cin >> C[i];
        ans += C[i];
        fa[i] = i;
        w[i] = C[i];
    }
    for(int i=1, a, b; i<=n; i++)
    {
        cin >> a >> b;
        fa[b] = a;
    }
    for(int i=1; i<n; i++)
    {
        int x = find_x();
        int x_father = find_father(x);
        ans += cnt[x_father] * C[x];
        C[x_father] += C[x];
        cnt[x_father] += cnt[x];
        w[x_father] = 1.0 * C[x_father] / cnt[x_father];
        vis[x] = 1;
    }
    cout << ans <<endl;
    return 0;
}
