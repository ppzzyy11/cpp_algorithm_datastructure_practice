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

void AnagramSearching(const string& txt, const string& pat)
{
	if(txt.size()<pat.size())
	{
		cout<<"Empty String"<<endl;
		return ;
	}
	vector<int> rec_pat(256,0);
	for(auto s:pat)
	{
		rec_pat[s]++;
	}
	vector<int> rec_txt(256,0);
	for(int i=0;i<pat.size();i++)
	{
		rec_txt[txt[i]]++;
	}
	if(rec_txt==rec_pat)
	{
		cout<<"Found at index:"<<0<<"\t"<<txt.substr(0,pat.size())<<endl;
	}
	for(int i=pat.size();i<txt.size();i++)
	{
		rec_txt[txt[i]]++;
		rec_txt[txt[i-pat.size()]]--;
		if(rec_txt==rec_pat)
		{
			cout<<"Found at index:"<<i-pat.size()+1<<"\t"<<txt.substr(i-pat.size()+1,pat.size())<<endl;
		}
	}
	return ;
}

int main()
{
	string txt="BACDGABCDA";
	string pat="ABCD";
	AnagramSearching(txt,pat);
	return 0;
}

