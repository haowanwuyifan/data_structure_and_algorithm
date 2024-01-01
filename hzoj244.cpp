/*------------------------------------------------------------------------------
 * @file    HZOJ244.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/10 12:28:35
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ244_C_

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

#define MAX_N 500

struct Point {
    int x, y;
} arr[MAX_N + 5];

int tmp[MAX_N + 5];

bool cmp(const Point &a, const Point &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int check_y(Point *arr, int n, int c, int b, int e, int l)
{
    int cnt = 0;
    for(int i=b; i<=e; i++)
    {
        tmp[cnt++] = arr[i].y;
    }
    sort(tmp, tmp + cnt);
    for(int i=c-1; i<cnt; i++)
    {
        if(arr[i].y - arr[i-c+1].y < l) return 1;
    }
    return 0;
}

int check(Point *arr, int n, int c, int l)
{
    int j = 0;
    for(int i=0; i<n; i++)
    {
        while (arr[i].x - arr[j].x >= l) j += 1;
        if(i - j < c) continue;
        if(check_y(arr, n, c, j, i, l)) return 1;
    }
    return 0;
}

int bs(int l, int r, Point *arr, int n, int c)
{
    int L = 0;
    while (l < r)
    {
        L = (l + r) / 2;
        if(check(arr, n, c, L)) r = L;
        else l = L + 1;
    }
    return l;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int c, n;
    cin >> c >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    cout << bs(0, 10000, arr, n, c) << endl;
    return 0;
}
