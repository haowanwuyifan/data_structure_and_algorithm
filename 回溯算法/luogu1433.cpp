/*------------------------------------------------------------------------------
 * @file    LUOGU1433.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/06 12:25:33
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1433_C_

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
#include <cmath>
#include <vector>

using namespace std;
#define MAX_N 25
#define S(a) ((a) * (a))
int n;
double ans = 1e9;
double x[MAX_N + 5], y[MAX_N + 5];
double dis[MAX_N + 5][MAX_N + 5];
double dp[70000][20];
int ind[70000];

double __dis(int i, int j)
{
    return sqrt(S(x[i] - x[j]) + S(y[i] - y[j]));
}

void dfs(int t, int now, double s)
{
    if(t == 0)
    {
        if(s < ans) ans = s;
        return ;
    }
    for(int k=t; k; k-=(-k & k))
    {
        int to = ind[-k & k], next_to = t - (t << to);
        if(dp[next_to][to] != 0 && dp[next_to][to] <= s + dis[now][to])
        {
            continue;
        }
        if(ans <= dis[now][to] + s) continue;
        dfs(next_to, to, s + dis[now][to]);
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    scanf("%d", &n);
    x[0] = y[0] = 0;
    double a, b;
    for(int i=1; i<=n; i++)
    {
        scanf("%lf%lf", &a, &b);
        x[i] = a;
        y[i] = b;
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            dis[i][j] = dis[j][i] = __dis(i, j);
        }
    }
    for(int k=1, i=0; i<=MAX_N; i++, k*=2) ind[k] = i;
    dfs((1 << (n+1)) - 2, 0, 0);
    printf("%.2lf\n", ans);
  return 0;
}
