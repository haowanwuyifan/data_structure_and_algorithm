/*------------------------------------------------------------------------------
 * @file    FACTORIAL.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/26 12:03:16
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _FACTORIAL_C_

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

int f(int n)
{
    if(n == 1) return 1;
    return n * f(n - 1);
}

struct Data {
    Data(int n, int* pre_ret) : n(n), pre_ret(pre_ret)
    {
        code = 0;
    }
    int n;
    int code, ret, *pre_ret;
};

int non_f(int n)
{
    stack<Data> s;
    int ans;
    Data d(n, &ans);
    s.push(d);
    while(!s.empty())
    {
        Data &cur = s.top();
        switch(cur.code)
        {
            case 0: {
                if(cur.n == 1)
                {
                    *(cur.pre_ret) = 1;
                    s.pop();
                }
                else
                {
                    cur.code = 1;
                }
            } break;
            case 1: {
                Data d(cur.n - 1, &(cur.ret));
                s.push(d);
                cur.code = 2;
            } break;
            case 2: {
                *(cur.pre_ret) = cur.ret * cur.n;
                s.pop();
            } break;
        }
    }
    return ans;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int x;
    while(cin >> x)
    {
        cout << f(x) << endl;
        cout<< non_f(x) << endl;
    }
    return 0;
}
