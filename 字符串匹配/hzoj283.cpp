/*------------------------------------------------------------------------------
 * @file    HZOJ283.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/10 10:46:53
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ283_C_

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

#define MAX_N 100000
char s[MAX_N + 5];
int node[MAX_N + 5][10];
int val[MAX_N + 5], child[MAX_N + 5];
int cnt = 1, root = 1;

int insert(const char *s)
{
    int p = root, sum = 0;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - '0';
        if(node[p][ind] == 0)
        {
            node[p][ind] = ++cnt;
            child[p] += 1;    
        }
        p = node[p][ind];
        sum += val[p];
    }
    val[p] += 1;
    return !(sum == 0 && child[p] == 0);
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", s);
        flag += insert(s);
    }
    printf("%s\n", flag ? "NO" : "YES");
    return 0;
}
