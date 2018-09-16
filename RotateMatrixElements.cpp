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

void RotateMatrixElements(vector<vector<int>>& mat)
{
	if(mat.size()<=1) return ;
	if(mat[0].size()<=1) return ;
	int iL=0,iH=mat.size()-1;
	int jL=0,jH=mat[0].size()-1;
	int pre=mat[iL+1][jL];
	int cur=mat[0][0];
	while(iL<=iH&&jL<=jH)
	{
		if(iL==iH||jL==jH) break;
		pre=mat[iL+1][jL];
		for(int i=iL,j=jL;j<=jH;j++)
		{
			cur=mat[i][j];
			mat[i][j]=pre;
			pre=cur;
		}
		iL++;
		for(int i=iL,j=jH;i<=iH;i++)
		{
			cur=mat[i][j];
			mat[i][j]=pre;
			pre=cur;
		}
		jH--;
		for(int i=iH,j=jH;j>=jL;j--)
		{
			cur=mat[i][j];
			mat[i][j]=pre;
			pre=cur;
		}
		iH--;
		for(int i=iH,j=jL;i>=iL;i--)
		{
			cur=mat[i][j];
			mat[i][j]=pre;
			pre=cur;
		}
		jL++;
		//cout<<mat<<endl;
	}
}

int main()
{
	vector<vector<int>> mat=
	{

		//{1,  2,  3,  4},
		//{5,  6,  7,  8},
		//{9,  10, 11, 12},
		//{13, 14, 15, 16}

		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout<<mat<<endl;
	RotateMatrixElements(mat);
	cout<<mat<<endl;
	return 0;
}
