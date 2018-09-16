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

void swap(vector<vector<int>>& mat,int row1,int row2,int col)
{
	for(int i=0;i<col;i++)
	{
		swap(mat[row1][i],mat[row2][i]);
	}
}

//这个函数不是很完善,默认int可以整除了,其实不是这样的,但是逻辑的实现跟随意和紧密,值得学习
int RankOfMatrix(vector<vector<int>>& mat)
{
	int R=mat.size();
	int C=mat[0].size();

		int rank=C;

		for(int row=0;row<rank;row++)
		{
			if(mat[row][row])
			{
				for(int col=0;col<R;col++)
				{
					if(col!=row)
					{
						double mult=(double)mat[col][row]/mat[row][row];
						for(int i=0;i<rank;i++)
						{
							mat[col][i]-=mult*mat[row][i];
						}
					}
				}
			}else
			{
				bool reduce=1;

				for(int i=row+1;i<R;i++)
				{
					if(mat[i][row])
					{
						swap(mat,row,i,rank);
						reduce=0;
						break;
					}
				}

				if(reduce)
				{
					rank--;
					for(int i=0;i<R;i++)
					{
						mat[i][row]=mat[i][rank];
					}
				}
				row--;
			}
		}
		return rank;
}

int main()
{
	vector<vector<int>> mat=
	{
		{10,   20,   10},
		{-20,  -30,   10},
		{30,   50,   0}
	};
	cout<<RankOfMatrix(mat)<<endl;

	return 0;
}
