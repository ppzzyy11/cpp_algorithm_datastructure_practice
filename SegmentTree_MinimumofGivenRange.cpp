/*
//This is a SegmentTree for the Qusetion-Range Minimum Query.
//Two operations allowed:
//1.Query for range minimum element
//2.Upodate a number in arr
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
	int mini;
	Node* left;
	Node* right;
	Node(int l,int r,int mini,Node* left=NULL,Node* right=NULL):l(l),r(r),mini(mini),left(left),right(right){}
};

//ATTENTION: the update is in problem .it should be the num to be adddd ,not the value it shall to be.
class SegmentTree{
	private:
		Node* head;
		vector<int> arr;
		Node* ConstructTreeHelper(const vector<int>& nums,int l,int r)
		{
			//cout<<l<<":"<<r<<endl;
			if(l>r) return NULL;
			if(l==r)
			{
				Node*nod= new Node(l,r,nums[l],NULL,NULL);//Left Nodes are always elements in arr
				//cout<<nod->l<<" to "<<nod->r<<" mini is "<<nod->mini<<endl;
				return nod;
			}
			int m=(l+r)/2;

			Node* left=ConstructTreeHelper(nums,l,m);
			Node* right=ConstructTreeHelper(nums,m+1,r);
			Node* nod= new Node(l,r,min(left->mini,right->mini),left,right);
			//cout<<nod->l<<" to "<<nod->r<<" mini is "<<nod->mini<<endl;
			return nod;
		}
		void DeleteNodes(Node* node)
		{
			if(node==NULL) return ;
			DeleteNodes(node->left);
			DeleteNodes(node->right);
			free(node);
			return ;
		}
		bool DestructTree()
		{
			DeleteNodes(head);
		}
		int RangeMinimumHelper(Node* node,int l,int r)
		{
			if(node==NULL) return INT_MAX;
			if(node->l>r) return INT_MAX;
			if(node->r<l) return INT_MAX;

			if(node->l>=l&&node->r<=r) return node->mini;//This the Key point of Segment:Don't go down for repeated operations
			return min(RangeMinimumHelper(node->left,l,r),RangeMinimumHelper(node->right,l,r));
		}
		void PreOrderHelper(Node* node)
		{
			if(node==NULL) return ;

			cout<<node->l<<" to "<<node->r<<" mini is "<<node->mini<<endl;
			PreOrderHelper(node->left);
			PreOrderHelper(node->right);
		}
		bool ChangeValueHelper(Node* node,const int idx,const int num)
		{
			if(node==NULL) return false;
			if(idx<node->l||idx>node->r) return false;

			//now idx is in range of node
			if(node->l==node->r)//This is the Leaf Node
			{
				node->mini=num;
				return true;
			}
			ChangeValueHelper(node->left,idx,num);
			ChangeValueHelper(node->right,idx,num);
			int l=(node->left==NULL?INT_MAX:node->left->mini);
			int r=(node->right==NULL?INT_MAX:node->right->mini);

			node->mini=min(l,r);
			return true;
		}
	public:
		void PreOrder()
		{
			PreOrderHelper(head);
		}
		SegmentTree(vector<int> nums=vector<int>(0,0))
		{
			arr=nums;
			head=ConstructTreeHelper(nums,0,nums.size()-1);
		}
		~SegmentTree()
		{
			DestructTree();
		}
		int RangeMinimum(int l,int r)
		{
			return RangeMinimumHelper(head,l,r);
		}
		bool ChangeValue(const int idx,const int num)
		{
			ChangeValueHelper(head,idx,num);
			arr[idx]=num;
			return true;
		}
};

int main()
{
	vector<int> nums={1, 3, 2, 7, 9, 11};
	SegmentTree t(nums);
	//t.PreOrder();
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int mini=INT_MAX;
			for(int k=i;k<=j;k++)
			{
				mini=min(mini,nums[k]);
			}
			int res=t.RangeMinimum(i,j);
			if(res==mini)
			{
				cout<<i<<" to "<<j<<"res is same to mini : "<<res<<endl;
			}else
			{
				cout<<i<<" to "<<j<<"res is different to mini  res:"<<res<<"   mini:"<<mini<<endl;
			}
		}
	}
	nums[1]=10;
	t.ChangeValue(1,10);
	cout<<"nums[1] is changed to 10\n";

	for(int i=0;i<nums.size();i++)
	{
		for(int j=i;j<nums.size();j++)
		{
			int mini=INT_MAX;
			for(int k=i;k<=j;k++)
			{
				mini=min(mini,nums[k]);
			}
			int res=t.RangeMinimum(i,j);
			if(res==mini)
			{
				cout<<i<<" to "<<j<<"res is same to mini : "<<res<<endl;
			}else
			{
				cout<<i<<" to "<<j<<"res is different to mini  res:"<<res<<"   mini:"<<mini<<endl;
			}
		}
	}
	return 0;
}
