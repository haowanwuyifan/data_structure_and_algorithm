/*------------------------------------------------------------------------------
 * @file    LUOGU1115.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/30 11:21:24
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1115_C_

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



/*----------------------------------------------------------------------------*/
int main()
{
    int n, pre_dp = 0, dp, ans = 0x8fffffff;
    cin >> n;
    for(int i=0, x; i<n; i++)
    {
        cin >> x;
        if(pre_dp > 0) dp = pre_dp + x;
        else dp = x;
        ans = max(ans, dp);
        pre_dp = dp;
    }
    cout << ans << endl;
    return 0;
}
