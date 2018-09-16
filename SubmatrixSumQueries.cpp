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
ostream& operator<<(ostream& os,const vector<vector<vector<int>>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			for(int k=0;k<mat[i][j].size();k++)
			{
				cout<<mat[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return os;
}

int SubmatrixSumQueries(const vector<vector<int>>& mat,int si,int sj,int ei,int ej)
{
	vector<vector<int>> sum(mat.size(),vector<int>(mat[0].size(),0));
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(i==0&&j==0)
			{
				sum[i][j]=mat[i][j];
			}else if(i==0)
			{
				sum[i][j]=mat[i][j]+sum[i][j-1];
			}else if(j==0)
			{
				sum[i][j]=mat[i][j]+sum[i-1][j];
			}else
			{
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
			}
		}
	}
	if(si==0&&sj==0)
	{
		return sum[ei][ej];
	}else if(si==0)
	{
		return sum[ei][ej]-sum[ei][sj-1];
	}else if(sj==0)
	{
		return sum[ei][ej]-sum[si-1][ej];
	}else
	{
		return sum[ei][ej]-sum[si-1][ej]-sum[ei][sj-1]+sum[si-1][sj-1];
	}

}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 3, 4, 6},
		{5, 3, 8, 1, 2},
		{4, 6, 7, 5, 5},
		{2, 4, 8, 9, 4}
	};
	vector<vector<int>> idx=// (i,j) (i,j)
	{
		{0,0,1,1},
		{2,2,3,4},
		{1,2,3,3}
	};
	for(int i=0;i<idx.size();i++)
	{
		cout<<SubmatrixSumQueries(mat,idx[i][0],idx[i][1],idx[i][2],idx[i][3])<<endl;//每次都得计算一遍,很傻比Lw'
	}
	return 0;
}
