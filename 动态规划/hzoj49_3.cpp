/*------------------------------------------------------------------------------
 * @file    HZOJ49_3.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/27 17:37:44
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ49_3_C_

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

#define MAX_V 100000
#define MAX_N 100
int dp[MAX_N + 5][MAX_V + 5];


/*----------------------------------------------------------------------------*/
int main()
{
    int V, n;
    scanf("%d%d", &V, &n);
    for(int i=1, v, w, s; i<=n; i++)
    {
        scanf("%d%d%d", &v, &w, &s);
        for(int r=0; r<v; r++)
        {
            deque<int> q;
            for(int j=r; j<=V; j+=v)
            {
                dp[i-1][j] -= j / v * w;
                while(!q.empty() && dp[i-1][q.front()] < dp[i-1][j]) q.pop_back();
                q.push_back(j);
                if((j - q.front()) > s) q.pop_front();
                dp[i][j] = dp[i-1][q.front()] + j / v * w;
            }
        }
    }
    printf("%d\n", dp[n][V]);
    return 0;
}
