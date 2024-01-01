/*------------------------------------------------------------------------------
 * @file    QUICK_FIND.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/28 12:18:55
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _QUICK_FIND_C_

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

#define MAX_N 10000
int color[MAX_N + 5];

void init(int n)
{
    for(int i=0; i<=n; i++) color[i] = i;
    return ;
}

int find(int a)
{
    return color[a];
}

int merge(int a, int b, int n)
{
    int aa = color[a], bb = color[b];
    if(aa == bb) return 0;
    for(int i=0; i<=n; i++)
    {
        if(find(i) == aa) color[i] = bb;
    }
    return 1;
}

void output(int n)
{
    int ret = 0;
    for(int i=0; i<=n; i++)
    {
        ret += printf("%3d", i);
    }
    printf("\n");
    for(int i=0; i<ret; i++) printf("-");
    printf("\n");
    for(int i=0; i<=n; i++)
    {
        printf("%3d", color[i]);
    }
    printf("\n");
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n, a, b;    
    cin >> n;
    init(n);
    while(cin >> a >> b)
    {
        printf("merge %d with %d : %d\n", a, b, merge(a, b, n));
        output(n);
    }        

    return 0;
}
