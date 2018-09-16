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

int Helper(const vector<vector<int>>& mat,int i,int j,int k,vector<vector<vector<int>>>& dp)
{
	if(i<0||j<0||k<0) return 0;
	if(i>=mat.size()||j>=mat[i].size()||mat[i][j]<0) return 0;// mat[i][j] must be bigger than or equal ot 0

	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(i==mat.size()-1&&j==mat[i].size()-1) return dp[i][j][k]=(k==mat[i][j]);
	return dp[i][j][k]=Helper(mat,i+1,j,k-mat[i][j],dp)+Helper(mat,i,j+1,k-mat[i][j],dp);
}

int NumbersOfPathsWithExactlyKCoins(const vector<vector<int>>& mat, const int k)
{
	vector<vector<vector<int>>> dp(mat.size(),vector<vector<int>>(mat[0].size(),vector<int>(k+1,-1)));
	int rtn= Helper(mat,0,0,k,dp);
	return rtn;
}

int NumbersOfPathsWithExactlyKCoins2(const vector<vector<int>>& mat,const int k)//bottom-up style
{
	vector<vector<vector<int>>> dp(mat.size(),vector<vector<int>>(mat[0].size(),vector<int>(k+1,0)));
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[0].size()-1;j>=0;j--)
		{
			if(i==mat.size()-1&&j==mat[0].size()-1)
			{
				dp[i][j][mat[i][j]]=1;
			}else
			{
				for(int l=mat[i][j];l<=k;l++)
				{
					if(i!=mat.size()-1)
					{
						dp[i][j][l]+=dp[i+1][j][l-mat[i][j]];
					}
					if(j!=mat[0].size()-1)
					{
						dp[i][j][l]+=dp[i][j+1][l-mat[i][j]];
					}
				}
			}
		}
	}
	return dp[0][0][k];
}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 3},
		{4, 6, 5},
		{3, 2, 1}
	};
	int k=12;
	cout<<NumbersOfPathsWithExactlyKCoins(mat,k)<<endl;
	cout<<NumbersOfPathsWithExactlyKCoins2(mat,k)<<endl;
	return 0;
}
