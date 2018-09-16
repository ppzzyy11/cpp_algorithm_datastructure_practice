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

int SearchInARowWiseAndColumnWirseSortedMatrix(const vector<vector<int>>& mat, const int x)
{
	if(mat.size()<0) return INT_MIN;
	int j=mat[0].size()-1;// 从右上向左下进行转移
	int i=0;
	while(i<mat.size()&&j>=0)
	{
		if(mat[i][j]<x)
		{
			i++;
		}else if(mat[i][j]>x)
		{
			j--;
		}else
		{
			cout<<"Found at ("<<i<<','<<j<<")"<<endl;
			return mat[i][j];
		}
	}
	cout<<"Element Not Found"<<endl;
	return INT_MIN;
}

int main()
{
	vector<vector<int>> mat={
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50}};
	cout<<SearchInARowWiseAndColumnWirseSortedMatrix(mat,31)<<endl;
	return 0;
}
