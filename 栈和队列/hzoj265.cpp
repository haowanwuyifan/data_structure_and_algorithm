/*------------------------------------------------------------------------------
 * @file    HZOJ265.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/10/28 11:36:24
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
#define _HZOJ265_C_

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

#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5];
stack<int> s;

/*----------------------------------------------------------------------------*/
int main()
{
    cin >> (str + 1);    
    for(int i=1;str[i];i++)
    {
        switch (str[i])
        {
            case '(':
            case '[':
            case '{': s.push(i); break;
            /* code */
            case ')':
            {
                if(!s.empty() && str[s.top()] == '(')
                {
                    match[s.top()] = i;
                    match[i] = s.top();
                    s.pop();
                }
                else
                    s.push(i);
                break;
            }
            case ']':
            {
                if(!s.empty() && str[s.top()] == '[')
                {
                    match[s.top()] = i;
                    match[i] = s.top();
                    s.pop();
                }
                else
                    s.push(i);
                break;
            }
            case '}':
            {
                if(!s.empty() && str[s.top()] == '{')
                {
                    match[s.top()] = i;
                    match[i] = s.top();
                    s.pop();
                }
                else
                    s.push(i);
                break;
            }
            break;
        
        default:
            break;
        }
    }
    int temp_ans = 0, ans = 0, i = 1;
    while(str[i])
    {
        if(match[i])
        {
            temp_ans = match[i] - i + 1;
            i = match[i] + 1;
        }
        else
        {
            i += 1;
            temp_ans = 0;
        }
        if(temp_ans > ans) ans = temp_ans;
    }

    return 0;
}
