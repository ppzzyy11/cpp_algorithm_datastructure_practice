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
struct Solution// GetDp0 GetDp1 需要相互调用
{

	int GetDp1(int n,int k,vector<vector<int>>& dp0,vector<vector<int>>& dp1)
	{
		if(n<=k) return 0;
		if(dp1[n][k]!=-1)
		{
			return dp1[n][k];
		}
		return dp1[n][k]=GetDp0(n-1,k,dp0,dp1)+GetDp1(n-1,k-1,dp0,dp1);
	}
	int GetDp0(int n,int k,vector<vector<int>>& dp0,vector<vector<int>>& dp1)
	{
		if(n<=k) return 0;
		if(dp0[n][k]!=-1)
		{
			return dp0[n][k];
		}
		return dp0[n][k]=GetDp0(n-1,k,dp0,dp1)+GetDp1(n-1,k,dp0,dp1);
	}
	int Helper(int n,int k,vector<vector<int>> &dp0,vector<vector<int>>& dp1)
	{
		cout<<GetDp0(n,k,dp0,dp1)<<endl;
		cout<<GetDp1(n,k,dp0,dp1)<<endl;
		return GetDp0(n,k,dp0,dp1)+GetDp1(n,k,dp0,dp1);
	}
	int CountBinaryStringsWithKTimesAppearingAdjacentTwoSetBits(const int& n,const int& k)
	{
		if(n<=k) return -1;
		vector<vector<int>> dp0(n+1,vector<int>(k+1,-1));
		vector<vector<int>> dp1(n+1,vector<int>(k+1,-1));
		dp0[1][0]=dp1[1][0]=1;
		return Helper(n,k,dp0,dp1);
	}

};
int main()
{
	Solution s;
	cout<<s.CountBinaryStringsWithKTimesAppearingAdjacentTwoSetBits(4,1)<<endl;
	return 0;
}
