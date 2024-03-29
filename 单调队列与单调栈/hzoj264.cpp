/*------------------------------------------------------------------------------
 * @file    HZOJ264.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/02 12:22:09
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ264_C_

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
#include <deque>

using namespace std;



/*----------------------------------------------------------------------------*/
int main()
{
    long long n;
    scanf("%lld", &n);
    vector<long long> arr(n+2, -1), l(n+2), r(n+2);
    for(long long i=1; i<=n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    stack<long long> s;
    s.push(0);
    for(long long i=1; i<=n+1; i++)
    {
        while(!s.empty() && arr[i] < arr[s.top()])
        {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(long long i=n; i>=0; i--)
    {
        while(!s.empty() && arr[i] < arr[s.top()])
        {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0;
    for(long long i=1; i<=n; i++)
    {
        long long height = arr[i], width = r[i] - l[i] - 1;
        ans = max(height*width, ans);
    }
    printf("%lld\n", ans);
    return 0;
}
