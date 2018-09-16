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

bool winC(char ch,const vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][0]==ch&&mat[i][1]==ch&&mat[i][2]==ch) return 1;
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[0][j]==ch&&mat[1][j]==ch&&mat[2][j]==ch) return 1;
	}

	if(mat[0][0]==ch&&mat[1][1]==ch&&mat[2][2]==ch) return 1;
	if(mat[0][2]==ch&&mat[1][1]==ch&&mat[2][0]==ch) return 1;

	return 0;
}

bool ValidityOfAGivenTicTacToeBoardConfiguration(const vector<vector<char>>& mat)
{
	if(mat.size()!=3) return 0;
	if(mat[0].size()!=3) return 0;

	int cntO=0,cntX=0;//X play first

	for(int i=0;i<mat.size();i++)
	{
		if(mat[i].size()!=3) return 0;
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]=='O') cntO++;
			if(mat[i][j]=='X') cntX++;
		}
		if(cntX!=cntO&&cntX!=cntO+1) return 0;
	}
	bool winX=0,winO=0;
	winX=winC('X',mat);
	winO=winC('O',mat);
	if(winX&&winO) return 0;
	return 1;
}

int main()
{
	vector<vector<char>> mat=
	{
		{ 'O', 'X', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }

		//{ 'O', 'X', 'X' },
		//{ 'O', 'X', 'X' },
		//{ 'O', 'O', 'X' }

		//{ 'X', 'X', 'O' },
		//{ 'O', 'O', 'X' },
		//{ 'X', 'O', 'X' }
	};
	cout<<ValidityOfAGivenTicTacToeBoardConfiguration(mat)<<endl;
	return 0;
}
