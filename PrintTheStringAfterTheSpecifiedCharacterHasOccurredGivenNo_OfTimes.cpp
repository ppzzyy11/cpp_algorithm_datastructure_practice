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

string PrintTheStringAfterTheSpecifiedCharacterHasOccurredGivenNO_OfTimes(const string&str,const char ch, int k)
{
	int i=0;
	for(i=0;i<str.size();i++)
	{
		if(str[i]==ch)
		{
			k--;
			if(k==0)
			{
				i++;
				break;
			}
		}
	}
	if(k!=0||i==str.size())
	{
		return "Empty string";
	}
	return str.substr(i,str.size()-i);
}

int main()
{
	//string str="This is demo string";
	//char ch='i';
	//int k=3;//3 4
	//string str="geeksforgeeks";
	//char ch='e';
	//int k=2;
	string str="gee";
	char ch='e';
	int k=2;
	cout<<PrintTheStringAfterTheSpecifiedCharacterHasOccurredGivenNO_OfTimes(str,ch,k)<<endl;
	return 0;
}
