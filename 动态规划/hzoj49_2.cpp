/*------------------------------------------------------------------------------
 * @file    HZOJ49_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/27 12:12:40
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ49_2_C_

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
int dp[MAX_V + 5] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    int V, n;
    scanf("%d%d", &V, &n);
    for(int i=0, v, w, s; i<n; i++)
    {
        scanf("%d%d%d", &v, &w, &s);
        for(int k=1; s; s-=k, k*= 2)
        {
            k = min(s, k);
            for(int j=V; j>=k*v; j--)
            {
                dp[j] = max(dp[j], dp[j-k*v] + w*v);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
