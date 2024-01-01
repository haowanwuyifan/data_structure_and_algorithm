/*------------------------------------------------------------------------------
 * @file    HZOJ72.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/30 17:29:25
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ72_C_

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

class WeightedUnionSet{
public:
    WeightedUnionSet(int n) : fa(n + 1), val(n + 1) {
        for(int i=0; i<=n; i++)
        {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x)
    {
        if(fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[fa[x]] + val[x]) % 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int t)
    {
        int aa = get(a), bb = get(b);
        if(aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (t - val[a] + val[b] + 3) % 3;
        return ;
    }
    vector<int> fa, val;
};




/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;    
    scanf("%d%d", &n, &m);
    WeightedUnionSet u(n);
    for(int i=0, a, b, c; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1)
        {
            u.merge(b, c, 2);
        }
        else
        {
            if(u.get(b) != u.get(c))
            {
                printf("Unknown\n");
            }
            else
            {
                switch ((u.val[b] - u.val[c] + 3) % 3)
                {
                case 0: printf("Tie\n"); break;
                case 1: printf("Lose\n"); break;
                case 2: printf("Win\n"); break;
                }
            }
        }
    }
    return 0;
}
