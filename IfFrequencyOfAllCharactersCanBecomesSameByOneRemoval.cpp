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

bool IsSameExceptZero(const vector<int>&nums)
{
	bool same=1;
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i]!=0&&nums[i-1]!=0&&nums[i]!=nums[i-1])
		{
			same=0;
			break;
		}
	}
	return same;
}

bool IfFrequencyOfAllCharactersCanBecomeSameByOneRemoval(const string& str)
{
	vector<int> rec(256,0);
	for(int i=0;i<str.size();i++)
	{
		rec[str[i]]++;
	}
	vector<int> nums;
	for(int i=0;i<rec.size();i++)
	{
		if(rec[i]!=0)
		{
			nums.push_back(rec[i]);
		}
	}
	sort(nums.begin(),nums.end());

	if(IsSameExceptZero(nums)) return 1;
	for(int i=0;i<nums.size();i++)
	{
		nums[i]--;
		if(IsSameExceptZero(nums)) return 1;
		nums[i]++;
	}
	return 0;
}

int main()
{
	//string str="xyyz";
	//string str="xyyzz";
	string str="xxxxyyzz";
	cout<<IfFrequencyOfAllCharactersCanBecomeSameByOneRemoval(str)<<endl;
	return 0;
}
