/*------------------------------------------------------------------------------
 * @file    HZOJ266.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/10/29 17:19:42
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
#define _HZOJ266_C_

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
#include <math.h>


using namespace std;
#define INF 0x3f3f3f

bool is_operator(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return true;
        default: return false;
    }
    return false;
}

long long calc(string &str, long long l, long long r)
{
    long long pos = -1, pri = INF - 1, cur_pri, temp_pri = 0;
    for(long long i=l;i<r;i++)
    {
        cur_pri = INF;
        switch (str[i])
        {
            case '(': temp_pri += 100; break;
            case ')': temp_pri -= 100; break;
            case '+': 
            case '-': cur_pri = 1 + temp_pri; break;
            case '*': 
            case '/': cur_pri = 2 + temp_pri; break;
            case '^': cur_pri = 3 + temp_pri; break;
        
            default:
                break;
        }
        if((str[i] == '-' || str[i] == '+') && (i-1 < 0 || is_operator(str[i-1])))
        {
            cur_pri += 1000;
        }
        if(pri >= cur_pri)
        {
            pri = cur_pri;
            pos = i;
        }
    }
    if(pos == -1)
    {
        long long num = 0;
        for(long long i=l;i<r;i++)
        {
            if(str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }
    else
    {
        long long a = calc(str, l, pos);
        long long b = calc(str, pos+1, r);
        switch (str[pos])
        {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow(a, b);
        
            default:
                break;
        }
    }
    return 0;
}

/*----------------------------------------------------------------------------*/
int main()
{
    string str;
    cin >> str;
    cout << calc(str, 0, str.size());
    return 0;
}
