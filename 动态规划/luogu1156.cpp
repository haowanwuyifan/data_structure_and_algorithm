/*------------------------------------------------------------------------------
 * @file    LUOGU1156.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/11 11:37:31
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1156_C_

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

#define MAX_N 100
struct Data {
    int t, f, h;
} arr[MAX_N + 5];

int dp[2 * MAX_N + 5];

bool cmp(const Data& a, const Data &b)
{
    return a.t < b.t;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int D, G;   
    cin >> D >> G;
    for(int i=0; i<G; i++)
    {
        cin >> arr[i].t >> arr[i].f >> arr[i].h;
    }
    sort(arr, arr + G, cmp);
    dp[0] = 10;
    for(int i=0; i<G; i++)
    {
        for(int j=D; j>=0; j--)
        {
            if(dp[j] < arr[i].t) continue;
            if(j + arr[i].h >= D)
            {
                cout << arr[i].t << endl;
                return 0;
            }
            dp[j + arr[i].h] = max(dp[j + arr[i].h], dp[j]);
            dp[j] += arr[i].f;
        }
    }
    cout << dp[0] << endl;
    return 0;
}
