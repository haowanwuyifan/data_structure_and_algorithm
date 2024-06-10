#include <iostream>
#include <string>
#include <vector>

#define BASE (1000000000 + 7)

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    vector<int> dp(n + 1, 0);
    //int ans = 0;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        cnt[ind] += 1;
        long long num = 0;
        for(int j=0; j<26; j++)
        {
            if(j == ind) continue;
            num = (num + cnt[j]) % BASE;
        }
        dp[i + 1] = (dp[i] + num) % BASE;
    }
    return dp[n];
}