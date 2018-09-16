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

bool IfAGivenStringARotationOfAPalindrome(string& str)// O(n^2)
{
	for(int i=0;i<str.size()-1;i++)//Roatation str.size() times
	{
		int l=0,r=str.size()-1;
		while(l<=r&&str[l]==str[r])
		{
			l++;
			r--;
		}
		if(l>r)
		{
			return 1;
		}
		char head=str[0];
		for(int j=0;j<str.size()-1;j++)
		{
			str[j]=str[j+1];
		}
		str[str.size()-1]=head;
	}
	return 0;
}

string FindTheLongestPalindromicSubstring(const string& str)//Can be done in O(n), this one is O(n^2)
{
	if(str.size()==0) return "";
	int L=0,R=0;
	int l,r;
	for(int i=0;i<str.size();i++)
	{
		l=i;
		r=l;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			if(r-l>R-L) { R=r; L=l; }
			l--;
			r++;
		}
		l=i;
		r=l+1;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			if(r-l>R-L){R=r;L=l;}
			l--;
			r++;
		}
	}
	return str.substr(L,R-L+1);
}
bool IfAGivenStringARotationOfAPalindrome2(const string& str)
{
	string tmp=str+str;
	return FindTheLongestPalindromicSubstring(tmp).size()>=str.size();
}

int main()
{
	//string str="aaaa";
	string str="abcdef";
	//string str="aab";
	//cout<<IfAGivenStringARotationOfAPalindrome(str)<<endl;
	cout<<IfAGivenStringARotationOfAPalindrome2(str)<<endl;
	return 0;
}
