/*------------------------------------------------------------------------------
 * @file    LUOGU1028.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/17 17:50:22
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1028_C_

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

#define MAX_N 1000
int f[MAX_N + 5] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        f[i] = 1;
        for(int j=1; j<=i/2; j++)
        {
            f[i] += f[j];
        }
    }
    cout << f[n] << endl;
    return 0;
}
