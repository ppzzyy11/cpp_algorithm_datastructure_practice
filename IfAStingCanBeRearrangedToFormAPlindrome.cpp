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

bool IfAStringCanBeRearrangedToFormAPalindrome(const string& str)
{
	vector<int> cnt(256,0);
	for(auto s:str)
	{
		cnt[s]++;
	}
	bool flag=0;

	for(int i=0;i<cnt.size();i++)
	{
		if(cnt[i]%2==1)
		{
			if(flag==0)
			{
				flag=1;
			}else
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	//string str="geeksfgeeks";
	string str="geeeea";
	cout<<IfAStringCanBeRearrangedToFormAPalindrome(str)<<endl;
	return 0;
}
