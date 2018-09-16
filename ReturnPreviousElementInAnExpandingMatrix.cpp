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
ostream& operator<<(ostream& os,const pair<int,int>& p)
{
	cout<<'('<<p.first<<","<<p.second<<')';
	return os;
}

string Position2String(int i,int j,int N)
{
	string str="";

	while(N>1)
	{
		N=N/2;
		if(N==0) break;
		if(i<N&&j<N)
		{
			str+='a';
		}else if(i<N&&j>=N)
		{
			str+='b';
			j-=N;
		}else if(i>=N&&j<N)
		{
			str+='c';
			i-=N;
		}else
		{
			str+='d';
			i-=N;
			j-=N;
		}
	}
	return str;
}

pair<int,int> String2Position(const string& str)
{
	int i=0;
	int j=0;
	for(auto s:str)
	{
		switch(s)
		{
			case 'a':

				break;

			case 'b':
				j++;
				break;

			case 'c':
				i++;
				break;

			case 'd':
				i++;
				j++;
				break;
		};
			i*=2;
			j*=2;
	}
	return make_pair(i/2,j/2);
}

string ReturnPreviousElementInAnExpandingMatrix(const string& str)
{
	int N=1;
	for(int i=0;i<str.size();i++)
	{
		N=N*2;
	}
	auto p=String2Position(str);
	int x=p.first;
	int y=p.second;
	if(y==0)
	{
		y=N;
	}
	y--;
	return Position2String(x,y,N);


}

int main()
{
	//string str="dda";
	//string str="cca";
	string str="aacbddc";
	cout<<ReturnPreviousElementInAnExpandingMatrix(str)<<endl;
	return 0;
}
