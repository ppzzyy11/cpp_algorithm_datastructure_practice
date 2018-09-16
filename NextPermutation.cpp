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
ostream& operator<<(ostream& os,const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return os;
}

string NextPermutation(string& str)
{
	if(str.size()<=1) return 0;
	int i=str.size()-2;
	while(i>=0)
	{
		if(str[i]<str[i+1])
			break;
		i--;
	}
	if(i==-1)
	{
		reverse(str.begin(),str.end());
		return str;
	}
	int j=i+1;
	for(int k=i+2;k<str.size();k++)
	{
		if(str[k]>str[i]&&str[k]<str[j])
			j=k;
	}
	swap(str[i],str[j]);
	sort(str.begin()+i+1,str.end());
	return str;
}
//string PrevPermutation(string& str)
//{

//}

int main()
{
	//string str="DCFEBA";
	string str="AABB";
	//string str="ABC";
	int i=0;
	while(i<6)
	{
		cout<<NextPermutation(str)<<endl;
		i++;
	}
	return 0;
}
