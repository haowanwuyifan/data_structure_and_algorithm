/*------------------------------------------------------------------------------
 * @file    HZOJ43.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/19 22:05:58
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ43_C_

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
    for(int i=1; i<=n; i++) f[n][i] = val[n][i];
    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            f[i][j] = max(f[i+1][j], f[i+1][j+1]) + val[i][j];
        }
    }
    printf("%d", f[1][1]);
    return 0;
}
