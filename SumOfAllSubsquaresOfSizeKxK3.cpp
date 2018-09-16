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

vector<vector<int>> SumOfAllSubsquaresOfSizeKxK(vector<vector<int>>& mat, const int k)
{
	vector<vector<int>> res;
	if(mat.size()==0) return res;
	if(mat[0].size()==0) return res;
	if(k>min(mat.size(),mat[0].size())) return res;
	res.resize(mat.size()-k+1,vector<int>(mat[0].size()-k+1,2));
	//process mat
	//TC O(n^2)
	for(int i=mat.size()-2;i>=0;i--)
	{
		mat[i][mat[0].size()-1]+=mat[i+1][mat[0].size()-1];
	}

	for(int j=mat[0].size()-2;j>=0;j--)
	{
		mat[mat.size()-1][j]+=mat[mat.size()-1][j+1];
	}

	for(int i=mat.size()-2;i>=0;i--)
	{
		for(int j=mat[0].size()-2;j>=0;j--)
		{
			mat[i][j]+=mat[i+1][j]+mat[i][j+1]-mat[i+1][j+1];
		}
	}
	//cout<<"mat:"<<endl;
	//cout<<mat<<endl;

	for(int i=0;i<mat.size()-k;i++)
	{
		for(int j=0;j<mat[0].size()-k;j++)
		{
			{
				res[i][j]=mat[i][j]-mat[i][j+k]-mat[i+k][j]+mat[i+k][j+k];
			}
		}
	}
	//border edge
	//i+k==mat.size()
	//j+k==mat[0].size()
	res[mat.size()-k][mat[0].size()-k]=mat[mat.size()-k][mat[0].size()-k];
	for(int i=mat.size()-k,j=0;j<mat[0].size()-k;j++)
	{
		res[i][j]=mat[i][j]-mat[i][j+k];
	}
	for(int i=0,j=mat[0].size()-k;i<mat.size()-k;i++)
	{
		res[i][j]=mat[i][j]-mat[i+k][j];
	}
	return res;
}

int main()
{
	vector<vector<int>> mat=
	{
		//{1, 1, 1, 1, 1},// k= 1 2 3 4 5 6 pass
		//{2, 2, 2, 2, 2},
		//{3, 3, 3, 3, 3},
		//{4, 4, 4, 4, 4},
		//{5, 5, 5, 5, 5},
		{1, 2, 3},//pass
		{4, 5, 6},
		{7, 8, 9},
	};
	cout<<SumOfAllSubsquaresOfSizeKxK(mat,2)<<endl;
	return 0;
}
