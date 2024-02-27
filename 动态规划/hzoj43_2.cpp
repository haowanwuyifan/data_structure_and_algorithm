/*------------------------------------------------------------------------------
 * @file    HZOJ43_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/19 22:48:57
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ43_2_C_

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
int val[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5][MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    f[1][1] = val[1][1];
    for(int i=2; i<=n; i++)
    {
        for(int j=2; i<=i-1; j++)
        {
            f[i][j] = max(f[i-1][j-1], f[i-1][j]) + val[i][j];
        }
        f[i][1] = f[i-1][1] + val[i][1];
        f[i][i] = f[i-1][i-1] + val[i][i];
    }
    int ans = f[n][1];
    for(int i=2; i<=n; i++)
    {
        if(f[n][i] > ans) ans = f[n][i];
    }
    printf("%d", ans);
    return 0;
}
