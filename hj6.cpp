#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

const int MAXN = 2e9 + 20;

bool isPrime[MAXN];
vector<int> mp;


void Initial(long long n)
{
    for(int i=0;i<=n;i++)
    {
        isPrime[i]= true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i = 2;i<=n;i++)
    {
        if(!isPrime[i])
        {
            continue;
        }
        mp.push_back(i);
        if(i > n / i)
        {
            isPrime[i] = false;
        }
        for (int j = i*i;j<=n;j+=i)
        {
            isPrime[j] = false;
        }
    }
}

int main()
{
    long long n;
    cin>>n;
    vector<int> rp;
    for(int i=2;i<sqrt(n)+1;i++)
    {
        while(n%i == 0)
        {
            rp.push_back(i);
            n /=i;
        }
    }
    if(n>2)
    {
        rp.push_back(n);
    }
    for(int j=0;j<rp.size();j++)
    {
        if(j==0)
        {
            cout<<rp[j];
        }
        else
        {
            cout<<' '<<rp[j];
        }
    }
    return 0;
}