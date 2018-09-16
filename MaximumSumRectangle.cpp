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

int KadaneAlgorithm(const vector<int>& nums)
{
	int Max=INT_MIN;
	int sum=0;
	for(auto n:nums)
	{
		sum+=n;
		Max=max(Max,sum);
		sum=(sum>0?sum:0);
	}
	return Max;
}

int MaximumSumrectangle(const vector<vector<int>>& mat)
{
	int Max=INT_MIN;
	for(int len=0;len<mat.size();len++)
	{
		vector<int> tmp(mat[0].size(),0);

		//calculate the fisrt bar
		for(int j=0;j<tmp.size();j++)//tmp[j]
		{
			for(int i=0;i<=len;i++)
			{
				tmp[j]+=mat[i][j];
			}
		}
		Max=max(Max,KadaneAlgorithm(tmp));
		//cout<<"len:"<<len<<endl;
		//cout<<tmp;
		for(int i=len+1;i<mat.size();i++)
		{
			for(int j=0;j<tmp.size();j++)
			{
				tmp[j]=tmp[j]-mat[i-len-1][j]+mat[i][j];
			}
		Max=max(Max,KadaneAlgorithm(tmp));
		//cout<<tmp;
		}
		//cout<<endl;


	}
	return Max;
}

int main()
{
	vector<int> nums={-2, -3, 4, -1, -2, 1, 5, -3};
	//cout<<KadaneAlgorithm(nums)<<endl;
	vector<vector<int>> mat=
	{
		{1, 2, -1, -4, -20},
		{-8, -3, 4, 2, 1},
		{3, 8, 10, 1, 3},
		{-4, -1, 1, 7, -6}
	};
	cout<<MaximumSumrectangle(mat)<<endl;
	return 0;
}
