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
ostream& operator<<(ostream& os,const vector<vector<vector<int>>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			for(int k=0;k<mat[i][j].size();k++)
			{
				cout<<mat[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return os;
}

int Helper(const vector<vector<char>>& mat ,int i,int j, int drt,vector<vector<vector<int>>>& dp)
{
	if(i<0||j<0) return 0;
	if(i>=mat.size()||j>=mat[i].size()) return 0;
	if(dp[i][j][drt]!=-1) return dp[i][j][drt];
	if(mat[i][j]=='#') return dp[i][j][drt]=0;
	int res=0;
	if(mat[i][j]=='E')
	{
		res=0;
	}else
	{
		res=1;
	}
	if(drt==0)//face right
	{
		return dp[i][j][drt]=res+max(Helper(mat,i,j+1,0,dp),Helper(mat,i+1,j,1,dp));
	}else
	{
		return dp[i][j][drt]=res+max(Helper(mat,i,j-1,1,dp),Helper(mat,i+1,j,0,dp));
	}
}


int CollectMaximumCoinsBeforeHittingADeadEnd(const vector<vector<char>>& mat)
{
	int i=0,j=0,drt=0;
	vector<vector<vector<int>>> dp(mat.size(),vector<vector<int>>(mat[0].size(),vector<int>(2,-1)));
	int rtn= Helper(mat,i,j,drt,dp);
	return rtn;
}



int main()
{
	vector<vector<char>> mat=
	{
		{'E', 'C', 'C', 'C', 'C'},
		{'C', '#', 'C', '#', 'E'},
		{'#', 'C', 'C', '#', 'C'},
		{'C', 'E', 'E', 'C', 'E'},
		{'C', 'E', '#', 'C', 'E'}
	};
	cout<<CollectMaximumCoinsBeforeHittingADeadEnd(mat)<<endl;
	return 0;
}
