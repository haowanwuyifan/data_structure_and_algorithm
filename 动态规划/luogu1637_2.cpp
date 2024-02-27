/*------------------------------------------------------------------------------
 * @file    LUOGU1637_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/13 17:33:47
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1637_2_C_

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

#define MAX_N 30000
#define lowbit(x) ((x) & (-x))
int c[2][MAX_N + 5];

void add(int k, int i, int val, int n)
{
    while(i <= n) c[k][i] += val, i += lowbit(i);
    return ;
}

long long query(int k, int i)
{
    long long sum = 0;
    while(i)
    {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for(int i=0, a; i<n; i++)
    {
        cin >> a;
        ans += query(1, a-1);
        add(0, a, 1, MAX_N);
        add(1, a, query(0, a - 1), MAX_N);
    }
    cout << ans << endl;
    return 0;
}
