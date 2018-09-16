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

int FindACommonElementInAllRowsOfAGivenRowWiseSortedMatrix(const vector<vector<int>>& mat)
{
	vector<int> idx(mat.size(),mat[0].size()-1);
	int MinIdx=0;
	while(MinIdx>=0)
	{
		for(int i=0;i<mat.size();i++)
		{
			if(mat[i][idx[i]]<mat[MinIdx][idx[MinIdx]])
			{
				MinIdx=i;
			}
		}
		if(MinIdx<0) return -1;

		int EqCnt=0;
		for(int i=0;i<mat.size();i++)
		{
			if(mat[i][idx[i]]==mat[MinIdx][idx[MinIdx]])
			{
				EqCnt++;
			}else
			{
				idx[i]--;
			}
		}
		if(EqCnt==mat.size()) return mat[MinIdx][idx[MinIdx]];
		for(int i=0;i<idx.size();i++)
		{
			if(idx[i]<0) return -1;
		}
	}
	return -1;
}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 3, 4, 5},
		{2, 4, 5, 8, 10},
		{3, 5, 7, 9, 11},
		{1, 3, 5, 7, 9},
	};
	cout<<FindACommonElementInAllRowsOfAGivenRowWiseSortedMatrix(mat)<<endl;
	return 0;
}
