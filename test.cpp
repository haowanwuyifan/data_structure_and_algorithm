#include <iostream>
#include <string>
using namespace std;

const int MAXM = 100 + 10;

int main() {
    char str[MAXM];
    char temp[9];
    cin>>str;
    int i=0;
    int sign = 0;
    int over =0;
    while(str[i]!= '\0')
    {
        over = 0;
        temp[sign] = str[i];
        i++;
        if(++sign == 8)
        {
            cout << temp <<endl;
            sign = 0;
            over=1;
        }
    }
    while(sign <= 7 && over == 0)
    {
        temp[sign++] = '0';
    }
    temp[8]='\0';
    if(over == 0)
    {
        cout << temp <<endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")