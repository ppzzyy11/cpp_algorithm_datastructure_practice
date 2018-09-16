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

int MinimumDeletionsToMakeAStringPalindrome(const string& str)
{
	vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));

	for(int i=str.size()-1;i>=0;i--)
	{
		for(int j=i;j<str.size();j++)
		{
			if(j==i) dp[i][j]=0;
			else
			{
				if(str[i]==str[j])
				{
					if(i+1==j) dp[i][j]=0;
					else
					{
						dp[i][j]=dp[i+1][j-1];
					}
				}else
				{
					dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
				}
			}
		}
	}
	//cout<<dp;
	return dp[0][str.size()-1];
}


int main()
{
	string str="geeksforgeeks";
	//string str="aebcbda";
	cout<<MinimumDeletionsToMakeAStringPalindrome(str)<<endl;
	return 0;
}
