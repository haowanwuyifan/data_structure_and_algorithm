/*------------------------------------------------------------------------------
 * @file    HZOJ284.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/19 12:07:43
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------
 * @attention 
 
 * THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE 
 * CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE 
 * TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH 
 * HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN 
 * CONNECTION WITH PRODUCTS MADE BY CUSTOMERS. 
 * 
 * <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2> 
------------------------------------------------------------------------------*/

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ284_C_

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

struct Data
{
    Data(int p, int d) : p(p), d(d) {}
    int p, d;
    bool operator < (const Data &obj) const{
        if(d != obj.d) return d < obj.d;
        return p > obj.p;
    }
};

typedef pair<int, int> PII;

/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    vector<Data> arr;
    set<PII> s;
    for(int i=0, p, d; i<n; i++)
    {
        cin >> p >> d;
        arr.push_back(Data(p, d));
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
    {
        if(arr[i].d > s.size())
        {
            s.insert(PII(arr[i].p, i));
        }
        else
        {
            if(arr[i].p > s.begin()->first)
            {
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }
    int ans = 0;
    for(auto x : s)
    {
        ans += x.first;
    }
    cout << ans <<endl;
    return 0;
}
