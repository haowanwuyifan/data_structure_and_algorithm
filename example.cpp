//先将所有的字符串存入哈希表，key为字符串，value为<出现顺序，出现次数>，顺序取相同的字符串的最小值，次数一直累加
//排序的话，利用set重写比较器，按次数降序，次数相同则按出现顺序排列
//插入过程利用hash时间复杂度可以认为是O(n)
//排序过程set的是红黑树，可以认为是O(nlgn) ,总的复杂度就是这个了 
#include<iostream>
#include<unordered_map>
#include<set>
#include<string.h>
using namespace std;
struct info{//记录出现的顺序，和次数 
	int rank;
	int count;
	info(int rank,int count){
		this->rank=rank;
		this->count=count;
	}
};
struct fullinfo{//一条完整的结果，字符串和次数 
	string file;
	int rank;
	int count;
	fullinfo(string file,int rank,int count){
		this->file=file;
		this->rank=rank;
		this->count=count;
	}
};
struct classcomp {//set的比较器 
  bool operator()(const struct fullinfo f1,const struct fullinfo f2){
		if(f1.count==f2.count)
			return f1.rank<f2.rank;
		return f1.count>f2.count;
	}
};
typedef struct info INFO;
typedef struct fullinfo FULLINFO;
int main(){
	unordered_map<string,INFO> record;
	unordered_map<string,INFO>::iterator it;
	unordered_map<string,INFO>::const_iterator itfind;
	set<FULLINFO,classcomp> ret;
	set<FULLINFO,classcomp>::iterator sit;
	string linestr;//一行输入 
	string file;//文件名+行号 
	int pos;//空格的位置 
	int i=1;
	while(getline(cin,linestr)){
		if(linestr.length()==0)
			break;
		pos=linestr.rfind(&quot;\\&quot;);
		file=linestr.substr(pos+1);//拆分得到最后的filename和count 
		itfind=record.find(file);//在map中查看是否已经有了该字符串，没有则插入，有则次数加1 
		if(itfind==record.end()){
			INFO tmpi(i,1);
			record.insert(pair<string,INFO>(file,tmpi));
		}
		else{
			INFO tmpi(itfind->second.rank,itfind->second.count+1);
			record.erase(file);
			record.insert(pair<string,INFO>(file,tmpi));
		}
		i++;
	}
	for(it=record.begin();it!=record.end();it++){
		FULLINFO tmpfull(it->first,it->second.rank,it->second.count);//构建排序的set集合 
		ret.insert(tmpfull);
	}
	for(i=0,sit=ret.begin();sit!=ret.end()i<8;++sit,++i){//最多输出8条记录，file少于16位 
		if(file.find(&quot; &quot;)<=16){ 
			cout<(*sit).file<&quot; &quot;<(*sit).count<endl;
			} 
		else{
			cout<(*sit).file.substr(file.find(&quot; &quot;)-16)<&quot; &quot;<(*sit).count<endl;
		} 
		
	}
	return 0;
}