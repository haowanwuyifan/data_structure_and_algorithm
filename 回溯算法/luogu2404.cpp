/*------------------------------------------------------------------------------
 * @file    LUOGU2404.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/07 12:34:10
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU2404_C_

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
int ans[20] = {0};

void print_one_result(int n)
{
    for(int i=0; i<n; i++)
    {
        if(i) cout << "+";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void dfs(int k, int s_num, int n)
{
    if(n == 0)
    {
        print_one_result(k);
        return ;
    }
    if(s_num > n) return;
    for(int i=s_num; i<=n; i++)
    {
        ans[k] = i;
        dfs(k+1, i, n-i);
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    dfs(0, 1, n);

    return 0;
}
