/*
 * Segment Tree | 	Sum of Given Range
 * There are two operations:
 * 1)change the value of an element in the array
 * 2)Query for the sum of given range
 *
 * There are O(N) nodes in Total
 * Father node is the merging of the two children nodes
 * So we will construct the tree from Leaf Nodes which are elements in the array
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
#include<ctime>
using namespace std;

struct Node{
	int l;
	int r;
	int sum;
	Node* left;
	Node* right;
	Node(int l,int r,int sum,Node* left,Node* right):l(l),r(r),sum(sum),left(left),right(right){}
};

//ATTENTION: the update is in problem .it should be the num to be adddd ,not the value it shall to be.
class SegmentTree{
	private:
		Node* head;
		Node* ConstructTree(const vector<int>& nums,int l,int r)
		{
			if(l>r) return NULL;
			int m=(l+r)/2;//if r==l+1 ,then m=l

			if(l==r)
			{
				Node* nod=new Node(l,m,nums[l],NULL,NULL);
				return nod;
			}else
			{
				Node* lc=ConstructTree(nums,l,m);
				Node* rc=ConstructTree(nums,m+1,r);
				Node* nod=new Node(l,r,lc->sum+rc->sum,lc,rc);
				return nod;
			}
		}
		bool DestructTree(Node* nod)
		{
			if(nod==NULL) return true;
			DestructTree(nod->left);
			DestructTree(nod->right);
			free(nod);
			return true;
		}
		int SumOfGivenRangeHelper(Node* nod,const int l,const int r)
		{
			if(l>r) return 0;
			if(l>nod->r) return 0;
			if(r<nod->l) return 0;
			if(nod->l>=l&&nod->r<=r) return nod->sum;
			return SumOfGivenRangeHelper(nod->left,l,r)+SumOfGivenRangeHelper(nod->right,l,r);
		}
		bool ChangeNumberHelper(Node* nod,int idx,int num)
		{
			if(nod==NULL) return false;
			if(idx<nod->l||idx>nod->r) return true;
			if(nod->l<=idx&&idx<=nod->r)
			{
				nod->sum=nod->sum-arr[idx]+num;
			}
			ChangeNumberHelper(nod->left,idx,num);
			ChangeNumberHelper(nod->right,idx,num);
			return true;
		}
		vector<int> arr;
	public:
		SegmentTree(const vector<int>& nums=vector<int>(0,0))
		{
			head=ConstructTree(nums,0,nums.size()-1);
			arr=nums;
		}
		~SegmentTree()
		{
			DestructTree(head);
		}
		void PreOrder(Node* nod)
		{
			cout<<nod->sum<<' ';
			PreOrder(nod->left);
			PreOrder(nod->right);
		}
		void InOrder(Node* nod)
		{
			InOrder(nod->left);
			cout<<nod->sum<<' ';
			InOrder(nod->right);
		}
		void PostOrder(Node* nod)
		{
			PostOrder(nod->left);
			PostOrder(nod->right);
			cout<<nod->sum<<' ';
		}
		int SumOfGivenRange(const int l,const int r)
		{
			return SumOfGivenRangeHelper(head,l,r);
		}

		bool ChangeNumber(const int idx,const int num)
		{
			 bool res=ChangeNumberHelper(head,idx,num);
			 arr[idx]=num;
			 return res;
		}
		bool OutputArr()
		{
			for(auto a:arr)
			{
				cout<<a<<' ';
			}
			cout<<endl;
			return true;
		}

};

int main()
{
	vector<int> nums={1, 3, 5, 7, 9, 11};
	vector<pair<int,int>> queries=
	{
		{1,3},
		{1,3},
	};
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
			int res=t.SumOfGivenRange(i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" answer same is "<<sum<<endl;
			}else
			{
				cout<<i<<" to "<<j<<" answer different is sum:"<<sum<<" res"<<res<<endl;
			}
		}
	}
	nums[3]=100;
	t.ChangeNumber( 3,100 );
	cout<<"change num[3] to 100"<<endl;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=t.SumOfGivenRange(i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" answer same is "<<sum<<endl;
			}else
			{
				cout<<i<<" to "<<j<<" answer different is sum:"<<sum<<" res"<<res<<endl;
			}
		}
	}
	cout<<"arr:"<<endl;
	t.OutputArr();
	return 0;
}
