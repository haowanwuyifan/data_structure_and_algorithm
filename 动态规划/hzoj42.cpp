/*------------------------------------------------------------------------------
 * @file    HZOJ42.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/14 21:45:10
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ42_C_

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
#define MAX_N 10000
#define MAX_M 25
int w[MAX_M + 5];
int f[MAX_M + 5][MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int m, n;
    cin >> m >> n;
    for(int i=1; i<=n; i++) cin >>w[i];
    for(int i=1; i<=m; i++)
    {
        f[i][0] = 1;
        for(int j=1; j<=n; j++)
        {
            f[i][j] = f[i-1][j];
            if(j < w[i]) continue;
            f[i][j] += f[i][j - w[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
