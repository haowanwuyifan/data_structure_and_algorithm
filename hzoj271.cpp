/*------------------------------------------------------------------------------
 * @file    HZOJ271.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/01 11:59:33
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ271_C_

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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> q;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        while(!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if(i - q.front() == k) q.pop_front();
        if(i+1 < k) continue;
        if(i >= k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    q.clear();
    for(int i=0; i<n; i++)
    {
        while(!q.empty() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if(i - q.front() == k) q.pop_front();
        if(i+1 < k) continue;
        if(i >= k) cout << " ";
        cout << arr[q.front()];
    }
    return 0;
}
