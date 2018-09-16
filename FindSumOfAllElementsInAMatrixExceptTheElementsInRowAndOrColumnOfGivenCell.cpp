#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<map>
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
ostream& operator<<(ostream& os,const vector<bool>& nums)
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
			cout<<mat[i][j]<<'\t';
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
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
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

vector<int> FindSumOfAllElementsInAMatrixExceptTheElementsInRowAndOrColumnOfGivenCell(const vector<vector<int>>& mat,const vector<vector<int>>& cells)
{
	vector<int> rows(mat.size(),0);
	vector<int> cols(mat[0].size(),0);
	int sum=0;

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			sum+=mat[i][j];
			rows[i]+=mat[i][j];
			cols[j]+=mat[i][j];
		}
	}

	vector<int> res;
	for(int i=0;i<cells.size();i++)
	{
		int x=cells[i][0];
		int y=cells[i][1];
		res.push_back(sum-rows[x]-cols[y]+mat[x][y]);
	}

	return res;
}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 1, 2},
		{3, 4, 6},
		{5, 3, 2},
	};
	vector<vector<int>> cells=
	{
		{ 0, 0 }, { 1, 1 }, { 0, 1 }
	};
	cout<<FindSumOfAllElementsInAMatrixExceptTheElementsInRowAndOrColumnOfGivenCell(mat,cells)<<endl;
	return 0;
}
