/*------------------------------------------------------------------------------
 * @file    LUOGU1315.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/05 12:03:28
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1315_C_

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
#define MAX_N 200
int to[MAX_N];
int dis[MAX_N + 5] = {0};

void dfs(int k, int a, int n)
{
    if(dis[a] <= k) return ;
    dis[a] = k;
    if(a + to[a] <= n) dfs(k+1, a+to[a], n);
    if(a - to[a] >= 1) dfs(k+1, a-to[a], n);
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for(int i=0; i<n; i++) scanf("%d", to + i);
    for(int i=0; i<n; i++) dis[i] = n + 1;
    dfs(0, a, n);
    printf("%d\n", dis[b]);
    return 0;
}
