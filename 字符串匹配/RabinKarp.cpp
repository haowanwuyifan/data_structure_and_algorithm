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

using namespace std;

#define TEST(func, s, t) { \
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
}
#define MOD 9973
#define BASE 131

int hash_func(const char* s)
{
    int h = 0, slen = strlen(s);
    for(int i=slen-1, kbase=1; i>=0; i--)
    {
        h = (h + s[i] * s[i] * kbase) % MOD;
        kbase = kbase * BASE % MOD;
    }
    return h;
}



int RabinKarp(const char* s, const char* t)
{
    int thash = hash_func(t);
    int nbase = 1, tlen;
    for(int tlen=0; t[tlen]; tlen++)
    {
        nbase = nbase * BASE % MOD;
    }
    for(int i=0, h=0; s[i]; i++)
    {
        h = h * BASE + s[i];
        if(i >= tlen) h = (h - s[i-tlen] * nbase % MOD + MOD) % MOD;
        if(i + 1 < tlen) continue;
        if(h != thash) continue;
        if(strncmp(s + i - tlen + 1, t, tlen) == 0)
        {
            return i - tlen + 1;
        }
    }
    return -1;
}


/*----------------------------------------------------------------------------*/
int main()
{
    char s[100], t[100];
    while(~scanf("%s%s", &s, &t))
    {
        TEST(RabinKarp, s, t);
    }
    return 0;
}
