/*------------------------------------------------------------------------------
 * @file    HZOJ263.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/10/27 11:27:40
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
#define _HZOJ263_C_

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
bool isValid(int a[], int n)
{
    stack<int> s;
    int x = 1;
    for(int i=0;i<n;i++)
    {
        if(s.empty() || s.top() < a[i])
        {
            while(x <= a[i]) s.push(x), x += 1;
        }
        if(s.empty() || s.top() != a[i]) return false;
        s.pop();
    }
    return true;
}

int main()
{
    int n, a[25], cnt = 20;
    cin >> n;
    for(int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if(isValid(a, n))
        {
            for(int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
            cnt -= 1;
        }
    } while(next_permutation(a, a + n) && cnt);
    return 0;
}
