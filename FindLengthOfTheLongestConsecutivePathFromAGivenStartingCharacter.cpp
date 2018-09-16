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

int Helper(int i,int j,const vector<vector<char>>& mat, vector<vector<int>>& dp)
{
	if(i<0||j<0) return 0;
	if(i>=mat.size()||j>=mat[0].size()) return 0;

	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=1;

	if(i>0&&mat[i][j]+1==mat[i-1][j]) dp[i][j]=max(dp[i][j],1+Helper(i-1,j,mat,dp));
	if(j>0&&mat[i][j]+1==mat[i][j-1]) dp[i][j]=max(dp[i][j],1+Helper(i,j-1,mat,dp));
	if(i<mat.size()-1&&mat[i][j]+1==mat[i+1][j]) dp[i][j]=max(dp[i][j],1+Helper(i+1,j,mat,dp));
	if(j<mat[0].size()-1&&mat[i][j]+1==mat[i][j+1]) dp[i][j]=max(dp[i][j],1+Helper(i,j+1,mat,dp));

	if(i>0&&j>0&&mat[i][j]+1==mat[i-1][j-1]) dp[i][j]=max(dp[i][j],1+Helper(i-1,j-1,mat,dp));
	if(i>0&&j<mat[0].size()-1&&mat[i][j]+1==mat[i-1][j+1]) dp[i][j]=max(dp[i][j],1+Helper(i-1,j+1,mat,dp));
	if(i<mat.size()-1&&j>0&&mat[i][j]+1==mat[i+1][j-1]) dp[i][j]=max(dp[i][j],1+Helper(i+1,j-1,mat,dp));
	if(i<mat.size()-1&&j<mat[0].size()-1&&mat[i][j]+1==mat[i+1][j+1]) dp[i][j]=max(dp[i][j],1+Helper(i+1,j+1,mat,dp));

	return dp[i][j];
}

int FindLengthOfTheLongestConsecutivePathFromAGivenStartingCharacter(const vector<vector<char>>& mat,const char ch)
{
	if(mat.size()==0) return 0;
	if(mat[0].size()==0) return 0;
	int res=0;
	vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==ch)
			{
				res=max(res,Helper(i,j,mat,dp));
			}
		}
	}
	return res;
}


int main()
{
	vector<vector<char>> mat=
	{
		//{'a', 'c', 'd'},
		//{'h', 'b', 'e'},
		//{'i', 'g', 'f'}

		{'b', 'e', 'f'},
		{'h', 'd', 'a'},
		{'i', 'c', 'a'}
	};
	//char ch='e';
	char ch='b';
	cout<<FindLengthOfTheLongestConsecutivePathFromAGivenStartingCharacter(mat,ch)<<endl;
	return 0;
}
