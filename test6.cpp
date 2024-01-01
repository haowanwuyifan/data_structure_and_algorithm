#include<iostream>
#include<string>
using namespace std;

int nexttable[100];
string pattern;

void GetNextTable(int m)
{
    int j=0;
    nexttable[j]= -1;
    int t = nexttable[j];
    while(j<m)
    {
        if(t == -1 || pattern[j] == pattern[t])
        {
            j++;
            t++;
            nexttable[j] = t;
        }
        else
        {
            t = nexttable[t];
        }
    }
}
 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pattern[i];
    }
    GetNextTable(n);
    return 0;
}
