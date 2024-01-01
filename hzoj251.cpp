/*------------------------------------------------------------------------------
 * @file    HZOJ251.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/01 17:58:49
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ251_C_

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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int X, Y, costX = 0, costY = 0;
    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    for(int i=0; i<n; i++) x[i] = x[i] - i;
    sort(x.begin(), x.end());
    X = x[n / 2];
    Y = y[n / 2];
    for(int i=0; i<n; i++) costY += abs(y[i] - Y);
    for(int i=0; i<n; i++) costX += abs(x[i] - X);
    cout << costX + costY << endl;
    return 0;
}
