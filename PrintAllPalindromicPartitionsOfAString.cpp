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

ostream& operator<<(ostream& os,const vector<vector<string>>& strss)
{
	for(auto strs:strss)
	{
		for(auto str:strs)
		{
			cout<<str<<' ';
		}
		cout<<endl;
	}
	return os;
}

vector<vector<string>> PrintAllPalinromicPartitionsOfAString(const string& str)
{
	vector<vector<string>> res;
	if(str.size()==0) return res;
	vector<string> tmp(0,"");
	int l=0,r=0;
	for(int i=0;i<str.size();i++)
	{
		l=i;
		r=i;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			while(res.size()<r-l+1)
			{
				res.push_back(vector<string>(0,""));
			}
			res[r-l].push_back(str.substr(l,r-l+1));
			r++;
			l--;
		}
		l=i;
		r=i+1;
		while(l>=0&&r<str.size()&&str[l]==str[r])
		{
			while(res.size()<r-l+1)
			{
				res.push_back(vector<string>(0,""));
			}
			res[r-l].push_back(str.substr(l,r-l+1));
			r++;
			l--;
		}
	}
	cout<<res.size()<<endl;
	cout<<res;
	return res;
}

int main()
{
	//string str="bcc";
	string str="geeeks";
	PrintAllPalinromicPartitionsOfAString(str);
	return 0;
}
