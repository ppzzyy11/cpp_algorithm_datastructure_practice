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

string MakeLargestPalindromeBuChangingAtMostKDigits(string& str,  int k)
{
	//make string palindromic
	int l=0,r=str.size()-1;
	vector<bool> rec(str.size(),0);

	while(l<r)
	{
		if(str[l]!=str[r])
		{
			if(str[l]>str[r])
			{
				str[r]=str[l];
				rec[r]=1;
			}else
			{
				str[l]=str[r];
				rec[l]=1;
			}
			k--;
			if(k<0) return "Impossible";
		}
		l++;
		r--;
	}
	while(k>0)
	{
		int pos=-1;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]!='9')
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
		{
			return str;
		}else
		{
			int rev_pos=str.size()-1-pos;
			if(rev_pos==pos)
			{
				str[pos]='9';
				return str;
			}else if(k>=2)
			{
				if(rec[pos]==1)
					k++;
				if(rec[rev_pos]==1)
					k++;
				str[pos]=str[rev_pos]='9';
				k=k-2;
			}else //k ==1
			{
				if(str.size()%2==1)//odd length
				{
					str[str.size()/2]='9';
					return str;
				}
			}
		}
	}
	return str;
}

int main()
{
	string str="12345";
	int k=2;
	//string str="43435";
	//int k=5;// 4 3 2 1 0
	cout<<MakeLargestPalindromeBuChangingAtMostKDigits(str,k)<<endl;
	return 0;
}
