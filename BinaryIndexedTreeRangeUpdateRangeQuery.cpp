/*
 * Binary Indexed Tree | RangeUpdate RangeSum
 *
 * Based on BIT point updata, point query
 *
 * we analysis 3 cases with sum query k and rangeupdate(l,r,val);
 *
 * So we use 2 BIT to store
 *
 * https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * We get sum from to k
 * An update (l,r,val)
 *
 * case 1:(k<l) is simple as sum would remain same as it was before update.

 * Case 2:(l<=k<=r) Sum was incremented by val*k – val*(l-1). We can find “val”, it is similar to finding the ith element in range update and point query article. So we maintain one BIT for Range Update and Point Queries, this BIT will be helpful in finding the value at kth index. Now val * k is computed, how to handle extra term val*(l-1)?
 * In order to handle this extra term, we maintain another BIT (BIT2). Update val * (l-1) at lth index, so when getSum query is performed on BIT2 will give result as val*(l-1).

 * Case 3:(k>r) The sum in case 3 was incremented by “val*r – val *(l-1)”, the value of this term can be obtained using BIT2. Instead of adding, we subtract “val*(l-1) – val*r” as we can get this value from BIT2 by adding val*(l-1) as we did in case 2 and subtracting val*r in every update operation.

 * Update Query
 * Update(BITree1, l, val)
 * Update(BITree1, r+1, -val)
 * UpdateBIT2(BITree2, l, val*(l-1))
 * UpdateBIT2(BITree2, r+1, -val*r)

 * Range Sum
 * getSum(BITTree1, k) *k) - getSum(BITTree2, k)
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
		bool Update(const int i,const int idx,const int val)
		{
			if(i<0||i>=BITree.size()) return false;
			int x=idx+1;
			for(;x<BITree[i].size();x+=(x&(-x)))
			{
				BITree[i][x]+=val;
			}
			return true;
		}
	public:
		BinaryIndexedTree(const int n)
		{
			BITree.resize(2,vector<int>(n+1,0));
		}
		bool RangeUpdate(const int l,const int r,const int val)
		{
			Update(0,l,val);
			Update(0,r+1,-val);
			Update(1,l,val*(l-1));
			Update(1,r+1,-val*r);
		}
		int RangeSum(const int l,const int r)//就这个地方,把int写成了bool,又让老子调了半天
		{
			return getSum(r)-getSum(l-1);
		}
		void Show()
		{
			for(auto bit:BITree)
			{
				for(auto b:bit)
				{
					cout<<b<<'\t';
				}
				cout<<endl;
			}
		}
		int getSum(const int i,const int idx)
		{
			if(i<0||i>=BITree.size()) return 0;
			int x=idx+1;
			int sum=0;
			for(;x>0;x-=(x&(-x)))
			{
				sum+=BITree[i][x];
			}
			return sum;
		}
		int getSum(const int k)
		{
			return getSum(0,k)*k-getSum(1,k);
		}
	protected:
		vector<vector<int>> BITree;
};

int main()
{
	int len=5;
	vector<int> arr(len,0);
	BinaryIndexedTree b(len);
	int l=0;
	int r=4;
	int val=5;
	b.RangeUpdate(l,r,val);
	for(int i=l;i<=r;i++)
		arr[i]+=val;
	//l=2;
	//r=4;
	//val=10;
	//b.RangeUpdate(l,r,val);
	//for(int i=l;i<=r;i++)
		//arr[i]+=val;
	for(int i=0;i<arr.size();i++)
	{
		for(int j=i;j<arr.size();j++)
		{
			int sum=0;
			for(int x=i;x<=j;x++)
			{
				sum+=arr[x];
			}
			if(sum==b.RangeSum(i,j))
			{
				cout<<i<<" to "<<j<<" OK!\n";
			}else
			{
				cout<<i<<" to "<<j<<" Different! "<<sum<<":"<<b.RangeSum(i,j)<<"\n";
			}
		}
	}
	return 0;
}
