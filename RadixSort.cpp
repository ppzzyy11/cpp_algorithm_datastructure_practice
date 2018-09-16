/*
 *
 * RadixSort
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,vector<T>& nums)
{
	for(size_t i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<'\n';
	return os;
}

template<typename T>
T GetMax(const vector<T>& nums)
{
	T res;
	for(int i=0;i<nums.size();i++)
	{
		if(i==0)
		{
			res=nums[i];
		}else
		{
			res=max(nums[i],res);
		}
	}
	return res;
}


template<typename T>
void RadixSortHelper(vector<T>& nums,T b,T B)//b is the Base ,B is the Base for now
{
	vector<vector<T>> cnt((size_t)b,vector<T>(0,0));
	for(size_t i=0;i<nums.size();i++)
	{
		int idx=nums[i]/B%b;
		cnt[idx].push_back(nums[i]);
	}

	size_t j=0;
	for(size_t i=0;i<cnt.size();i++)
	{
		for(auto t:cnt[i])
		{
			nums[j++]=t;
		}
	}
}


template<typename T>
void RadixSort(vector<T>& nums,T b)//b is the base
{
	T Max=GetMax(nums);
	for(T t=1;t<Max;t=t*b)
	{
		RadixSortHelper(nums,b,t);
	}
}

int main()
{
	vector<int> nums={170, 45, 75, 90, 802, 24, 2, 66};
	RadixSort(nums,10);
	cout<<nums<<endl;
	return 0;
}
