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

char KthNonRepeatingCharacter(const string& str,int k)
{
	vector<int> cnt;
	vector<char> rec;
	unordered_map<char,int> hash;
	for(auto s:str)
	{
		if(hash.count(s)!=0)
		{
			cnt[hash[s]]++;
		}else
		{
			hash[s]=cnt.size();
			cnt.push_back(1);
			rec.push_back(s);
		}
	}
	for(int i=0;i<cnt.size();i++)
	{
		if(cnt[i]==1)
		{
			k--;
			if(k==0)
			{
				return rec[i];
			}
		}
	}
}

int main()
{
	string str="geeksforgeeks";
	int k=3;//2 2 3 4 5
	cout<<KthNonRepeatingCharacter(str,k)<<endl;
	return 0;
}

