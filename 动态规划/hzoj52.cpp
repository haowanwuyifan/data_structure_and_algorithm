/*------------------------------------------------------------------------------
 * @file    HZOJ52.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/29 12:27:38
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ52_C_

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
#define SQ(x) ((x) * (x))
long long c[MAX_N + 5], sum[MAX_N + 5];
int dp[MAX_N + 5], f[MAX_N + 5];
int q[MAX_N + 5], head, tail;
long long n, M;

double slope(int i, int j)
{
    return 1.0 * (f[i] - f[j]) / (sum[i] - sum[j]);
}

void set(int i, int j)
{
    dp[i] = dp[j] + SQ(sum[i] - sum[j]) + M;
    f[i] = dp[i] + SQ(sum[i]);
}


/*----------------------------------------------------------------------------*/
int main()
{
    scanf("%lld%lld", &n, &M);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", c + i);
        sum[i] = sum[i-1] + c[i];
    }
    head = tail = 0;
    q[tail++] = 0;
    for(int i=1; i<=n; i++)
    {
        while(tail - head >= 2 && slope(q[head + 1], q[head] < 2 * sum[i])) head += 1;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], q[tail - 2]) > slope(i, q[tail - 1])) tail -= 1;
        q[tail++] = i;
        
    }
    printf("%lld\n", dp[n]);
    return 0;
}
