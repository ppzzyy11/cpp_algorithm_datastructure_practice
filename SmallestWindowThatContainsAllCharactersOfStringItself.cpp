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

string SmallestWindowThatContainsAllCharactersOfStringItself(const string& str)
{
	vector<int> REC(256,0);
	int CNT=0;
	for(auto s:str)
	{
		REC[s]++;
		if(REC[s]==1)
		{
			CNT++;
		}
	}
	int cnt=0;
	vector<int> rec(256,0);
	int L=-1,R=-1;
	int l=0,r=0;
	while(r<str.size())
	{
		if(rec[str[r]]==0)
		{
			cnt++;
		}
		rec[str[r]]++;
		if(cnt==CNT)
		{
			while(l<r)
			{
				if(rec[str[l]]==1)
				{
					if(R==-1)
					{
						R=r;
						L=l;
					}else if(r-l<R-L)
					{
						R=r;
						L=l;
					}
					rec[str[l]]--;
					l++;
					cnt--;
					break;
				}
				rec[str[l]]--;
				l++;
			}
		}
		r++;
	}
	//cout<<L<<":"<<R<<endl;
	//for(int i=0;i<rec.size();i++)
	//{
		//if(rec[i]!=0)
			//cout<<(char)i<<' '<<rec[i]<<endl;
	//}
	return str.substr(L,R-L+1);
}

int main()
{
	//string str="aabcbcdbca";
	string str="aaab";
	cout<<SmallestWindowThatContainsAllCharactersOfStringItself(str)<<endl;
	return 0;
}

