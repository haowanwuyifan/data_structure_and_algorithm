/*------------------------------------------------------------------------------
 * @file    HZOJ511.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/11 16:46:21
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ511_C_

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
    long long a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    if(k == 1)
    {
        cout << b - a << endl;
        return 0;
    }
    if(k == 0)
    {
        if(b != 0) cout << b - a << endl;
        else cout << !!(a) << endl;
        return 0;
    }
    while(1)
    {
        if(a * k <= b)
        {
            ans += b % k;
            b /= k;
        }
        else
        {
            ans += b - a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
