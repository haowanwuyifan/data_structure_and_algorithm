/*------------------------------------------------------------------------------
 * @file    HZOJ505.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/08 17:14:55
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ505_C_

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

bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
}


/*----------------------------------------------------------------------------*/
int main()
{
    vector<string> arr;
    string s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i=0; i<n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
