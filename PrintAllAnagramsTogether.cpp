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

vector<vector<string>> PrintAllAnagramsTogether(const vector<string>& strs)
{
	vector<vector<string>> res;
	vector<vector<int>> recs;
	for(auto str:strs)
	{
		vector<int> rec(256,0);
		for(auto s:str)
		{
			rec[s]++;
		}
		int i=0;
		for(;i<recs.size();i++)
		{
			if(rec==recs[i])
			{
				break;
			}
		}
		if(i==recs.size())
		{
			recs.push_back(rec);
			vector<string> tmp;
			tmp.push_back(str);
			res.push_back(tmp);
		}else
		{
			res[i].push_back(str);
		}
	}
	cout<<res<<endl;
	return res;
}

int main()
{
	vector<string> strs=
	{"cat", "dog", "tac", "god", "act"}
	;
	PrintAllAnagramsTogether(strs);
	return 0;
}

