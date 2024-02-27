/*------------------------------------------------------------------------------
 * @file    LUOGU1096.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/19 11:23:56
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _LUOGU1096_C_

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

class BigInt : public vector <int> {
public:
    BigInt() {push_back(0);}
    BigInt(int x)
    {
        push_back(x);
        process_digit();
        return ;
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

    BigInt &operator+=(int x)
    {
        for(int i=0; i<size(); i++)
        {
            at(i) += x;
        }
        process_digit();
        return (*this);
    }

    BigInt operator+(int x)
    {
        BigInt ret(*this);
        ret += x;
        return ret;
    }

private:
    void process_digit()
    {
        for(int i=0; i<size(); i++)
        {
            if(at(i) < 10) continue;
            if(i + 1 >= size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size()>1 && at(size() - 1) == 0) this->pop_back();
        return ;
    }
};

#define MAX_N 200
int f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a)
{
    for(int i=0; i<a.size(); i++)
    {
        out << a[i];
    }
    return out;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    cin >> n;
    f[1] = 2;
    for(int i=2; i<=n; i++){
        f[i] = f[n - 1] * 2 + 2;
    }
    cout << f[n] << endl;
    return 0;
}
