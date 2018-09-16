#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>//make_heap
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void Helper(const string& str,int i,string& tmp,vector<string>& res)
{
	if(i==str.size())
	{
		res.push_back(tmp);
		return ;
	}
	if(str[i]=='?')
	{
		tmp+='0';
		Helper(str,i+1,tmp,res);
		tmp.pop_back();

		tmp+='1';
		Helper(str,i+1,tmp,res);
		tmp.pop_back();
	}else
	{
		tmp+=str[i];
		Helper(str,i+1,tmp,res);
		tmp.pop_back();
	}

}
void GenerateAllBinaryStringsFromGivenPattern(const string& str)
{
	string tmp="";
	vector<string> res;
	Helper(str,0,tmp,res);
	for(auto r:res)
	{
		cout<<r<<endl;
	}
}

int main()
{
	string str="1??0?101";
	GenerateAllBinaryStringsFromGivenPattern(str);
	return 0;
}
