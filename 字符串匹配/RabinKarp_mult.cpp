/*------------------------------------------------------------------------------
 * @file    BRUTE_FORCE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/02/17 12:04:47
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _BRUTE_FORCE_C_

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
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

#define MOD 9973
#define BASE 131

int hash_func(string s)
{
    int h = 0, slen = s.size();
    for(int i=slen-1, kbase=1; i>=0; i--)
    {
        h = (h + s[i] * s[i] * kbase) % MOD;
        kbase = kbase * BASE % MOD;
    }
    return h;
}



int RabinKarp(string s, vector<string> &t)
{
    unordered_map<int, vector<int>> thash;
    for(int i=0; i<t.size(); i++) thash[hash_func(t[i])].push_back(i);
    int nbase = 1, tlen;
    for(int tlen=0; t[0][tlen]; tlen++)
    {
        nbase = nbase * BASE % MOD;
    }
    for(int i=0, h=0; s[i]; i++)
    {
        h = h * BASE + s[i];
        if(i >= tlen) h = (h - s[i-tlen] * nbase % MOD + MOD) % MOD;
        if(i + 1 < tlen) continue;
        if(thash.find(h) == thash.end()) continue;
        for(int j=0; j<thash[h].size(); j++)
        {
            if(strncmp(s.c_str() + i - tlen + 1, t[thash[h][j]].c_str(), tlen) == 0)
            {
                printf("pos %d : %s\n", i - tlen + 1 ,t[thash[h][j]].c_str());
            }
        }
        
    }
    return -1;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    string s;
    vector<string> t(100);
    cin >> n;
    for(int i=0; i<n; i++) cin >> t[i];
    while(cin >> s)
    {
        RabinKarp(s, t);
    }
    return 0;
}
