/*------------------------------------------------------------------------------
 * @file    LUOGU2392_NEW.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/07 17:40:18
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU2392_NEW_C_

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
#include <unordered_map>

using namespace std;
#define MAX_N 20
#define MAX_ANS 9999999

int total = 0;
int num[6];
int s[6][MAX_N];
int sum[6] = {0};
unordered_map<int, int> ind;

int solve(int k)
{
    int ans = MAX_ANS;
    int T = (1 << num[k]);
    for(int i=0; i<T; i++)
    {
        int j = i, l = 0, r = 0;
        while(j)
        {
            l += s[k][ind[-j & j]];
            j -= (-j & j);
        }
        r = sum[k] - l;
        ans = min(ans, max(l, r));
    }
    return ans;
}

/*----------------------------------------------------------------------------*/
int main()
{
    for(int i=0; i<4; i++)
    {
        cin >> num[i];
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<num[i]; j++)
        {
            cin >> s[i][j];
            sum[i] += s[i][j];
        }
    }
    for(int i=0, k=1; i<=MAX_N; i++, k*=2) ind[k] = i;
    for(int i=0; i<4; i++)
    {
        total += solve(i);
    }
    cout << total << endl;
    return 0;
}
