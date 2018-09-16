/*
 *
 * Binary Search Tree
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
using namespace std;

template<typename T>
class Node{
	protected:

	private:
		Node<T>* left;
		Node<T>* right;
		T key;
		int height;
	public:
		Node(T k,Node<T>* l=NULL,Node<T>* r=NULL,int h=1){key=k;left=l;right=r;height=h;}
		int GetHeight() {return height;}
		void SetHeight(const int h){height=h;}
		Node<T>* GetLeft(){return left;}
		void SetLeft(Node<T>* l){left=l;}
		Node<T>* GetRight(){return right;}
		void SetRight(Node<T>* r){right=r;}
		T GetKey(){return key;}
		void SetKey(const T t){key=t;}
};

template<typename T>
class BinarySearchTree
{
	protected:
		Node<T>* root;
	private:

		Node<T>* Insert(Node<T>* nod,const T t)
		{
			if(nod==NULL) return new Node<T>(t);
			if(nod->GetKey()==t) return nod;
			else if(nod->GetKey()>t)//t is smaller than nod->GetKey()
			{
				nod->SetLeft(Insert(nod->GetLeft(),t));
				return nod;
			}else {
				nod->SetRight(Insert(nod->GetRight(),t));
				return nod;
			}
		}

		bool Search(Node<T>* nod,const T t)
		{
			if(nod==NULL) return false;
			if(nod->GetKey()==t) return true;
			else if(nod->GetKey()>t)//t is smaller than nod->key , go left
			{
				return Search(nod->GetLeft(),t);
			}else {
				return Search(nod->GetRight(),t);
			}
		}

		Node<T>* Delete(Node<T>* nod,const T t)
		{
			if(nod==NULL) return NULL;
			if(nod->GetKey()<t)//t is bigger than nod->key , go right
			{
				nod->SetRight(Delete(nod->GetRight(),t));
			}else if(nod->GetKey()>t)//t is smaller than nod->key , go left
			{
				nod->SetLeft(Delete(nod->GetLeft(),t));
			}else{//nod->key == t is true
				if(nod->GetLeft()==NULL&&nod->GetRight()==NULL)//leaf node
				{
					delete nod;
					return NULL;
				}else if(nod->GetLeft()!=NULL&&nod->GetRight()!=NULL)//two children
				{
					Node<T>* predecessor= nod->GetLeft();
					while(predecessor->GetRight()!=NULL)
					{
						predecessor=predecessor->GetRight();
					}
					nod->SetKey(predecessor->GetKey());
					nod->SetLeft(Delete(nod->GetLeft(),predecessor->GetKey()));
				}else //one child
				{
					Node<T>* child=NULL;
					if(nod->GetLeft()!=NULL)
					{
						child=nod->GetLeft();
					}else
					{
						child=nod->GetRight();
					}
					delete nod;
					return child;
				}
			}
			return nod;
		}

		void Clear(Node<T>* nod)
		{
			if(nod==NULL) return ;
			Clear(nod->GetLeft());
			Clear(nod->GetRight());
			delete nod;
		}

		void PreOrder(Node<T>* nod)
		{
			if(nod==NULL) return ;
			cout<<nod->GetKey()<<' ';
			PreOrder(nod->GetLeft());
			PreOrder(nod->GetRight());
		}

		void InOrder(Node<T>* nod)
		{
			if(nod==NULL) return ;
			InOrder(nod->GetLeft());
			cout<<nod->GetKey()<<' ';
			InOrder(nod->GetRight());
		}

	public:
		BinarySearchTree(const vector<T>& ts=vector<T>(0,0))
		{
			root=NULL;
			for(auto t:ts)
			{
				Insert(t);
			}
		}
		~BinarySearchTree()
		{
			Clear(root);
			root=NULL;
		}
		void Insert(const T t)
		{
			root=Insert(root,t);
		}
		bool Search(const T t)
		{
			return Search(root,t);
		}
		void Delete(const T t)
		{
			root=Delete(root,t);
		}
		void PreOrder()
		{
			PreOrder(root);
			cout<<'\n';
		}
		void InOrder()
		{
			InOrder(root);
			cout<<'\n';
		}

};


int main()
{
	int len=12;
	srand(time(NULL));
	vector<int> nums={};
	for(int i=0;i<len;i++)
	{
		nums.push_back(rand()%999);
	}
	BinarySearchTree<int> bst(nums);
	while(nums.size()!=0)
	{
		bst.PreOrder();
		int idx=rand()%nums.size();
		bst.Delete(nums[idx]);
		swap(nums[idx],nums[nums.size()-1]);
		nums.pop_back();
	}
	bst.PreOrder();
	return 0;
}
