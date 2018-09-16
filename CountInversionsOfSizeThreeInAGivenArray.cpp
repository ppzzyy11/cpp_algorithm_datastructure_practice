/*
 *
 * Binary Indexed Tree | Count Inversions of Size Three In An Array
 *
 * We implement another tow classs Bigger and Samller to get the temp value to get the result
 *
 * ATTENTION:
 * easier way, Insert the bigger element first ,and every time get the sum of coordinate x,y
 *
 * Use the binary indexed tree as a hash table, sort the nums and represetn them as thier order
 * Update nums[i],1
 * Get Sum to get the number of 1
 *
 * Update From the Right to left:Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j. ``
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

template<typename Value>
ostream& operator<<(ostream& os,const vector<Value>& nums)
{
	for(auto num:nums)
	{
		 cout<<num<<' ';
	}
	return os;
}

template<typename Value>
class BinaryIndexedTree{
	private:
		bool Convert(vector<Value>& nums)
		{
			vector<Value>tmp=nums;
			sort(tmp.begin(),tmp.end());
			unordered_map<Value,vector<int>> hash;
			for(int i=0;i<nums.size();i++)
			{
				hash[nums[i]].push_back(i);
			}
			for(int i=0;i<tmp.size();i++)
			{
				for(auto idx:hash[tmp[i]])
				{
					nums[idx]=i;
				}
			}
			return true;
		}
	public:
		BinaryIndexedTree(vector<Value>& nums)
		{
			Cnt=0;
			BIT.resize(nums.size()+1,0);
			Convert(nums);
		}
		bool GetUpdate(const int idx)
		{
			int i=idx+1;
			while(i<BIT.size())
			{
				BIT[i]+=1;
				i=i+(i&(-i));
			}
			return true;
		}
		Value GetSum(const int idx)const
		{
			Value sum=0;
			int i=idx+1;
			while(i>0)
			{
				sum+=BIT[i];
				i=i-(i&(-i));
			}
			return sum;
		}
		int GetCnt()const {return Cnt;}

	protected:
		vector<Value> BIT;
		int Cnt;
};

template<typename Value>
class Smaller:public BinaryIndexedTree<Value>
{
	public:
		Smaller(vector<Value>& nums):BinaryIndexedTree<Value>(nums)
		{
			smaller.resize(nums.size(),0);
			for(int i=nums.size()-1;i>=0;i--)
			{
				smaller[i]=this->GetSum(nums[i]);
				this->GetUpdate(nums[i]);
			}
		}
		int GetNthValue(const int idx)
		{
			if(idx<0||idx>=smaller.size())
			{
				return INT_MAX;
			}
			return smaller[idx];
		}
	protected:
		vector<int> smaller;
	private:
};

template<typename Value>
class Bigger:public BinaryIndexedTree<Value>
{
	public:
	Bigger(vector<Value>& nums):BinaryIndexedTree<Value>(nums)
	{
		bigger.resize(nums.size(),0);
		for(int i=0;i<nums.size();i++)
		{
			bigger[i]=this->GetSum(nums.size()-nums[i]-1);//reverse the nums[i]
			this->GetUpdate(nums.size()-1-nums[i]);
		}
	}
	int GetNthValue(const int idx)
	{
		if(idx<0||idx>=bigger.size())
		{
			return INT_MAX;
		}
		return bigger[idx];
	}
	protected:
		vector<int> bigger;
	private:

};

int main()
{
	vector<int> nums={1,4,-10,INT_MAX,900,INT_MIN};
	Smaller<int> sm(nums);
	for(int i=0;i<nums.size();i++)
	{
		cout<<sm.GetNthValue(i)<<' ';
	}
	cout<<'\n';
	Bigger<int> bg(nums);
	for(int i=0;i<nums.size();i++)
	{
		cout<<bg.GetNthValue(i)<<' ';
	}
	cout<<'\n';
	int res=0;
	for(int i=0;i<nums.size();i++)
	{
		res+=sm.GetNthValue(i)*bg.GetNthValue(i);
	}
	cout<<res<<endl;
	return 0;
}
