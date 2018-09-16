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
ostream& operator<<(ostream& os,const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<char>& chs)
{
	for(int i=0;i<chs.size();i++)
	{
		cout<<chs[i]<<' ';
	}
	cout<<endl;
	return os;
}

bool IsPalidromic(const string& str)
{
	if(str.size()<=1) return 1;
	int l=0,r=str.size()-1;
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			return 0;
		}
		l++;
		r--;
	}
	return 1;
}

bool PalindromePair(const vector<string>& strs)
{
	unordered_set<string> rec;
	for(auto str:strs)
	{
		//cout<<str<<endl;
		reverse(str.begin(),str.end());
		if(rec.count(str)!=0) return 1;
		rec.insert(str);
		reverse(str.begin(),str.end());
		for(int i=1;i<str.size()-1;i++)
		{
			//cout<<i<<endl;
			string tmp0=str.substr(i,str.size()-i);
			string tmp1=str.substr(0,i);
			if(IsPalidromic(tmp0))
			{
				reverse(tmp1.begin(),tmp1.end());
				if(rec.count(tmp1)!=0) return 1;
				rec.insert(tmp1);
				reverse(tmp1.begin(),tmp1.end());
			}
			if(IsPalidromic(tmp1))
			{
				reverse(tmp0.begin(),tmp0.end());
				if(rec.count(tmp0)!=0) return 1;
				rec.insert(tmp0);
				reverse(tmp0.begin(),tmp0.end());
			}
		}
	}
	return 0;
}

int main()
{
	vector<string> strs=
	//{"geekf", "geeks", "or", "keeg", "abc", "bc"};
	//{"abc", "xyxcba","geekst", "or", "keeg", "bc"};
	{"abaded", "ded","aba"};
   	cout<<PalindromePair(strs)<<endl;
	return 0;
}

