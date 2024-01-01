#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 32000 + 10;
const int MAXM = 60 + 10;


int main()
{
    int dp[MAXN];
    int value[MAXM];
    int satisfy[MAXM];
    int attach[MAXM];
    int n, m;
    cin >> n >> m;
    fill(dp, dp+n+1, 0);
    for(int i=0;i<m;i++)
    {
        int v, p, q;
        cin >>v>>p>>q;
        value[i]=v;
        satisfy[i]=p;
        attach[i]=q-1;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=n;j>=value[i];j--)
        {
            if(attach[i]==-1)
            {
                dp[j] = max(dp[j], dp[j-value[i]]+satisfy[i] * j);
            }
            else
            {
                dp[j] = max(dp[j], dp[j-value[i]-value[attach[i]]]+(satisfy[i]+satisfy[attach[i]]) * j);
            }
        }
    }
    cout<<dp[n];
    return 0;
}