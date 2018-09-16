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

ostream& operator<<(ostream& os,const set<string>& strs)
{
	for(auto it=strs.begin();it!=strs.end();it++)
	{
		cout<<*it<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}

bool IfBothHalvesOfTheStringHaveSameSetOfCharacters(const string& str)
{
	if(str.size()%2==1) return 0;

	vector<int> rec(256,0);

	for(int i=0;i<str.size()/2;i++)
	{
		rec[str[i]]++;
	}
	for(int i=str.size()/2;i<str.size();i++)
	{
		rec[str[i]]--;
	}
	for(int i=0;i<rec.size();i++)
	{
		if(rec[i]!=0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//string str="aababb";
	string str="abccab";
	cout<<IfBothHalvesOfTheStringHaveSameSetOfCharacters(str)<<endl;
	return 0;
}
