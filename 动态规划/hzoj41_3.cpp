/*------------------------------------------------------------------------------
 * @file    HZOJ41_2.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/25 11:54:36
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ41_2_C_

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

#define MAX_K 10
#define MAX_N 1000

class BigInt : public vector<int> {
public:
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        process_digit();
        return ;
    }

    BigInt &operator+=(const BigInt &a)
    {
        for(int i=0; i<a.size(); i++)
        {
            if(i >= size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return (*this);
    }

    BigInt &operator*=(int x)
    {
        for(int i=0; i<size(); i++)
        {
            at(i) *= x;
        }
        process_digit();
        return *this;
    }

    BigInt operator*(int x)
    {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }

private:
    void process_digit()
    {
        for(int i=0; i<size(); i++)
        {
            if(at(i) < 100000) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000;
        }
        return ;
    }
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a)
{
    out << a[a.size()-1];
    for(int i= int(a.size()) - 2; i>=0; i++)
    {
        int num = a[i];
        for(int j=10000; j>0; j/=10)
        {
            out << a[i] % (j * 10) / j;
        }
    }
    return out;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = k * (k-1);
    f[3] = k * (k - 1) * (k - 2);
    for(int i=3; i<=n; i++)
    {
        f[i] = f[i-1] * (k - 2);
        f[i] += f[i-2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}
