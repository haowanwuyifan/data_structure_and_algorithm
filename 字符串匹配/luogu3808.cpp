/*------------------------------------------------------------------------------
 * @file    LUOGU3808.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/03/29 17:28:50
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU3808_C_

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

#define MAX_N 1000000

int node[MAX_N + 5][26];
int val[MAX_N + 5] = {0};
int fail[MAX_N + 5] = {0};
int node_cnt = 1, root = 1;
int q[MAX_N + 5];
char s[MAX_N + 5];

int getNewNode() {return ++node_cnt ;}

void insert(char* s)
{
    int p = root;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        if(node[p][ind] == 0) node[p][ind] = getNewNode();
        p = node[p][ind];
    }
    val[p] += 1;
    return ;
}

void build_ac()
{
    int head = 0, tail = 0, p;
    q[tail++] = root;
    while(head < tail)
    {
        int cur = q[head++];
        for(int i=0; i<26; i++)
        {
            if(node[cur][i] == 0)
            {
                if(fail[cur] == 0) node[cur][i] = root;
                else node[cur][i] = node[fail[cur]][i];
                continue;
            }
            p = fail[cur];
            if(p == 0) p = root;
            else p = node[fail[cur]][i];
            fail[node[cur][i]] = p;
            q[tail++] = node[cur][i];
        }
    }
    return ;
}

int find_all(char *s)
{
    int ans = 0, p = root, q;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        p = node[p][ind];
        q = p;
        while(q && val[q] != -1)
        {
            ans += val[q];
            val[q] = -1;
            q = fail[q];
        }
    }
    return ans;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", s);
        insert(s);
    }
    build_ac();
    scanf("%s", s);
    printf("%d\n", find_all(s));
    return 0;
}