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
ostream& operator<<(ostream& os,const vector<vector<bool>>& mat)
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

bool Helper(int x,int y,const vector<vector<bool>>& mat,vector<vector<int>>& res,const int cnt)
{
	if(x<0||y<0) return 0;
	if(x>=mat.size()||y>=mat[x].size()) return 0;
	if(mat[x][y]==0) return 0;
	if(res[x][y]!=0) return 0;
	res[x][y]=cnt;
	return 1;
}

vector<vector<int>> ShortestPathInABinaryMaze(const vector<vector<bool>>& mat,const pair<int,int>& src, const pair<int,int>& dst)
{
	vector<vector<int>> res(mat.size(),vector<int>(mat[0].size(),0));
	int x=src.first;
	int y=src.second;
	if(mat[x][y]==0) return res;

	queue<pair<int,int>> que;
	que.push(make_pair(x,y));
	res[x][y]=1;

	while(!que.empty())
	{
		int x=que.front().first;
		int y=que.front().second;
		int cnt=res[x][y]+1;
		que.pop();

		x--;
		if(Helper(x,y,mat,res,cnt))
		{
			que.push(make_pair(x,y));
		}
		x++;

		x++;
		if(Helper(x,y,mat,res,cnt))
		{
			que.push(make_pair(x,y));
		}
		x--;

		y++;
		if(Helper(x,y,mat,res,cnt))
		{
			que.push(make_pair(x,y));
		}
		y--;

		y--;
		if(Helper(x,y,mat,res,cnt))
		{
			que.push(make_pair(x,y));
		}
		y++;
	}
	return res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};
	auto src=make_pair(0,0);
	cout<<ShortestPathInABinaryMaze(mat,src,src)<<endl;
	return 0;
}
