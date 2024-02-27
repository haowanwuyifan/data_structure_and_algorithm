/*------------------------------------------------------------------------------
 * @file    HZOJ595.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/10/25 12:29:48
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
#define _HZOJ595_C_

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
    int flag = 0, n;
    cin >> n;
    vector<string> ops(n), s;
    string target;
    for(int i=0;i<n;i++) cin >> ops[i];
    cin >> target;
    for(int i = 0; i < n; i++)
    {
        if(target == ops[i]) 
        {
            s.push_back(ops[i]);
            flag = 1;
            break;
        }
        if(ops[i] == "return") s.pop_back();
        else s.push_back(ops[i]);
    }
    if(flag){
        for(int i=0;i<s.size();i++)
        {
            if(i) cout << "->";
            cout << s[i];
        }
        cout << endl;
    }
    else 
    {
        cout << "NOT REFERENCED" << endl;
    }
    return 0;
}
