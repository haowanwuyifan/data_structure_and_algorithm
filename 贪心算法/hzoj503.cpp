/*------------------------------------------------------------------------------
 * @file    HZOJ503.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/09 11:42:54
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ503_C_

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
    int w, n;
    cin >> w >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1, cnt = 0;
    while(i < j)
    {
        if(arr[i] + arr[j] <= w)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        cnt += 1;
    }
    if(i == j) cnt += 1;
    cout << cnt << endl;
    return 0;
}
