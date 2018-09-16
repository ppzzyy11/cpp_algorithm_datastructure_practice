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

int LengthOfLongestNonPalindromicSubstring(const string& str)
{
	if(str.size()<=1) return 0;
	bool flag=0;
	for(int i=1;i<str.size();i++)
	{
		if(str[i]!=str[0])
		{
			if(flag==0)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
		return 0;
	return IsPalindromic(str)?str.size()-1:str.size();
}

int main()
{
	string str="bb";
	//string str="abba";
	cout<<LengthOfLongestNonPalindromicSubstring(str)<<endl;
	return 0;
}
