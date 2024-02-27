/*------------------------------------------------------------------------------
 * @file    LUOGU1605.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/05 21:40:22
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1605_C_

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
#define MAX_N 5
int g[MAX_N  + 5][MAX_N + 5] = {0};
int n, m, t, x1, x2, y1, y2, ans;
int dir[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void dfs(int x, int y)
{
    if(x == x2 && y == y2)
    {
        ans += 1;
        return ;
    }
    g[x][y] = 0;
    for(int k=0; k<4; k++)
    {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        if(g[dx][dy] == 0) continue;
        dfs(dx, dy);
    }
    g[x][y] = 1;
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            g[i][j] = 1;
        }
    }
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for(int i=0, x, y; i<t; i++)
    {
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    ans = 0;
    dfs(x1, y1);
    printf("%d\n", ans);
    return 0;
}
