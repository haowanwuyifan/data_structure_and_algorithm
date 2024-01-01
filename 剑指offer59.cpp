/*------------------------------------------------------------------------------
 * @file    剑指OFFER59.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/01 23:52:33
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _剑指OFFER59_C_

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

class MaxQueue {
public:
    deque<int> q;
    deque<int> mq;
    MaxQueue() {}
    int max_value()
    {
        if(q.empty()) return -1;
        return mq.front();
    }
    void push_back(int value)
    {
        q.push_back(value);
        while(!mq.empty() && mq.back() < value) mq.pop_back();
        mq.push_back(value);
    }
    int pop_front()
    {
        if(q.empty()) return -1;
        int val = q.front();
        q.pop_front();
        if(mq.front() == val) mq.pop_front();
        return val;
    }
};


/*----------------------------------------------------------------------------*/
int main()
{
    



    return 0;
}
