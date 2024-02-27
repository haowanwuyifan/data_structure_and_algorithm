/*------------------------------------------------------------------------------
 * @file    HZOJ372.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/03 22:25:15
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ372_C_

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



/*----------------------------------------------------------------------------*/
int main()
{   
    int n, p;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    deque<int> ap, bp;
    for(p=0; p<n; p++)
    {
        while(!ap.empty() && a[p] <= a[ap.back()]) ap.pop_back();
        while(!bp.empty() && b[p] <= b[bp.back()]) bp.pop_back();
        ap.push_back(p);
        bp.push_back(p);
        if(ap.size() != bp.size()) break;
    }
    printf("%d\n", p);
    return 0;
}
