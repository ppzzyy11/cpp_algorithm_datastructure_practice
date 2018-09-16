/*
 * AVL Tree | Self Balanced Tree
 *
 * So many tiny tests passed
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& ts)
{
	for(auto t:ts)
	{
		cout<<t<<' ';
	}
	//cout<<'\n';
	return os;
}

template<typename T>
class AVLNode{
	private:
		int height;
		T key;
		AVLNode<T>* left;
		AVLNode<T>* right;
	public:
		AVLNode(T k,AVLNode<T>* l=NULL,AVLNode<T>* r=NULL,int h=1):key(k),left(l),right(r),height(h){;}
		~AVLNode(){}
		int GetHeight(){return height;}
		void SetHeight(const int h){height=h;}
		AVLNode<T>* GetLeft(){return left;}
		AVLNode<T>* GetRight(){return right;}
		void SetLeft(AVLNode<T>* l){left=l;}
		void SetRight(AVLNode<T>* r){right=r;}
		T GetKey(){return key;}
		void SetKey(T k){key=k;}
};


template<typename T>
class AVLTree
{
	private:
		AVLNode<T>* LeftRotate(AVLNode<T>* z)
		{
			if(z==NULL) return NULL;
			AVLNode<T>* y=z->GetRight();
			if(y==NULL) return NULL;
			AVLNode<T>* t2=y->GetLeft();

			y->SetLeft(z);
			z->SetRight(t2);
			UpdateHeight(z);
			UpdateHeight(y);
			return y;
		}

		AVLNode<T>* RightRotate(AVLNode<T>* z)
		{
			if(z==NULL) return NULL;
			AVLNode<T>* y=z->GetLeft();
			if(y==NULL) return NULL;
			AVLNode<T>* t3=y->GetRight();

			z->SetLeft(t3);
			y->SetRight(z);
			UpdateHeight(z);
			UpdateHeight(y);
			return y;
		}

		bool UpdateHeight(AVLNode<T>* nod)
		{
			if(nod==NULL) return false;
			int lh=GetHeight(nod->GetLeft());
			int rh=GetHeight(nod->GetRight());
			nod->SetHeight(max(lh,rh)+1);
			return true;
		}
		int GetHeight(AVLNode<T>* nod)
		{
			if(nod==NULL) return 0;
			return nod->GetHeight();
		}

		int GetBalance(AVLNode<T>* nod)
		{
			if(nod==NULL) return 0;
			return GetHeight(nod->GetLeft())-GetHeight(nod->GetRight());
		}

		AVLNode<T>*Insert(AVLNode<T>* nod,T t)
		{
			if(nod==NULL) return new AVLNode<T>(t,NULL,NULL,1);
			if(nod->GetKey()>t)// go to left child
			{
				nod->SetLeft(Insert(nod->GetLeft(),t));
			}else if(nod->GetKey()<t)//t is bigger than nod->t
			{
				nod->SetRight(Insert(nod->GetRight(),t));
			}else
			{
				return nod;
			}
			UpdateHeight(nod);

			int balance=GetBalance(nod);//balance factor

			if(balance>1&&t<nod->GetLeft()->GetKey())//left left
			{
				return RightRotate(nod);
			}

			if(balance<-1&&t>nod->GetRight()->GetKey())//right right
			{
				return LeftRotate(nod);
			}

			if(balance>1&&t>nod->GetLeft()->GetKey())//left right
			{
				nod->SetLeft(LeftRotate(nod->GetLeft()));
				return RightRotate(nod);
			}

			if(balance<-1&&t<nod->GetRight()->GetKey())//left right
			{
				nod->SetRight(RightRotate(nod->GetRight()));
				return LeftRotate(nod);
			}

			return nod;
		}

		AVLNode<T>* Delete(AVLNode<T>* nod,T t)
		{
			if(nod==NULL) return NULL;
			if(nod->GetKey()>t)//go to left
			{
				nod->SetLeft(Delete(nod->GetLeft(),t));
			}else if(nod->GetKey()<t)//go to right
			{
				nod->SetRight(Delete(nod->GetRight(),t));
			}else {
				if(nod->GetLeft()==NULL&&nod->GetRight()==NULL)//no child
				{
					delete nod;
					return NULL;
				}else if(nod->GetLeft()!=NULL&&nod->GetRight()!=NULL)//two children
				{
					AVLNode<T>* predecessor=nod->GetLeft();
					while(predecessor->GetRight()!=NULL)
					{
						predecessor=predecessor->GetRight();
					}
					nod->SetKey(predecessor->GetKey());
					nod->SetLeft(Delete(nod->GetLeft(),predecessor->GetKey()));
				}else// only one child
				{
					AVLNode<T>* child;
					if(nod->GetLeft()!=NULL)
						child=nod->GetLeft();
					else
						child=nod->GetRight();
					delete nod;
					return child;
				}
			}
			UpdateHeight(nod);
			int balance=GetBalance(nod);
			if(balance>1&&GetBalance(nod->GetLeft())>=0)//left left
			{
				return RightRotate(nod);
			}

			if(balance>1&&GetBalance(nod->GetLeft())<0)//left right
			{
				nod->SetLeft(LeftRotate(nod->GetLeft()));
				return RightRotate(nod);
			}

			if(balance<-1&&GetBalance(nod->GetRight())<=0)//right right
			{
				return LeftRotate(nod);
			}

			if(balance<-1&&GetBalance(nod->GetRight())>0)//right left
			{
				nod->SetRight(RightRotate(nod->GetRight()));
				return LeftRotate(nod);
			}
			return nod;
		}

		bool Search(AVLNode<T>* nod,T t)
		{
			if(nod==NULL) return false;
			if(nod->GetKey()==t)
			{
				return true;
			}else if(t<nod->GetKey())//go to nod->left
			{
				return Search(nod->GetLeft(),t);
			}else//go to right
			{
				return Search(nod->GetRight(),t);
			}
		}

		void PreOrder(AVLNode<T>* nod)
		{
			if(nod==NULL) return ;
			cout<<nod->GetKey()<<' ';
			PreOrder(nod->GetLeft());
			PreOrder(nod->GetRight());
		}
		void InOrder(AVLNode<T>* nod)
		{
			if(nod==NULL) return ;
			InOrder(nod->GetLeft());
			cout<<nod->GetKey()<< ' ';
			InOrder(nod->GetRight());
		}
		void PostOrder(AVLNode<T>* nod)
		{
			if(nod==NULL) return ;
			PostOrder(nod->GetLeft());
			PostOrder(nod->GetRight());
			cout<<nod->GetKey()<<' ';
		}
		void Clear(AVLNode<T>* nod)
		{
			if(nod==NULL) return ;
			Clear(nod->GetLeft());
			Clear(nod->GetRight());
			delete nod;
		}

	public:
		AVLTree(const vector<T> ts)
		{
			root=NULL;
			for(auto t:ts)
			{
				Insert(t);
			}
		}
		~AVLTree()
		{
			Clear(root);
			root=NULL;
		}
		void Insert(T t)
		{
			root=Insert(root,t);
		}
		void Delete(T t)
		{
			root=Delete(root,t);
		}

		bool Search(T t)
		{
			return Search(root,t);
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
		void PostOrder()
		{
			PostOrder(root);
			cout<<'\n';
		}
		int height()
		{
			return root==NULL?0:root->GetHeight();
		}
		void clear()
		{
			Clear(root);
			root=NULL;
		}
	protected:
		AVLNode<T>* root;

};

int main()
{
	int len=10000;

	vector<int> nums;
	srand(time(NULL));
	for(int i=0;i<len;i++)
	{
		nums.push_back(rand()%999);
	}
	AVLTree<int> AVLt(nums);
	while(nums.size()!=0)
	{
		int idx=rand()%nums.size();
		cout<<nums<<'\n';
		cout<<"delte "<<nums[idx]<<"\n";
		AVLt.Delete(nums[idx]);
		swap(nums[idx],nums[nums.size()-1]);
		nums.pop_back();
	}
	AVLt.PreOrder();
	AVLt.InOrder();
	cout<<AVLt.height()<<endl;
	return 0;
}
