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

int MaximumSizeSquareSubMatrixWithAll1S(const vector<vector<bool>>& mat)//two ways
{
	int res=0;
	vector<int> hgts(mat.size(),0);
	hgts.push_back(0);
	for(auto m:mat)
	{
		for(int i=0;i<m.size();i++)
		{
			if(m[i]==0)
			{
				hgts[i]=0;
			}else
			{
				hgts[i]++;
			}
		}
		stack<int> st;
		st.push(-1);
		for(int i=0;i<hgts.size();i++)
		{
			while(st.size()!=1&&hgts[st.top()]>=hgts[i])
			{
				int top=st.top();
				st.pop();
				res=max(res,(j-st.top()-1)*hgts[top]);
			}
			st.push(hgts[i]);
		}
	}
	return res;
}

int MaximumSizeSquareSubMatrixWithAll1S2(const vector<vector<bool>>& mat)
{
	int res=0;
	vector<vector<int>> dp(mat.size()+1,vector<int>(mat[0].size()+1,0));
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[0].size();j++)
		{
			if(mat[i][j]==0)
			{
				dp[i+1][j+1]=0;
			}else
			{
				dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
			}
			res=max(res,dp[i+1][j+1]);
		}
	}
	return res*res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}
	};
	cout<<MaximumSizeSquareSubMatrixWithAll1S(mat)<<endl;
	cout<<MaximumSizeSquareSubMatrixWithAll1S2(mat)<<endl;
	return 0;
}
