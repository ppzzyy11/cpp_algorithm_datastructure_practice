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



int CountOfPalindromicSubstringsInAnIndexRange(const string& str,const int l,const int r)
{
	if(l>r) return 0;
	if(l<0||r>=str.size()) return 0;

	vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));
	vector<vector<bool>> isPalin(str.size(),vector<bool>(str.size(),0));

	for(int i=str.size()-1;i>=0;i--)
	{
		for(int j=i;j<str.size();j++)
		{
			if(j==i)
			{
				dp[i][j]=1;
				isPalin[i][j]=1;
			}else
			{
				isPalin[i][j]=((i+1>=j-1|| isPalin[i+1][j-1] )&&(str[i]==str[j]));
				dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+isPalin[i][j];
			}
		}
	}

	return dp[l][r];
}

int main()
{
	string str="xyaabax";
	int l=3;
	int r=5;
	//int l=2;
	//int r=3;
	cout<<CountOfPalindromicSubstringsInAnIndexRange(str,l,r)<<endl;
	return 0;
}
