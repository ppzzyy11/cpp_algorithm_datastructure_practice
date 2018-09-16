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
ostream& operator<<(ostream& os,const vector<vector<string>>& mat)
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

int NumberOfStringsWithExactlyKDistinctCharacters(string& str, const int k)
{
	vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));
	int res=0;

	for(int i=0;i<str.size();i++)
	{
		unordered_set<char> rec;
		int cnt=0;
		for(int j=i;j<str.size();j++)
		{
			if(rec.count(str[j])==0)
			{
				cnt++;
				rec.insert(str[j]);
			}
			dp[i][j]=cnt;
			if(dp[i][j]==k)
			{
				cout<<str.substr(i,j-i+1)<<endl;
				res++;
			}
		}
	}
	return res;
}

int main()
{
	string str="aba";
	int k=2;
	cout<<NumberOfStringsWithExactlyKDistinctCharacters(str,k)<<endl;
	return 0;
}

