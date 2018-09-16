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

string 	LexicograpgicallyFirstPalindromicString(const string&str)
{
	vector<int> rec(256,0);
	for(auto s:str)
	{
		rec[s]++;
	}
	bool flag=0;
	for(int i=0;i<rec.size();i++)
	{
		if(rec[i]%2==1)
		{
			if(flag==0)
				flag=1;
			else
				return "No Palindromic string";
		}
	}

	string head="";
	string mid="";
	for(int i=0;i<rec.size();i++)
	{
		while(rec[i]>0)
		{
			if(rec[i]>=2)
			{
				char ch=i;
				head+=ch;
				rec[i]-=2;
			}else
			{
				char ch=i;
				mid+=ch;
				rec[i]--;
			}
		}
		//if(rec[i]==1)
		//{
			//mid+=(char)i;
		//}else if(rec[i]==2)
		//{
			//char ch=i;
			//head+=ch;
		//}
	}
	string res=head+mid;
	reverse(head.begin(),head.end());
	res+=head;
	return res;
}

int main()
{
	//string str="malaaalam";
	string str="apple";
	cout<<LexicograpgicallyFirstPalindromicString(str)<<endl;
	return 0;
}
