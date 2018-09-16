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

bool IsPalindromic(const string& str)
{
	int l=0,r=str.size()-1;
	while(l<r)
	{
		if(str[l]!=str[r])
			return 0;
		l++;
		r--;
	}
	return 1;
}

int MinimumAppendsNeededToMakeAStringPalindrome(const string& str)//向后添加
{
	string tmp=str;
	for(int i=0;i<str.size();i++)
	{
		string t=str.substr(i,str.size()-i);
		if(IsPalindromic(t))
			return i;
	}
}
int main()
{
	//string str="abede";
	string str="aabb";
	//string str="edeab";
	cout<<MinimumAppendsNeededToMakeAStringPalindrome(str)<<endl;
	return 0;
}
