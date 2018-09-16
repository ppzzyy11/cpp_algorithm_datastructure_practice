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

int FindTheLargestRectangleOf1SWithSwappingOfColumnsAllowed(const vector<vector<bool>>& mat)
{
	if(mat.size()==0) return 0;
	if(mat[0].size()==0) return 0;

	int res=0;
	vector<int> h(mat[0].size(),0);
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==1)
			{
				h[j]++;
			}else
			{
				h[j]=0;
			}
		}
		vector<int> tmp=h;
		sort(tmp.begin(),tmp.end());
		tmp.push_back(0);

		stack<int> st;
		st.push(-1);

		for(int j=0;j<tmp.size();j++)
		{
			while(st.top()!=-1&&tmp[st.top()]>=tmp[j])
			{
				int h=tmp[st.top()];
				st.pop();

				res=max(res,h*(j-st.top()-1));
			}
			st.push(j);
		}
	}

	return res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		//{0, 1, 0, 1, 0},
		//{0, 1, 0, 1, 1},
		//{1, 1, 0, 1, 0}

		{0, 1, 0, 1, 0},
		{0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1}
	};
	cout<<FindTheLargestRectangleOf1SWithSwappingOfColumnsAllowed(mat)<<endl;
	return 0;
}
