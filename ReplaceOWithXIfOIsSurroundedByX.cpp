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

void FloodFill(int x,int y,vector<vector<char>>& mat,const char preC, const char newC)
{
	if(x<0||y<0) return ;
	if(x>=mat.size()) return ;
	if(y>=mat[x].size()) return ;
	if(mat[x][y]==preC)
	{
		mat[x][y]=newC;
		FloodFill(x-1,y,mat,preC,newC);
		FloodFill(x,y-1,mat,preC,newC);
		FloodFill(x+1,y,mat,preC,newC);
		FloodFill(x,y+1,mat,preC,newC);
	}else
	{
		return ;
	}
}

void RepalceOWithXIfSurroundedByX(vector<vector<char>>& mat)
{
	if(mat.size()==0) return ;
	if(mat[0].size()==0) return ;

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]=='O')
			{
				mat[i][j]='-';
			}
		}
	}

	for(int i=0,j=0;i<mat.size();i++)
	{
		if(mat[i][j]=='-')
		{
			FloodFill(i,j,mat,'-','O');
		}
	}
	for(int i=0,j=0;j<mat[i].size();j++)
	{
		if(mat[i][j]=='-')
		{
			FloodFill(i,j,mat,'-','O');
		}
	}
	for(int i=mat.size()-1,j=mat[i].size()-1;i>=0;i--)
	{
		if(mat[i][j]=='-')
		{
			FloodFill(i,j,mat,'-','O');
		}
	}
	for(int i=mat.size()-1,j=mat[i].size()-1;j>=0;j--)
	{
		if(mat[i][j]=='-')
		{
			FloodFill(i,j,mat,'-','O');
		}
	}

	for(int i=1;i<mat.size()-1;i++)
	{
		for(int j=1;j<mat[i].size()-1;j++)
		{
			if(mat[i][j]=='-')
			{
				FloodFill(i,j,mat,'-','X');
			}
		}
	}

}

int main()
{
	vector<vector<char>> mat=
	{
		{'X', 'O', 'X', 'O', 'X', 'X'},
		{'X', 'O', 'X', 'X', 'O', 'X'},
		{'X', 'X', 'X', 'O', 'X', 'X'},
		{'O', 'X', 'X', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'O', 'X', 'O'},
		{'O', 'O', 'X', 'O', 'O', 'O'},
		//{'X', 'O', 'X', 'X', 'X', 'X'},
		//{'X', 'O', 'X', 'X', 'O', 'X'},
		//{'X', 'X', 'X', 'O', 'O', 'X'},
		//{'O', 'X', 'X', 'X', 'X', 'X'},
		//{'X', 'X', 'X', 'O', 'X', 'O'},
		//{'O', 'O', 'X', 'O', 'O', 'O'},
	};
	cout<<mat<<endl;
	RepalceOWithXIfSurroundedByX(mat);
	cout<<mat<<endl;
	return 0;
}
