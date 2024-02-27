/*------------------------------------------------------------------------------
 * @file    HZOJ285.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/19 17:20:14
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
#define _HZOJ285_C_

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

typedef pair<int, int> PII;

/*----------------------------------------------------------------------------*/
int main()
{
    int n, m, t=0;
    cin >> n >> m;
    set<PII> s;
    s.insert(PII(0, t++));
    for(int i=0; i<n; i++)
    {
        int i1 = i % 2, i2 = 1 - i1;
        vector<int> temp;
        for(auto x : s)
        {
            temp.push_back(x.first);
        }
        s.clear();
        for(int j=0, a; j<m; j++)
        {
            cin >> a;
            for(auto x : s)
            {
                if(s.size() < m || 
                   s.begin()->first < x.first - a)
                {
                    s.insert(PII(x.first - a, t++));
                }
                if(s.size() > m) s.erase(s.begin());
            }
        }
    }
    int flag = 0;
    for(auto iter = s.rbegin(); iter != s.rend(); iter++)
    {
        if(flag) cout << " ";
        cout << -iter->first;
        flag = 1;
    }
    cout << endl;
    return 0;
}
