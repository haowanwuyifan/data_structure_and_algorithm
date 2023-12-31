/*------------------------------------------------------------------------------
 * @file    HZOJ327.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/31 12:02:31
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ327_C_

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

class UnionSet {
public:
    UnionSet(int n) : fa(n+1) {
        for(int i=0; i<=n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x)
    {
        if(fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[fa[x]] + val[x]) % 2;
        return fa[x] = root;
    }
    void merge(int a, int b, int t)
    {
        int aa = get(a), bb = get(b);
        if(aa == bb) return ;
        val[aa] = (t - val[a] + val[b] + 2) % 2;
        fa[aa] = bb;
        return ;
    }
    vector<int> fa, val;
};

struct Data {
    int a, b, c;
};


/*----------------------------------------------------------------------------*/
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Data> arr(m);
    UnionSet u(n);
    for(int i=0 ;i<m; i++)
    {
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    sort(arr.begin(), arr.end(), [&](const Data &a, const Data &b) -> bool {
        return a.c > b.c;
    });
    int ans = 0;
    for(int i=0; i<m; i++)
    {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        if(u.get(a) == u.get(b))
        {
            if((u.val[a] + u.val[b])%2 == 0){
                ans = c;
                break;
            } 
        }
        else {
            u.merge(a, b, 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
