/*------------------------------------------------------------------------------
 * @file    HZOJ237.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/04 12:37:10
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ237_C_

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

void solve(int *arr, int ind, int n)
{
    if(ind == n+1)
    {
        cout << endl;
        return ;
    }
    for(int i=1; i<=n; i++)
    {
        if(arr[i] != 1)
        {
            arr[i] = 1;
            if(ind != 1) cout << " ";
            cout << i;
            solve(arr, ind+1, n);
            arr[i] = 0;
        }
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    solve(arr, 1, n);
    return 0;
}
