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

void FindTheSmallestWindowsContainingAllCharactersOfAnotherString(const string& txt, const string& pat)
{
	vector<int> rec_pat(256,0);
	for(auto p:pat)
	{
		rec_pat[p]++;
	}
	int count=0;
	int l=0,r=0;
	int L=-1,R=-1;
	vector<int> rec_txt(256,0);
	while(r<txt.size())
	{
		char ch=txt[r];
		if(rec_pat[ch]!=0)
			rec_txt[ch]++;
		if(rec_pat[ch]!=0&&rec_txt[ch]<=rec_pat[ch])
		{
			count++;
		}
		if(count==pat.size())
		{
			while(l<r)
			{
				char ch=txt[l];
				if(rec_pat[ch]!=0)
					rec_txt[ch]--;
				if(rec_pat[ch]!=0&&rec_txt[ch]<rec_pat[ch])
				{
					count--;
					if(L==-1)
					{
						L=l;
						R=r;
					}else if(r-l<R-L)
					{
						R=r;
						L=l;
					}
					l++;
					break;
				}
				l++;
			}
		}
		r++;
	}
	cout<<L<<":"<<R<<endl;
	cout<<txt.substr(L,R-L+1)<<endl;
}

int main()
{
	//string txt="this is a test string";
	//string pat="tist";
	string txt="geeksforgeeks";
	string pat="ork";
	FindTheSmallestWindowsContainingAllCharactersOfAnotherString(txt,pat);
	return 0;
}

