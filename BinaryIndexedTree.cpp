/*
 * Binary Indexed Tree
 *
 * We use BITree as indexed tree
 * BITree init as nums.size()+1,0
 * Then we update every value of nums
 *
 * GetSum
 * i=i-(i&(-i));//i should be in range
 *
 * GetUpdate
 * i=i+(i&(-i));//i should be in range
 *
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

class BinaryIndexedTree{
	private:
		vector<int> BITree;

	public:
		BinaryIndexedTree(const vector<int> nums=vector<int>(0,0))
		{
			BITree.resize(nums.size()+1,0);//BITree's size is nums.size() plus one
			for(int i=0;i<nums.size();i++)
			{
				GetUpdate(i,nums[i]);
			}
		}

		bool GetUpdate(const int idx,const int val)
		{
			if(idx<0||idx>=BITree.size()-1) return false;
			int i=idx+1;
			while(i>0&&i<BITree.size())
			{
				BITree[i]+=val;
				i=i+(i&(-i));
			}
			return true;
		}

		int GetSum(const int idx)//get sum of 0.....idx-1
		{
			int i=idx+1;
			int sum=0;
			while(i>0&&i<BITree.size())
			{
				sum+=BITree[i];
				i=i-(i&(-i));
			}
			return sum;
		}
};

int main()
{
	srand(time(NULL));
	int len=10000;
	vector<int> nums;
	for(int i=0;i<len;i++)
	{
		nums.push_back(rand()%99999);
	}
	BinaryIndexedTree bit(nums);
	for(int i=0;i<nums.size();i++)
	{
		int sum=0;
		for(int j=0;j<nums.size();j++)
		{
			sum+=nums[j];
			if(sum==bit.GetSum(j))
			{
				cout<<"No."<<i<<" sum of pre "<<j<<" OK\n";
			}else
			{
				cout<<"No."<<i<<" sum of pre "<<j<<" Different\n";
				return 1;
			}
		}
		int num=rand()%999;
		int idx=rand()%len;
		nums[idx]+=num;
		bit.GetUpdate(idx,num);
	}

	return 0;
}
