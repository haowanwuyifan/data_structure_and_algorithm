/*------------------------------------------------------------------------------
 * @file    LUOGU1443.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/05 17:13:40
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1443_C_

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
#define MAX_N 20
int dir[8][2] = {
    {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};
int dis[MAX_N + 5][MAX_N + 5];
int n, m;

void dfs(int step, int x, int y)
{
    if(dis[x][y] != -1 && dis[x][y] <= step)
    {
        return ;
    }
    dis[x][y] = step;
    for(int k=0; k<8; k++)
    {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        if(dx < 0 || dx > n) continue;
        if(dy < 0 || dy > m) continue;
        dfs(step + 1, dx, dy);
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dis[i][j] = -1;
        }
    }
    dfs(0, a, b);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j > 1) printf(" ");
            printf("%d", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
