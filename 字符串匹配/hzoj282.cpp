/*------------------------------------------------------------------------------
 * @file    HZOJ282.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/10 10:27:23
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ282_C_

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

#define MAX_N 3100000

int node[MAX_N + 5][2];
int cnt = 1, root = 1;

void insert(int x)
{
    int p = 1;
    for(int i=30; i>=0; i--)
    {
        int ind = !!(x & (1 << i));
        if(node[p][ind] == 0) node[p][ind] = +cnt;
        p = node[p][ind];
    }
    return ;
}

int query(int x)
{
    int ans = 0, p = root;
    for(int i=30; i>=0; i--)
    {
        int ind = !!(x & (1 << i));
        if(node[p][1 - ind] != 0)
        {
            ans |= (1 << i);
            p = node[p][1 - ind];
        }
        else
        {
            p = node[p][ind];
        }
    }
    return ans;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, ans = 0, temp;
    scanf("%d", &n);
    for(int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        insert(a);
        temp = query(a);
        ans = max(temp, ans);
    }
    printf("%d\n", ans);

    return 0;
}
