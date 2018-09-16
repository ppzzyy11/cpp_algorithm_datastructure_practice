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

int FindTheRowWithMaximumNumbersOf1S(const vector<vector<bool>> mat)
{
	int res=0;
	int Min=INT_MAX;

	for(int k=0;k<mat.size();k++)
	{
		const vector<bool>&m =mat[k];
		int i=0,j=m.size()-1;
		if(m[0]==1) return k;
		while(i<=j)//这是一个不成熟的二分法,常识寻找分界,第一个1或者最后一个0,还要考虑边界
		{
			int mid=i+(j-i)/2;
			//if(k==2)
			//cout<<i<<":"<<mid<<":"<<j<<endl;
			if(mid==0||(m[mid]==0&&m[mid+1]==1))
			{
				if(mid<Min)
				{
					Min=mid;
					res=k;
				}
				//cout<<k<<":"<<Min<<endl;
				break;
			}else if(m[mid+1]==0)
			{
				i=mid+1;
			}else
			{
				j=mid-1;
			}
		}
	}
	return res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		{0, 0, 0, 1},
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};
	cout<<FindTheRowWithMaximumNumbersOf1S(mat)<<endl;
	return 0;
}
