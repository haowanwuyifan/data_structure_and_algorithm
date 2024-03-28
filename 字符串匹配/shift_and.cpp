/*------------------------------------------------------------------------------
 * @file    SHIFT_AND.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/03/13 10:46:40
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _SHIFT_AND_C_

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

#define TEST(func, s, t) { \
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
}

int shift_and(const char* s, const char* t)
{
    int code[256] = {0}, n = 0;
    for(n=0; t[n]; n++) code[t[n]] |= (1 << n);
    int p = 0;
    for(int i=0; s[i]; i++)
    {
        p = (p << 1 | 1) & code[s[i]];
        if(p & (1 << (n - 1))) return i - n + 1;
    }
    return -1;
}



/*----------------------------------------------------------------------------*/
int main()
{
    char s[100], t[100];
    while(~scanf("%s%s", s, t))
    {
        TEST(shift_and, s, t);
    }


    return 0;
}
