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

struct Ele
{
	int x;
	int y;
	int val;
	Ele(int x,int y,int val):x(x),y(y),val(val){}
};
bool inline operator<(const Ele& e1, const Ele& e2)
{
	return e1.val>e2.val;
}
ostream& operator<<(ostream& os, const vector<Ele>& eles)
{
	for(auto e:eles)
	{
		cout<<'('<<e.x<<','<<e.y<<')'<<' '<<e.val<<'\t';
	}
	return os;
}

vector<int>  PrintAllElementsInSortedOrderFromRowAndColumnWiseSortedMatrix(const vector<vector<int>>& mat)
{
	vector<int> res;
	if(mat.size()==0) return res;
	if(mat[0].size()==0) return res;
	vector<Ele> eles;
	for(int i=0;i<mat.size();i++)
	{
		Ele tmp(i,0,mat[i][0]);
		eles.push_back(tmp);
	}
	//cout<<eles<<endl;
	while(eles.size())
	{
		Ele tmp=eles[0];
		res.push_back(tmp.val);
		swap(eles[0],eles[eles.size()-1]);
		eles.pop_back();
		pop_heap(eles.begin(),eles.end());
		if(tmp.y!=mat[0].size()-1)
		{
			tmp.y++;
			tmp.val=mat[tmp.x][tmp.y];
			eles.push_back(tmp);
			push_heap(eles.begin(),eles.end());
		}
		//cout<<eles<<endl;
	}
	return res;
}

int main()
{
	vector<vector<int>> mat=
	{
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50},
	};
	cout<<PrintAllElementsInSortedOrderFromRowAndColumnWiseSortedMatrix(mat)<<endl;
	return 0;
}
