#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(string a, string b)
{
    // vector<string> sequence = {"3","4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "JOKER"};
    string sequence = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
    if(sequence.find(a) < sequence.find(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getnumber(string a)
{
    int answer = 0;
    int position =0;
    while(position != -1)
    {
        position = a.find(" ", position+1);
        answer ++;
    }
    return answer;
}

struct card
{
    string ca;
    int length;
    card(string s, int l):ca(s), length(l){}
    bool operator <(card const b) const
    {
        if(b.ca == "joker JOKER")
        {
            return true;
        }
        else if(ca == "joker JOKER")
        {
            return false;
        }
        else if(b.length == 7 && length != 7)
        {
            return true;
        }
        else if(length == b.length)
        {
            int position = ca.find(" ");
            string ta = ca.substr(0, position);
            string tb = b.ca.substr(0, position);
            return compare(ta, tb);
        }
        else if(ca.find(" ") == -1&&b.ca.find(" ")==-1)
        {
            return compare(ca, b.ca);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string str;
    getline(cin, str);
    int positon = str.find('-');
    string a = str.substr(0, positon);
    string b = str.substr(positon+1);
    card pa = card(a, getnumber(a));
    card pb = card(b, getnumber(b));
    if(pa.length !=4 && pb.length != 4)
    {
        if(pa.ca != "joker JOKER" && pb.ca != "joker JOKER" && pa.length != pb.length)
        {
            cout<<"ERROR";
        }
        else if(pa<pb)
        {
            cout<<pb.ca;
        }
        else
        {
            cout<<pa.ca;
        }
    }
    else
    {
        if(pa<pb)
        {
            cout<<pb.ca;
        }
        else
        {
            cout<<pa.ca;
        }
    }
    return 0;
}