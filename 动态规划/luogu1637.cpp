/*------------------------------------------------------------------------------
 * @file    LUOGU1637.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/13 17:24:36
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1637_C_

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

#define MAX_N 30000
int n, a[MAX_N + 5];
long long f[MAX_N + 5][4];


/*----------------------------------------------------------------------------*/
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        f[i][1] = 1;
    }
    long long ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(a[j] >= a[i]) continue;
            f[i][2] += f[i][1];
            f[i][3] += f[i][2];
        }
        ans += f[i][3];
    }
    cout << ans << endl;
    return 0;
}
