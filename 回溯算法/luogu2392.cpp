/*------------------------------------------------------------------------------
 * @file    LUOGU2392.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/07 16:29:14
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU2392_C_

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
#define MAX_N 20
#define MAX_ANS 9999999

int total = 0;
int ans = 0;
int num[6];
int s[6][MAX_N];
int vis[MAX_N + 5] = {0};

void dfs(int i, int l_end, int r_end, int step)
{
    if(step == num[i])
    {
        ans = min(ans, max(l_end, r_end));
        return ;
    }
    dfs(i, l_end + s[i][step], r_end, step + 1);
    dfs(i, l_end, r_end + s[i][step], step + 1);
    return ;
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
        }
    }
    for(int i=0; i<4; i++)
    {
        ans = MAX_ANS;
        dfs(i, 0, 0, 0);
        total += ans;
    }
    cout << total << endl;
    return 0;
}
