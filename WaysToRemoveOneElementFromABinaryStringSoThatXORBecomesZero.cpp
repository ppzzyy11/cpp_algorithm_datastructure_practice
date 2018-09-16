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

int WaysToRemoveOneElementFromABinaryStringSoThatXORBecomesZero(const string& str)
{
	vector<int> cnt(2,0);
	for(auto s:str)
	{
		if(s=='1')
		{
			cnt[1]++;
		}else
		{
			cnt[0]++;
		}
	}
	if(cnt[1]%2==0) return cnt[0];
	else return cnt[1];
}

int main()
{
	string str="100011100";
	//string str="10011";
	//string str="10000";
	cout<<WaysToRemoveOneElementFromABinaryStringSoThatXORBecomesZero(str)<<endl;
	return 0;
}
