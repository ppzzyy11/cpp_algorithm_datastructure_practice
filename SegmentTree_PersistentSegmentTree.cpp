/*
 * SegmentTree | Persistent Data Structures
 * This a partially persistent segmentTree. :) we won't want to edit the old version because there will be branches
 * We stores versions in the heads array.
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
		int Size=0;
		vector<Node*> heads;//stores the versions
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
		bool DestructTree(Node* nod,unordered_set<Node*> &hash)
		{
			if(nod==NULL) return true;
			if(hash.count(nod->left)==0)
			{
				DestructTree(nod->left,hash);
			}
			if(hash.count(nod->left)==0)
			{
				DestructTree(nod->right,hash);
			}
			if(hash.count(nod)==0)
			{
				free(nod);
				hash.insert(nod);
			}
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
		Node* ChangeNumberHelper(Node* nod,int idx,int num)
		{
			if(nod==NULL) return NULL;
			if(idx<nod->l||idx>nod->r) return nod;//nod should be shared
			Node* cpy=new Node(nod->l,nod->r,-1,NULL,NULL);
			cpy->left=ChangeNumberHelper(nod->left,idx,num);
			cpy->right=ChangeNumberHelper(nod->right,idx,num);
			if(nod->l<=idx&&idx<=nod->r)//need to update
			{
				cpy->sum=nod->sum+num;
			}else
			{
				int suml=(cpy->left==NULL?0:cpy->left->sum);
				int sumr=(cpy->right==NULL?0:cpy->right->sum);
				cpy->sum=suml+sumr;
			}
			return cpy;
		}
	public:
		SegmentTree(const vector<int>& nums=vector<int>(0,0))
		{
			heads.push_back(ConstructTree(nums,0,nums.size()-1));
			Size=nums.size();
		}
		~SegmentTree()
		{
			unordered_set<Node*> hash;
			for(auto head:heads)
			{
				DestructTree(head,hash);
			}
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
		int SumOfGivenRange(const int v,const int l,const int r)//OK
		{
			if(v<0||v>=heads.size()) return INT_MIN;
			return SumOfGivenRangeHelper(heads[v],l,r);
		}

		bool ChangeNumber(const int idx,const int num)
		{
			 heads.push_back(ChangeNumberHelper(heads.back(),idx,num));//默认对最后一个version进行修改,其实可以对之前的version进行修改,但是存储会很麻烦,会出现分支,这个么,不好存储
			 return true;
		}

};

int main()
{
	vector<int> nums={1, 3, 5, 7, 9, 11,99};
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
			int res=t.SumOfGivenRange(0,i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" answer same is "<<sum<<endl;
			}else
			{
				cout<<i<<" to "<<j<<" answer different is sum:"<<sum<<" res"<<res<<endl;
			}
		}
	}
	nums[3]+=100;
	t.ChangeNumber( 3,100 );
	cout<<"add 100 to nums[3]"<<endl;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=t.SumOfGivenRange(1,i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" answer same is "<<sum<<endl;
			}else
			{
				cout<<i<<" to "<<j<<" answer different is sum:"<<sum<<" res"<<res<<endl;
			}
		}
	}
	nums[4]-=100;
	t.ChangeNumber( 4,-100 );
	cout<<"add -100 to num[4]"<<endl;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=t.SumOfGivenRange(2,i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" answer same is "<<sum<<endl;
			}else
			{
				cout<<i<<" to "<<j<<" answer different is sum:"<<sum<<" res"<<res<<endl;
			}
		}
	}
	return 0;
}
