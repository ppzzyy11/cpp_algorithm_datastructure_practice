/*
 *
 * Binary Indexed Tree | Count Inversions In An Array
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
			cout<<nums<<endl;
			for(int i=0;i<nums.size();i++)
			{
				Cnt+=GetSum(nums[i]);
				GetUpdate(nums[i]);
			}
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

int main()
{
	vector<int> nums={1,4,-10,INT_MAX,900,INT_MIN};
	BinaryIndexedTree<int> bit(nums);
	cout<<bit.GetCnt()<<endl;
	return 0;
}
