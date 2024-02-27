/*------------------------------------------------------------------------------
 * @file    HZOJ270.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/01 12:24:15
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ270_C_

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
#include <cinttypes>

using namespace std;



/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;
    cin >> n >>m;
    vector<int> s(n+1);
    deque<int> q;
    s.push_back(0);
    for(int i=1; i<=n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    q.push_back(0);
    int ans = INT32_MIN;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, s[i] - s[q.front()]);
        while(!q.empty() && s[q.back()] > s[i]) s.pop_back();
        q.push_back(i);
        if(i - q.front() == m) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}
