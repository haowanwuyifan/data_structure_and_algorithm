#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXI = 11111111 +10;
map<int, int> mp;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        map<int, int>::iterator it = mp.find(a);
        if(it == mp.end())
        {
            mp.insert(pair<int, int>(a, b));
        }
        else
        {
            mp[a] += b;
        }
    }
    // sort(mp.begin(), mp.end());
    bool sign=true;
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(sign==true)
        {
            cout<<it->first<<" "<<it->second;
            sign=false;
        }
        else
        {
            cout<<endl;
            cout<<it->first<<" "<<it->second;
        }
    }
    return 0;
}