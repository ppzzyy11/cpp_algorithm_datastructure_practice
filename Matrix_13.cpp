#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
using namespace std;


ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
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
ostream& operator<<(ostream& os, const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(auto num:nums)
	{
		cout<<num<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os, const vector<vector<string>>& strs)
{
	for(int i=0;i<strs.size();i++)
	{
		for(int j=0;j<strs[i].size();j++)
		{
			cout<<strs[i][j]<<' ';
			//cout<<i<<":"<<j<<endl;
		}
		cout<<endl;
	}
	return os;
}

void Helper(const int m,const int n,const int k,const vector<vector<int>>& mat, vector<vector<int>>& sum1k,vector<vector<int>>& sumk1, vector<vector<int>>& res)
{
	if(k>min(m,n)) return ;//等于会出错
	if(k==1) return ;

	Helper(m,n,k-1,mat,sum1k,sumk1,res);

	for(int i=0;i<=m-k;i++)
	{
		for(int j=0;j<=n-k;j++)
		{
			res[i][j]=res[i][j]+mat[i+k-1][j+k-1]+sumk1[i][j+k-1]+sum1k[i+k-1][j];
		}
	}
	for(int i=k;i<m;i++)
	{
		for(int j=0;j<=n-k;j++)
		{
			sum1k[i][j]=sum1k[i][j]+mat[i][j+k-1];
		}
	}
	for(int i=0;i<=m-k;i++)
	{
		for(int j=k;j<n;j++)
		{
			sumk1[i][j]=sumk1[i][j]+mat[i+k-1][j];
		}
	}

	cout<<"\n\n\n\n"<<k<<endl;
	cout<<res<<endl;
	//cout<<"sumk1:\n"<<sumk1<<endl;
	//cout<<"sum1k:\n"<<sum1k<<endl;
}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 1, 1, 1, 1},
		{2, 2, 2, 2, 2},
		{3, 3, 3, 3, 3},
		{4, 4, 4, 4, 4},
		{5, 5, 5, 5, 5}
	};
	int k=5;
	int m=mat.size();
	int n;
	if(m!=0)
		n=mat[0].size();
	else
		return 0;
	cout<<mat<<endl;
	vector<vector<int>> sum1k(mat);
	vector<vector<int>> sumk1(mat);
	vector<vector<int>> res(mat);
	Helper(m,n,k,mat,sum1k,sumk1,res);
	return 0;
}
