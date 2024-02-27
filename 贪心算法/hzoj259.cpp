/*------------------------------------------------------------------------------
 * @file    HZOJ259.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/12 18:20:14
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ259_C_

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
int cnt[105] = {0};

struct Data {
    int x, y;
};

Data task[MAX_N + 5], ma[MAX_N + 5];

bool cmp(const Data &a, const Data &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n, m, task_cnt = 0;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &ma[i].x, &ma[i].y);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &task[i].x, &task[i].y);
    }
    sort(ma, ma + n, cmp);
    sort(task, task + m, cmp);
    for(int i=0, j=0; i<m; i++)
    {
        while(j < n && ma[j].x >= task[i].x)
        {
            cnt[ma[j].y] += 1;
            j += 1;
        }
        for(int y=task[i].y; y<=100; y++)
        {
            if(cnt[y] == 0) continue;
            cnt[y] -= 1;
            ans += 500 * task[i].x + 2 * task[i].y;
            task_cnt += 1;
            break;
        }
    }
    printf("%d %lld\n", task_cnt, ans);
    return 0;
}
