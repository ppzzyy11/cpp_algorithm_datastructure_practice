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

int CountStringsWithoutConsecutive1s(const int n)
{
	vector<vector<int>> dp(n+1,vector<int>(2,0));
	dp[1][0]=dp[1][1]=1;
	for(int i=2;i<dp.size();i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	return dp.back()[0]+dp.back()[1];
}

int main()
{
	int n=5;//3-5 success
	cout<<CountStringsWithoutConsecutive1s(n)<<endl;
	return 0;
}
