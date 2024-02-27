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
#include <vector>

using namespace std;

#define TEST(func, s, t) { \
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
}

int brute_force(const char* s, const char *t)
{
    for(int i=0; s[i]; i++)
    {
        int flag = 1;
        for(int j=0; t[j]; j++)
        {
            if(s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return i;
    }
    return -1;
}


/*----------------------------------------------------------------------------*/
int main()
{
    char s[100], t[100];
    while(~scanf("%s%s", &s, &t))
    {
        TEST(brute_force, s, t);
    }
    return 0;
}
