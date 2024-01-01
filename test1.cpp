#include<iostream>
#include<string>


// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
using namespace std;
string littlevowel = "aeiou";
string captinvowel = "AEIOU";

int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    string str;
    getline(cin, str);
    for (int i = 0;i<str.size();i++)
    {
        if(littlevowel.find(str[i]) != -1)
        {
            str[i] = captinvowel[littlevowel.find(str[i])];
        }
        else if(captinvowel.find(str[i]) != -1)
        {
            str[i] = littlevowel[captinvowel.find(str[i])];
        }
    }
    cout<<str;
    return 0;
}
