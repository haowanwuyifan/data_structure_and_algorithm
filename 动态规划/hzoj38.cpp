/*------------------------------------------------------------------------------
 * @file    HZOJ38.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/14 12:04:29
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ38_C_

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
#define MAX_N 100
long long arr[MAX_N + 5] = {0};

long long f(int n)
{
    if(n == 1 || n == 2) return 1;
    if(arr[n]) return arr[n];
    arr[n] = f(n - 1) + f(n - 2);
    return arr[n];
}



/*----------------------------------------------------------------------------*/
int main()
{   
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
