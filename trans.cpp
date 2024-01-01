#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    // string str = "abcdef";
    // sort(str.begin(), str.end());
    // next_permutation(str.begin(), str.end());
    // cout << str << endl;
    string str;
    getline(cin, str);
    int position = 0;
    int lastposition = 0;
    int value = 0;
    int time = 0;
    while(true)
    {
        position = str.find(' ', lastposition);
        if (position == -1)
        {
            int length = str.size() - lastposition;
            value += length;
            time++;
            break;
        }
        int length = position - lastposition;
        value += length;
        time++;
        lastposition = position + 1;
    }
    float answer = value * 1.0/time;
    printf("%.2f", answer);
    
    return 0;
}