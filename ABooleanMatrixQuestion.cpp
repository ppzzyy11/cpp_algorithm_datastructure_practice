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

void ABooleanMatrixQuestion(vector<vector<int>>& mat)
{
	if(mat.size()==0) return ;
	if(mat[0].size()==0) return ;
	bool FRow=0,FColumn=0;
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][0]==1)
		{
			FColumn=1;
			break;
		}
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[0][j]==1)
		{
			FRow=1;
			break;
		}
	}

	for(int i=1;i<mat.size();i++)
	{
		for(int j=1;j<mat[i].size();j++)
		{
			if(mat[i][j]==1)
			{
				mat[i][0]=1;
				mat[0][j]=1;
			}
		}
	}
	for(int i=1;i<mat.size();i++)
	{
		if(mat[i][0]==1)
		{
			for(int j=1;j<mat[i].size();j++)
			{
				mat[i][j]=1;
			}
		}
	}
	for(int j=1;j<mat[0].size();j++)
	{
		if(mat[0][j]==1)
		{
			for(int i=1;i<mat.size();i++)
			{
				mat[i][j]=1;
			}
		}
	}
	if(FRow)
		for(int j=0;j<mat[0].size();j++)
		{
			mat[0][j]=1;
		}
	if(FColumn)
		for(int i=0;i<mat.size();i++)
		{
			mat[i][0]=1;
		}
}

int main()
{
	vector<vector<int>> mat=
	{
		//{1, 0, 0, 1},
		//{0, 0, 1, 0},
		//{0, 0, 0, 0},
		{1, 0, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
	};
	ABooleanMatrixQuestion(mat);
	cout<<mat<<endl;
	return 0;
}
