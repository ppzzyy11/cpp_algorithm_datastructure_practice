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

string CommonCharactersOfTwoStringsInAlphabeticalOrder(const string& str1, const string& str2)
{
	vector<int> rec1(256,0);
	vector<int> rec2(256,0);
	for(auto s:str1)
	{
		rec1[s]++;
	}
	for(auto s:str2)
	{
		rec2[s]++;
	}
	string res="";
	for(int i=0;i<rec1.size();i++)
	{
		int times=min(rec1[i],rec2[i]);
		while(times)
		{
			res+=(char)i;
			times--;
		}
	}
	return res;
}

int main()
{
	//string str1="geeks";
	//string str2="forgeeks";
	string str1="hhhhhello";
	string str2="gfghhmh";
	cout<<CommonCharactersOfTwoStringsInAlphabeticalOrder(str1,str2)<<endl;
	return 0;
}

