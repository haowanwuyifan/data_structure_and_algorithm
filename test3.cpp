#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXL = 50 +10;
const int MAXN = 1000 + 10;

struct filename
{
    string name;
    string row;
    int time;
    int order;
    filename(string n, string r, int t,int o):name(n), row(r), time(t), order(o){}  
    bool operator<(filename b) const
    {
        if(time == b.time)
        {
            return order < b.order;
        }
        return time > b.time;
    }
};




int main() {
    string str;
    vector<filename> log;
    int o =0;
    while(getline(cin, str))
    {
        if (str.size()==0)
        {
            break;
        }
        int position = str.find(' ');
        string wholename = str.substr(0, position);
        string row = str.substr(position+1);
        position=0;
        int lastposition = 0;
        while(position!=-1)
        {
            lastposition = position;
            position = wholename.find("\\", lastposition+1);
        }
        string realname = wholename.substr(lastposition+1);
        filename s = filename(realname, row, 1, o);
        o++;
        if(!log.empty())
        {
            for(int i = 0;i<log.size();i++)
            {
                if(log[i].name == s.name && log[i].row == s.row)
                {
                    log[i].time++;
                    break;
                }
            }
            log.push_back(s);
        }
        else
        {
            log.push_back(s);
        }
        
    }
    sort(log.begin(), log.end());
        if(log.size() > 8)
        {
            for(int i=0;i<8;i++)
            {
                if(log[i].name.size()>16)
                {
                    cout<<log[i].name.substr(log[i].name.size()-16)<<' '<<log[i].row<<" "<<log[i].time<<endl; 
                }
                else
                {
                    cout<<log[i].name<<' '<<log[i].row<<" "<<log[i].time<<endl;
                }
            }
        }
        else{
            for(int i=0;i<log.size();i++)
            {
                if(log[i].name.size()>16)
                {
                    cout<<log[i].name.substr(log[i].name.size()-16)<<' '<<log[i].row<<" "<<log[i].time<<endl; 
                }
                else
                {
                    cout<<log[i].name<<' '<<log[i].row<<" "<<log[i].time<<endl;
                }
            }
        }
    return 0;
}
// 64 位输出请用 printf("%lld")