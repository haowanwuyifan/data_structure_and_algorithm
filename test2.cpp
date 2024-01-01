#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

long long phase(int n)
{
    long long answer = 1;
    if (n == 0)
    {
        return 1;
    }
    for(int i =1;i<=n;i++)
    {
        answer *= i;
    }
    return answer;
}

int main() {
    string str;
    cin >> str;
    int letter[26];
    memset(letter, 0, sizeof(letter));
    for (int i = 0; i < str.size(); i++)
    {
        letter[str[i] - 'A']++;
    }
    long long answer = 0;
    long long de = 1;
    for (int i = 0; i < 26; i++)
    {
        de *= phase(letter[i]);
    }
    answer = phase(str.size())/de;
    cout << answer;
    return 0;
}