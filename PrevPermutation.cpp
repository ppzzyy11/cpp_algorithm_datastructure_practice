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

string PrevPermutation(string& str)
{
	int i=str.size()-1;
	while(i>0)//
	{
		if(str[i-1]>str[i])
		{
			break;
		}
		i--;
	}
	if(i==0)
	{
		reverse(str.begin(),str.end());
		return str;
	}
	int j;
	for(j=str.size()-1;j>=i;j--)
	{
		if(str[j]<str[i-1])
		{
			break;
		}
	}
	swap(str[i-1],str[j]);
	reverse(str.begin()+i,str.end());
	return str;
}

int main()
{
	//string str="DCFEBA";
	string str="AABB";
	//string str="ABC";
	int i=0;
	int len=6;
	while(i<len)
	{
		cout<<PrevPermutation(str)<<endl;
		i++;
	}
	return 0;
}
