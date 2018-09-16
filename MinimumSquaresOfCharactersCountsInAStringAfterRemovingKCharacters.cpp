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

int MinimumSquaresOfCharactersCountsInAStringAfterRemoingKCharacters(const string& str, int k)
{
	vector<int> rec(256,0);
	for(auto s:str)
	{
		rec[s]++;
	}
	make_heap(rec.begin(),rec.end());
	while(k)
	{
		if(rec[0]==0)
		{
			return -1;
		}
		rec[0]--;
		make_heap(rec.begin(),rec.end());
		k--;
		//cout<<rec<<endl;
	}

	int num=0;
	for(auto r:rec)
	{
		num+=r*r;
	}
	return num;
}

int main()
{
	//string  str="abccc";
	//int K=1;
	string  str="aaab";
	int K=2;
	cout<<MinimumSquaresOfCharactersCountsInAStringAfterRemoingKCharacters(str,K)<<endl;
	return 0;
}

