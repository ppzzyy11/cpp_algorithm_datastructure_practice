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

int MinimumSumOfSquaresOfCharacterCountsInAGivenStringAfterRemovingKCharacters(const string& str,int k)
{
	vector<int> rec(256,0);
	for(auto s:str)
	{
		rec[s]++;
	}

	vector<int> hp;
	for(int  i=0;i<rec.size();i++)
	{
		if(rec[i]!=0)
		{
			hp.push_back(rec[i]);
		}
	}

	make_heap(hp.begin(),hp.end());
	while(k)
	{
		hp[0]--;
		make_heap(hp.begin(),hp.end());
		k--;
	}
	int res=0;
	for(int i=0;i<hp.size();i++)
	{
		res+=hp[i]*hp[i];
	}
	return res;
}

int main()
{
	string str="abccc";
	int k=3;//1 2
	cout<<MinimumSumOfSquaresOfCharacterCountsInAGivenStringAfterRemovingKCharacters(str,k)<<endl;
	return 0;
}
