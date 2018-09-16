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

set<string> FindAllDistinctPalindromicSubstringsOfAGivenString(const string& str)
{
	set<string> res;
	int l,r;
	for(int i=0;i<str.size();i++)
	{
		l=i,r=i;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			string tmp=str.substr(l,r-l+1);
			if(res.count(tmp)==0)
			{
				res.insert(tmp);
			}
			l--;
			r++;
		}
		l=i,r=i+1;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			string tmp=str.substr(l,r-l+1);
			if(res.count(tmp)==0)
			{
				res.insert(tmp);
			}
			l--;
			r++;
		}
	}
	cout<<res<<endl;
	return res;
}

int main()
{
	string str="geek";
	//string str="abaaa";
	FindAllDistinctPalindromicSubstringsOfAGivenString(str);
	return 0;
}
