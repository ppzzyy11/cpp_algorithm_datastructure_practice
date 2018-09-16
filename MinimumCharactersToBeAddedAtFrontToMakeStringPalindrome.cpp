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

int MinimumCharactersToBeAddedAtFrontToMakeStringPalindrome(string& str)
{
	string tmp=str;
	reverse(str.begin(),str.end());
	tmp+='$'+str;

	vector<int> lps(tmp.size(),0);
	int i=0,j=1;
	while(j<tmp.size())
	{
		if(tmp[i]==tmp[j])
		{
			i++;
			lps[j]=i;
			j++;
		}else if(i==0)
		{
			j++;
		}else
		{
			i=lps[i-1];
		}
	}
	cout<<tmp<<endl;
	cout<<lps<<endl;
	return lps.back();
}

int main()
{
	string str="ccabacc";
	cout<<MinimumCharactersToBeAddedAtFrontToMakeStringPalindrome(str)<<endl;
	return 0;
}

