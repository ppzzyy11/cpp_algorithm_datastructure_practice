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

int Helper(int l,int r,vector<vector<int>>& dp,const string& str)
{
	if(l>r) return 0;
	if(l==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	if(str[l]==str[r]) return Helper(l+1,r-1,dp,str);
	else
	{
		return min(Helper(l+1,r,dp,str),Helper(l,r-1,dp,str))+1;
	}
}

int MinimumInsertionsToFormAPalindrome(const string& str)
{
	vector<vector<int>> dp(str.size(),vector<int>(str.size(),-1));
	return Helper(0,str.size()-1,dp,str);
}

int main()
{
	//string str="ab";
	//string str="aa";
	string str="abcda";
	cout<<MinimumInsertionsToFormAPalindrome(str)<<endl;
	return 0;
}
