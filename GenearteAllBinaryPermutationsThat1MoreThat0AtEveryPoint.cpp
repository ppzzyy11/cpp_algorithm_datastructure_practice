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

void Helper(const int& n,int cnt1,string& tmp,vector<string>& res)
{
	if(tmp.size()==n)
	{
		res.push_back(tmp);
		return ;
	}
	if(tmp.size()<2*cnt1)
	{
		tmp+='0';
		Helper(n,cnt1,tmp,res);
		tmp.pop_back();
	}
	tmp+='1';
	Helper(n,cnt1+1,tmp,res);
	tmp.pop_back();
}

void GenerateAllBinaryPermutationsThat1MoreThan0AtEveryPoint(const int& n)
{
	string tmp="";
	vector<string> res;
	Helper(n,0,tmp,res);
	for(auto r:res)
	{
		cout<<r<<endl;
	}
	return ;
}

int main()
{
	int n=2;//4 3 2 OK
	GenerateAllBinaryPermutationsThat1MoreThan0AtEveryPoint(n);
	return 0;
}
