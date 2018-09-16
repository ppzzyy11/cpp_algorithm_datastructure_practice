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

string FindOrientationOfAPatternInAMatrix(const vector<vector<char>>& mat,const string& pat)
{
	vector<int> lps(pat.size(),0);
	int i=1,j=0;
	while(i<pat.size())
	{
		if(pat[i]==pat[j])
		{
			j++;
			lps[i]=j;
			i++;
		}else if(j!=0)
		{
			j=lps[j-1];
		}else
		{
			i++;
		}
	}

	//cout<<lps<<endl;

	for(int i=0;i<mat.size();i++)
	{
		string txt="";
		for(int j=0;j<mat[i].size();j++)
		{
			txt+=mat[i][j];
		}
		{
			int i=0,j=0;
			while(i<txt.size())
			{
				if(txt[i]==pat[j])
				{
					i++;
					j++;
				}

				if(j==pat.size())
				{
					return "Horizontal";
				}else if(i<txt.size()&&txt[i]!=pat[j])
				{
					if(j==0)
					{
						i++;
					}else
					{
						j=lps[j-1];
					}
				}
			}
		}
	}

	for(int j=0;j<mat[0].size();j++)
	{
		string txt="";
		for(int i=0;i<mat.size();i++)
		{
			txt+=mat[i][j];
		}

		{
			int i=0,j=0;
			while(i<txt.size())
			{
				if(txt[i]==pat[j])
				{
					i++;
					j++;
				}

				if(j==pat.size())
				{
					return "Vertical";
				}else if(i<txt.size()&&txt[i]!=pat[j])
				{
					if(j==0)
					{
						i++;
					}else
					{
						j=lps[j-1];
					}
				}
			}
		}
	}

	return "Not Found at mat";
}

int main()
{
	vector<vector<char>> mat=
	{
		{'a', 'b', 'c', 'd', 'e'},
		{'f', 'g', 'h', 'i', 'j'},
		{'k', 'l', 'm', 'n', 'o'},
		{'p', 'q', 'r', 's', 't'},
		{'u', 'v', 'w', 'x', 'y'}
	};
	string pat="pqrs";
	//string pat="aaabaaa";
	cout<<FindOrientationOfAPatternInAMatrix(mat,pat)<<endl;
	return 0;
}
