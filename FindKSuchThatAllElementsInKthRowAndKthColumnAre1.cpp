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

int FindKSuchThatAllElementsInKthRowAndKthColumnAre1(const vector<vector<int>>& mat)
{
	int i=0,j=mat[0].size();
	int res=-1;
	while(i<mat.size()&&j>=0)
	{
		if(mat[i][j]==0)
		{
			while(j>=0&&(mat[i][j]==0||i==j))
			{
				j--;
			}
			if(j==-1)
			{
				res=i;
				break;
			}
		}else
		{
			while(i<mat.size()&&(mat[i][j]==1||i==j))
			{
				i++;
			}
			if(i==mat.size())
			{
				res=j;
				break;
			}
		}
	}
	if(res==-1) return -1;
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][res]!=1&&i!=res)
		{
			return -1;
		}
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[res][j]!=0&&j!=res)
		{
			return -1;
		}
	}
	return res;
}


int main()
{
	vector<vector<int>> mat=
	{
		//{1, 0, 0, 0},
		//{1, 1, 1, 0},
		//{1, 1, 0, 0},
		//{1, 1, 1, 0},

		//{0, 1, 1, 0, 1},
		//{0, 0, 0, 0, 0},
		//{1, 1, 1, 0, 0},
		//{1, 1, 1, 1, 0},
		//{1, 1, 1, 1, 1}

		//{0, 1, 1, 0, 1},
		//{0, 0, 0, 0, 0},
		//{1, 1, 1, 0, 0},
		//{1, 0, 1, 1, 0},
		//{1, 1, 1, 1, 1}

		{0, 0, 1, 1, 0},
		{0, 0, 0, 1, 0},
		{1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
	};
	cout<<FindKSuchThatAllElementsInKthRowAndKthColumnAre1(mat)<<endl;
	return 0;
}
