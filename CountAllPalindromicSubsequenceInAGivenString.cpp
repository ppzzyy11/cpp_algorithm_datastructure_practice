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

int Helper(int l,int r,vector<vector<int>>& dp,const string& str)
{
	if(l>r) return 0;
	if(l==r) return 1;

	if(dp[l][r]!=-1) return dp[l][r];
	if(str[l]==str[r])
	{
		return dp[l][r]=Helper(l+1,r,dp,str)+Helper(l,r-1,dp,str)+1;
	}else
	{
		return dp[l][r]=Helper(l+1,r,dp,str)+Helper(l,r-1,dp,str)-Helper(l+1,r-1,dp,str);
	}
}

int CountAllPalindromicSubsequenceInAGivenString(const string& str)
{
	vector<vector<int>> dp(str.size(),vector<int>(str.size(),-1));
	return Helper(0,str.size()-1,dp,str);
}

int main()
{
	//string str="abcd";
	//string str="aab";
	string str="aaaa";
	cout<<CountAllPalindromicSubsequenceInAGivenString(str)<<endl;
	return 0;
}
