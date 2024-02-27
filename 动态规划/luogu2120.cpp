/*------------------------------------------------------------------------------
 * @file    LUOGU2120.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/14 12:20:50
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU2120_C_

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define MAX_N 1000000
long long dp[MAX_N + 5];
long long c[MAX_N + 5];
long long s[MAX_N + 5], t[MAX_N + 5], f[MAX_N + 5];
long long x[MAX_N + 5];
long long q[MAX_N + 5], head = 0, tail = 0;

void set(long long i, int j)
{
    dp[i] = dp[j] + x[i] * (s[i] - s[j]) - (t[i] - t[j]) + c[i];
    f[i] = dp[i] + t[i];
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    long long n;    
    cin >> n;
    for(long long i=1; i<=n; i++)
    {
        cin >> x[i] >> s[i] >> c[i];
        t[i] = t[i - 1] + x[i] * s[i];
        s[i] += s[i - 1];
    }
    set(1, 0);
    q[tail++] = 0;
    q[tail++] = 1;
    for(long long i=2; i<=n; i++)
    {
        do {
            long long X = s[q[head + 1]] - s[q[head]];
            long long Y = f[q[head + 1]] - f[q[head]];
            if(tail - head >= 2 && Y < x[i] * X) ++head;
            else break;
        } while(1);
        set(i, q[head]);
        do {
            long long A = f[i] - f[q[tail - 1]];
            long long B = f[q[tail - 1]] - f[q[tail - 2]];
            long long C = s[i] - s[q[tail - 1]];
            long long D = f[q[tail - 1]] - f[q[tail - 2]];
            if(tail - head >= 2 && A * D < B * C) --tail;
            else break;
        } while (1);
        q[tail++] = i;
    }
    long long ans = dp[n];
    for(long long i=n-1; i>= 1 && s[i] == s[i + 1]; i--)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
