#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> que;

int main()
{
    int n;
    cin>>n;
    // vector<int>::iterator it = que.begin();
    while(n>0)
    {
        int t = n % 10;
        if(!que.empty())
        {
            vector<int>::iterator it = find(que.begin(), que.end(), t);
            if(it == que.end())
            {
                que.push_back(t);
            }
            
        }
        else
        {
            que.push_back(t);
        }
        n /= 10;
    }
    for(vector<int>::iterator it=que.begin(); it!=que.end();it++)
    {
        cout<<*it;
    }
    return 0;
}