#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

struct letter{
    int current;
    int last;
    letter(){}
    letter(int c, int l):current(c), last(l){}
};

int main()
{
    string s;
    int k;
    cin>>s>>k;
    int sum = 0;
    letter le[26];
    // int dp[26];
    memset(le, -1, sizeof(le));
    // fill(le, le + 26, (0,0));
    // memset(dp, 0, sizeof(dp));
    int len = s.size();
    int sign = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (le[s[i] - 'a'].current != -1)
        {
            
            // int length = i - le[s[i] - 'a'].last + 1;
            // if (length == k)
            // {
            //     sum++;
            // }
            // else if (length > k)
            // {
            //     continue;
            // }
            // else
            // {
            //     int begin = max(le[s[i] - 'a'].last + 1, i - k + 1);
            //     int end = min(len - 1, le[s[i] - 'a'].last + k - 1);
            //     sum += min(end-i+1, le[s[i] - 'a'].last-begin +1);
            // }
            le[s[i] - 'a'].last = le[s[i] - 'a'].current;
            le[s[i] - 'a'].current = i;
            if (sum == 0 && i<=k-1)
            {
                sum = 1;
            }
            sign++;
        }
        else
        {
            le[s[i] - 'a'].last = -1;
            le[s[i] - 'a'].current = i;
        }
        if(i>k-1)
        {
            if (k>26)
            {
                sum++;
            }
            else if(sign == 1 && s[i-k]==s[i-1] && s[i] !=s[i-1])
            {
                sum+=0;
                sign--;
            }
            else if(sign > 0 && i-le[s[i]-'a'].last <k)
            {
                sum++;
            }
        }
    }
    // int sign = 0;
    // for(int i=0;i<len;i++)
    // {
    //     if(i<k &&sign ==0&&letter[s[i] - 'a'] !=0)
    //     {
    //         sign = 1;
    //     }
    //     letter[s[i] - 'a']++;
    // }
    // dp[0] = sign;
    // sign = 0;
    // for(int j=1;j<=len-k;j++)
    // {
    //     int a = --letter[s[j-1] - 'a'];
    //     int b = ++letter[s[j] - 'a'];
    //     if(a>=2&&)
    // }
    cout<<sum<<endl;
    return 0;
}