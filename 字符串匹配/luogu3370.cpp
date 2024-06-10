/*------------------------------------------------------------------------------
 * @file    LUOGU3370.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/04/10 12:00:45
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU3370_C_

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
#include <unordered_map>

using namespace std;

int get_hash(string &s)
{
    int base = 131, h = 0;
    for(int i=0 ;s[i]; i++)
    {
        h = h * base + s[i];
    }
    return h;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, hash_code, ans = 0;
    unordered_map<int, vector<string>> h;
    string s;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        hash_code = get_hash(s);
        if(h.find(hash_code) == h.end())
        {
            ans += 1;
            h[hash_code].push_back(s);
        }
        else
        {
            int flag = 1;
            for(auto t : h[hash_code])
            {
                if(t != s) continue;
                flag = 0;
                break;
            }
            if(flag)
            {
                ans += 1;
                h[hash_code].push_back(s);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
