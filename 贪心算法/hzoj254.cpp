/*------------------------------------------------------------------------------
 * @file    HZOJ254.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/12 12:00:40
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ254_C_

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
#define MAX_N 50000
struct Data {
    int l, r, ind;
} arr[MAX_N + 5];
int m_time[MAX_N + 5], ans[MAX_N + 5];
int cnt = 1;


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ;i<n; i++)
    {
        scanf("%d%d", &arr[i].l, &arr[i].r);
        arr[i].ind = i;
    }
    sort(arr, arr + n, [&](const Data a, const Data b) -> bool {
        if(a.l != b.l) return a.l < b.l;
        return a.ind < b.ind;
    });
    for(int i=0; i<n; i++)
    {
        int pos = -1;
        for(int j=0; j<cnt; j++)
        {
            if(m_time[j] < arr[i].l)
            {
                pos = j;
                break;
            }
        }
        if(pos == -1) pos = (cnt++);
        m_time[pos] = arr[i].r;
        ans[arr[i].ind] = pos + 1;
    }
    cout << cnt << endl;
    for(int i=0; i<n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
