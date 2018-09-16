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

vector<vector<char>> CreateAMatrixWithAlternatingRectanglesOfOAndX(const int m, const int n)
{
	vector<vector<char>> mat(m,vector<char>(n,0));
	int iL=0,iH=m-1;
	int jL=0,jH=n-1;
	char ch='X';
	while(iL<=iH&&jL<=jH)
	{
		for(int i=iL,j=jL;j<=jH;j++)
		{
			mat[i][j]=ch;
		}
		for(int i=iL,j=jH;i<=iH;i++)
		{
			mat[i][j]=ch;
		}
		for(int i=iH,j=jH;j>=jL;j--)
		{
			mat[i][j]=ch;
		}
		for(int i=iH,j=jL;i>=iL;i--)
		{
			mat[i][j]=ch;
		}
		if(ch=='X')
		{
			ch='O';
		}else
		{
			ch='X';
		}
		iH--,jH--;
		iL++,jL++;
	}
	return mat;
}

int main()
{
	int m=5;
	int n=5;
	cout<<CreateAMatrixWithAlternatingRectanglesOfOAndX(m,n)<<endl;
	return 0;
}
