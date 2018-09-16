/*
 * Build Suffix Arrays Using Radix Sort
 *
 * We push_back 0 to the suffixes to make their length all same
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& nums)
{
	for(auto num:nums)
	{
		cout<<num<<' ';
	}
	cout<<endl;
}


inline bool operator<(const string& str1,const string& str2)
{
	if(str1.size()<str2.size()) return true;
	if(str1.size()>str2.size()) return false;
	for(int i=0;i<str1.size();i++)
	{
		if(str1[i]>str2[i]) return false;
		if(str1[i]<str2[i]) return true;
	}
	return true;
}

inline char GetNthChar(const string& str,const int i)
{
	if(i<0||i>=str.size()) return 0;
	return str[str.size()-1-i];
}

void RadixSortHelper(vector<string>& strs,int i)
{
	vector<vector<string>> cnt(256,vector<string>(0,""));
	for(auto str:strs)
	{
		cnt[GetNthChar(str,i)].push_back(str);
	}
	int j=0;
	for(int i=0;i<cnt.size();i++)
	{
		for(auto str:cnt[i])
		{
			strs[j++]=str;
		}
	}
}

void RadixSort(vector<string>& strs)
{
	int Max=0;
	for(str:strs)
	{
		Max=max(Max,(int)str.size());
	}
	for(int i=0;i<Max;i++)
	{
		RadixSortHelper(strs,i);
		cout<<strs<<endl;
	}
}

int main()
{
	string str="banana";
	vector<string> suffixes;
	for(int i=0;i<str.size();i++)
	{
		suffixes.push_back(str.substr(i));
		for(int j=str.size()-i;j<str.size();j++)
		{
			suffixes.back().push_back('\0');//这样才可以用Radix Sort
		}
	}
	cout<<suffixes<<endl;
	RadixSort(suffixes);
	cout<<suffixes<<endl;
	return 0;
}
