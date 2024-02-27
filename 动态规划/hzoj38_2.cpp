/*------------------------------------------------------------------------------
 * @file    HZOJ38_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/14 17:51:45
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ38_2_C_

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

class BigInt : public vector<int> {
public:
    BigInt() {push_back(0);}
    BigInt(int x)
    {
        this->push_back(x);
        process_digit();
    }

    void process_digit()
    {
        for(int i=0; i<size(); i++)
        {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }

    BigInt operator+=(const BigInt &a)
    {
        for(int i=0; i<a.size(); i++)
        {
            if(i >= size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return *this;
    }

    BigInt operator+(const BigInt &a)
    {
        BigInt ret(*this);
        ret += a;
        return ret;
    }
};

ostream &operator<<(ostream &out, const BigInt &a)
{
    for(int i=a.size()-1; i>=0; i++)
    {
        out << a[i];
    }
    return out;
}

BigInt f[105] = {0};


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    for(int i=3; i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[n] << endl;
    return 0;
}
