/*------------------------------------------------------------------------------
 * @file    LUOGU1509.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/30 16:43:56
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1509_C_

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

#define MAX_N 100
int dp[MAX_N + 5][MAX_N + 5];
int dpt[MAX_N + 5][MAX_N + 5];
int r[MAX_N + 5], rp[MAX_N + 5], t[MAX_N + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int n, M, R;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> r[i] >> rp[i] >> t[i];
    }
    cin >> M >> R;
    for(int i=0; i<n; i++)
    {
        for(int j=M; j>=r[i]; j--)
        {
            for(int k=R; k>=rp[i]; k--)
            {
                if(dp[j][k] < dp[j-r[i]][k-rp[i]] + 1)
                {
                    dp[j][k] = dp[j-r[i]][k-rp[i]] + 1;
                    dpt[j][k] = dpt[j-r[i]][k-rp[i]] + t[i];
                }
                else if(dp[j][k] == dp[j-r[i]][k-rp[i]] + 1)
                {

                    dpt[j][k] = min(dpt[j][k], dpt[j-r[i]][k-rp[i]] + t[i]);
                }
            }
        }
    }
    cout << dpt[M][R] << endl;
    return 0;
}
