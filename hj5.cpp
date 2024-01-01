#include<iostream>
#include<string>
using namespace std;
 
// int main(){
//     string str;
//     while(cin>>str){
//         cout << stoi(str,0,16) << endl;
//     }
// }
int Char2Int(char str)
{
    if (str>='A' && str<='F')
    {
        return str - 'A' + 10;
    }
    else
    {
        return str - '0';
    }

}
 
int main(){
    string str;
    while(cin>>str){
        // cout << stoi(str,0,16) << endl;
        string sub = str.substr(2);
        int num = 0;
        int n = sub.size()-1;
        int st = 1;
        while(n>=0)
        {
            num += st * Char2Int(sub[n]);
            n--;
            st *= 16;
        }
        cout<< num;
    }
}