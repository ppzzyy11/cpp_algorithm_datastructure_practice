/*
 * Binary Indexed Tree | RangeUpdate PointQuery
 *
 * RangeUpdate(l,r) O(1)
 * PointQuery(x) O(N)
 *
 * prerequisite :Prefix sum
 * RangeUpdate(l,r,val): arr[l]+=val;arr[r+1]-=val;
 * GetElement(x): for(int i=0;i<=x;i++) res+=arr[i];
 *
 * With Binary Indexed Tree, we can do both operations in O(logN)
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
		bool Update(const int idx,const int val)
		{
			if(idx<0||idx>=BITree.size()-1) return false;
			int i=idx+1;
			for(;i<BITree.size();i+=(i&(-i)))
			{
				BITree[i]+=val;
			}
			return true;
		}
		int GetSum(const int idx)
		{
			if(idx<0||idx>=BITree.size()-1) return false;
			int i=idx+1;

			int sum=0;
			for(;i>0;i-=(i&(-i)))
			{
				sum+=BITree[i];
			}
			return sum;
		}
	public:
		BinaryIndexedTree(const int n)//n is the size of the array
		{
			BITree.resize(n+1,0);
		}
		bool RnageUpdate(const int l,const int r,const int val)
		{
			if( Update(l,val) == false ) return false;
			if( Update(r+1,-val) == false) return false;
			return true;
		}
		int GetElement(const int idx)
		{
			return GetSum(idx);
		}
	protected:
		vector<int> BITree;
};

int main()
{
	int size=5;
	BinaryIndexedTree b(size);
	b.RnageUpdate(2,4,2);
	for(int i=0;i<size;i++)
	{
		cout<<i<<"th is "<<b.GetElement(i)<<endl;
	}
	b.RnageUpdate(0,3,4);
	for(int i=0;i<size;i++)
	{
		cout<<i<<"th is "<<b.GetElement(i)<<endl;
	}
	return 0;
}
