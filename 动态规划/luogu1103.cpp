/*------------------------------------------------------------------------------
 * @file    LUOGU1103.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/31 12:27:00
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1103_C_

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
#include <cstring>
#include <vector>

using namespace std;

#define MAX_N 100
int dp[MAX_N + 5][MAX_N + 5];
struct Data {
    int x, y;
} arr[MAX_N + 5];

/*----------------------------------------------------------------------------*/
int main()
{
    int n, K;
    cin >> n >> K;
    K = n - K;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, [&](const Data a, const Data b) -> bool {
        return a.x < b.x;
    });
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        dp[i][0] = dp[1][1] = 0;
        for(int k=2; k<=i; k++)
        {
            for(int j=1; j<i; j++)
            {
                dp[i][k] = min(dp[i][k], dp[j][k-1] + abs(arr[j].y - arr[i].y));
            }
        }
    }
    int ans = 0x7fffffff;
    for(int i=1; i<=n; i++)
    {
        ans = min(ans, dp[i][K]);
    }
    cout << ans << endl;
    return 0;
}
