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

bool IsPalindromic(const string& str)
{
	int l=0,r=str.size()-1;
	while(l<=r)
	{
		if(str[l]==str[r])
		{
			;
		}else
		{
			return 0;
		}
		l++;
		r--;
	}
	return 1;
}

void Helper(const string& str,int i,string& tmp,vector<string>& res)
{
	if(i==str.size())
	{
		tmp.pop_back();//Attention , pop ' '
		res.push_back(tmp);
		return ;
	}
	for(int j=i;j<str.size();j++)
	{
		if(IsPalindromic(str.substr(i,j-i+1)))
		{
			string t=tmp;
			tmp=tmp+str.substr(i,j-i+1)+' ';
			Helper(str,j+1,tmp,res);
			tmp=t;
		}
	}
}
void PrintAllPossiblePalindromicPartitions(const string& str)
{
	string tmp="";
	vector<string> res;
	Helper(str,0,tmp,res);
	cout<<res;
}


int main()
{
	//string str="nitin";
	string str="gheeks";
	PrintAllPossiblePalindromicPartitions(str);
	return 0;
}
