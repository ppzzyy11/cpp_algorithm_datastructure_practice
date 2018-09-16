/*
 * Segment Tree wih Lazy Propagation
 *
 * We will try array this time
 * for 0_based arry: i th node's
 * left child node is 2*i+1,
 * right is 2*i+2
 * father is (i-1)/2
 *
 * Lazy Propagation(传递)
 * save time of range update in segment
 *
 * Update method: add one num to all element form index s to e:) not so good
 *
 * Passed Burte Test
*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Node{
	int l;
	int r;
	int sum;
	int idx;
	Node(int l,int r,int sum,int idx):l(l),r(r),sum(sum),idx(idx){}
};

class SegmentTree{
	private:
		vector<Node> tree;
		vector<int> lazy;//store the value to be added in node's range

		int ConstructTree(const vector<int>& nums,const int l,const int r,const int idx)
		{
			if(l>r) return 0;
			while(tree.size()<=idx)//adaptive size
			{
				tree.push_back(Node(-1,-1,-1,-1));
			}
			if(l==r)
			{
				tree[idx]=Node(l,r,nums[l],idx);
				return nums[l];
			}
			int m=(l+r)/2;
			int suml=ConstructTree(nums,l,m,idx*2+1);
			int sumr=ConstructTree(nums,m+1,r,idx*2+2);
			tree[idx]=Node(l,r,suml+sumr,idx);
			return suml+sumr;
		}

		int RangeUpdateUntil(const int s,const int e,const int num,const int idx)
		{
			if(idx>=tree.size()) return 0;
			const int i=idx;
			if(lazy[i]!=0)//there is pending update to aplly for the range
			{
				tree[i].sum+=(tree[i].r-tree[i].l+1)*lazy[i];//update node;you should know the meaning of lazy[i]
				if(i*2+1<lazy.size())lazy[i*2+1]+=lazy[i];
				if(i*2+2<lazy.size())lazy[i*2+2]+=lazy[i];
				lazy[i]=0;
			}
			if(s>tree[i].r||tree[i].l>e) return 0;//no update
			if(s<=tree[i].l&&e>=tree[i].r)//s e lies in node's range
			{
				lazy[i]=num;//Or you can update tree[i], and set its child lazy value as num
				return num*(tree[i].r-tree[i].l+1);
			}

			int sum=RangeUpdateUntil(s,e,num,idx*2+1)+RangeUpdateUntil(s,e,num,2*idx+2);//child will set thier lazy value themself
			tree[i].sum+=sum;
			return sum;
		}

		int RangeOfSumUntil(const int s,const int e,const int idx)
		{
			const int i=idx;
			if(idx>=tree.size()) return 0;
			if(lazy[i]!=0)//pending update
			{
				tree[i].sum+=(tree[i].r-tree[i].l+1)*lazy[i];
				if(i*2+1<lazy.size())lazy[i*2+1]+=lazy[i];
				if(i*2+2<lazy.size())lazy[i*2+2]+=lazy[i];
				lazy[i]=0;
			}
			if(s>tree[i].r||e<tree[i].l)
			{
				return 0;
			}
			if(s<=tree[i].l&&tree[i].r<=e)
			{
				return tree[i].sum;
			}

			int suml=RangeOfSumUntil(s,e,idx*2+1);
			int sumr=RangeOfSumUntil(s,e,idx*2+2);
			return suml+sumr;
		}

	public:
		SegmentTree(const vector<int>& nums)
		{
			//tree.resize(nums.size()*4,Node(-1,-1,-1,-1));
			ConstructTree(nums,0,nums.size()-1,0);//tree's node's number is not bigger then 2*num.size()
			lazy.resize(tree.size(),0);
		}

		int RangeUpdate(const int s,const int e,const int num)//num to be added in the range form s to e (included)
		{
			if(s>e) return 0;
			if(s<0||e>=tree.size()) return 0;
			RangeUpdateUntil(s,e,num,0);
		}

		int RangeOfSum(const int l,const int r)
		{
			if(l>r) return 0;
			if(l<0||r>=tree.size()) return 0;
			return RangeOfSumUntil(l,r,0);
		}

		void ShowLazy()
		{
			for(int i=0;i<lazy.size();i++)
			{
				cout<<lazy[i]<<' ';
			}
			cout<<'\n';
		}

		void ShowTree()
		{
			for(int i=0;i<tree.size();i++)
			{
				cout<<tree[i].l<<" to "<<tree[i].r<<" sum is "<<tree[i].sum<<"\n";
			}
			cout<<'\n';
		}
};



int main()
{
	//vector<int> nums={1, 3, 5, 7, 9, 11};
	vector<int> nums;

	srand(time(NULL));
	int size=1000;
	for(int i=0;i<size;i++)
	{
		nums.push_back(rand()%99);
	}
	SegmentTree t(nums);
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=t.RangeOfSum(i,j);
			if(sum==res)
			{
				cout<<i<<" to "<<j<<" OK! "<<res<<"\n";
			}else
			{
				cout<<i<<" to "<<j<<" NOT SAME! sum: "<<sum<<" res: "<<res<<"\n";
				return 1;
			}
		}
	}
	int s=rand()%(size/2);;
	int e=rand()%(size/2)+size/2;
	int num=rand()%999-500;;
	t.RangeUpdate(s,e,num);
	for(int i=s;i<=e;i++)
	{
		nums[i]+=num;
	}
	t.ShowTree();
	t.ShowLazy();
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=t.RangeOfSum(i,j);
			if(sum==res)
			{
				cout<<i<<" to "<<j<<" OK! "<<res<<"\n";
			}else
			{
				cout<<i<<" to "<<j<<" NOT SAME! sum: "<<sum<<" res: "<<res<<"\n";
				return 1;
			}
		}
	}
	return 0;
}
