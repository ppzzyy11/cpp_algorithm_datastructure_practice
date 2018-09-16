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

void PrintAGivenMatrixInSpiralForm(const vector<vector<int>>& mat)
{
	int dct=0;// 0 ->3  representing 4 directions
	int iL=0,iR=mat.size()-1;
	int jL=0,jR=mat[0].size()-1;
	while(iL<=iR&&jL<=jR)
	{
		switch (dct)
		{
			case 0:
				{
					int i=iL,j=jL;
					while(j<=jR)
					{
						cout<<mat[i][j]<<' ';
						j++;
					}
					iL++;
					dct=1;
				}
				break;

			case 1:
				{
					int i=iL,j=jR;
					while(i<=iR)
					{
						cout<<mat[i][j]<<' ';
						i++;
					}
					jR--;
					dct=2;
				}
				break;

			case 2:
				{
					int i=iR,j=jR;
					while(j>=jL)
					{
						cout<<mat[i][j]<<' ';
						j--;
					}
					iR--;
					dct=3;
				}
				break;

			case 3:
				{
					int i=iR,j=jL;
					while(i>=iL)
					{
						cout<<mat[i][j]<<' ';
						i--;
					}
					jL++;
					dct=0;
				}
				break;
		}
	}
	return ;
}

int main()
{
	vector<vector<int>> mat={
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50}};
	PrintAGivenMatrixInSpiralForm(mat);
	return 0;
}
