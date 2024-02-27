/*------------------------------------------------------------------------------
 * @file    HZOJ49.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/23 18:26:03
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ49_C_

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
    int n, V;    
    scanf("%d%d", &n, &V);
    for(int i=1, v, w, s; i<=n; i++)
    {
        scanf("%d%d%d", &v, &w, &s);
        for(int k=0; k<s; k++)
        {
            for(int j=V; j>=v; j--)
            {
                dp[j] = max(dp[j], dp[j-v] + w);
            }
            
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
