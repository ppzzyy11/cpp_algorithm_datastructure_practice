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

int MaximumSizeSquareSubMatrixWithAll1s(const vector<vector<int>>& mat)
{
	int res=0;
	if(mat.size()==0) return 0;
	vector<int> h(mat[0].size(),0);
	for(int i=0;i<mat.size();i++)
	{
		const vector<int> & nums=mat[i];
		for(int j=0;j<nums.size();j++)
		{
			if(nums[j]==1)
			{
				h[j]++;
			}else
			{
				h[j]=0;
			}
		}
		//cout<<h<<endl;
		stack<int> st;
		st.push(-1);
		for(int j=0;j<h.size();j++)
		{
			while(st.top()!=-1&&h[st.top()]>=h[j])
			{
				//cout<<st.top()<<endl;
				int top=st.top();
				st.pop();
				res=max(res,h[top]*(j-st.top()-1));
			}
			st.push(j);
		}
	}
	return res;
}
int MaximumSizeSquareSubMatrixWithAll1S(const vector<vector<int>>& mat)//Only for Square
{
	if(mat.size()==0) return 0;
	vector<vector<int>> sum(mat.size(),vector<int>(mat[0].size(),0));
	int l=0;
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(i==0||j==0)
			{
				sum[i][j]=(mat[i][j]==1);
			}else
			{
				if(mat[i][j]==1)
				{
					sum[i][j]=min(sum[i-1][j],min(sum[i][j-1],sum[i-1][j-1]))+1;
					l=max(l,sum[i][j]);
				}else
				{
					sum[i][j]=0;
				}
			}
		}
	}
	return l*l;
}

int main()
{
	vector<vector<int>> mat=
	{
		{0,1,1,0,1},
		{1,1,0,1,0},
		{0,1,1,1,0},
		{1,1,1,1,0},
		{1,1,1,1,1},
		{0,0,0,0,0}
	};
	cout<<MaximumSizeSquareSubMatrixWithAll1s(mat)<<endl;
	cout<<MaximumSizeSquareSubMatrixWithAll1S(mat)<<endl;
	return 0;
}
