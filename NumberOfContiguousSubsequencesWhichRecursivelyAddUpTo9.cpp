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

ostream& operator <<(ostream& os, const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	return os;
}

int NumberOfSubsequencesWhichRecursivelyAddUpTo9(const string & str)
{
	vector<int> dp(10,0);
	dp[0]=1;
	int cnt=0;

	for(auto s:str)
	{
		int num=s-'0';
		vector<int> tmp(dp.size(),0);
		for(int i=0;i<dp.size();i++)
		{
			int idx=(i+num)%dp.size();
			if(i+num>9) idx++;
			idx=idx%dp.size();
			tmp[idx]+=dp[i];
		}
		for(int i=0;i<dp.size();i++)
		{
			dp[i]=tmp[i];
		}
		dp[0]=1;
		cnt+=dp.back();
	}
	return cnt;
}

int main()
{
	//string str="999";
	string str="4189";
	cout<<NumberOfSubsequencesWhichRecursivelyAddUpTo9(str)<<endl;
    return 0;
}
