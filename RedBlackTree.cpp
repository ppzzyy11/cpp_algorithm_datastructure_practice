/*
 *
 * Red Black Tree
 *
 * All tests pass.
 *
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<cctype>
#include<set>
#include<map>
#include<climits>
using namespace std;

enum Color { Red,Black,Double_Black };//0 1 2

template<typename T>
class Node{
	public:
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
		T key;
		int height;
		Color color;
		Node(T k=0,Color clr=Red,Node<T>*  p=NULL,Node<T>* l=NULL,Node<T>* r=NULL,int h=1){key=k;color=clr;left=l;right=r;parent=p;height=h;}
};

template<typename T>
ostream& operator<<(ostream& os,const Node<T>* nod)
{
	if(nod==NULL) {cout<<"node:NULL\t";return os;}
	if(nod) cout<<"nod:\t"<<nod->key<<'\t'<<"color:\t";
	string color;
	switch(nod->color)
	{
		case 0:
			color="Red";
			break;

		case 1:
			color="Black";
			break;

		case 2:
			color="Double_Black";
			break;
	};
	cout<<color<<"\t";
	if(nod->parent) {cout<<"parent:\t"<<nod->parent->key<<"\t";}
	if(nod->left) {cout<<"left:\t"<<nod->left->key<<"\t";}
	if(nod->right) {cout<<"right:\t"<<nod->right->key<<"\t";}
	cout<<'\n';
	return os;
}

template<typename T>
class RedBlackTree{
	protected:
		Node<T> black_null;//const member must be define in the Constructor
		Node<T> double_black_null;
		Node<T> *node;
	private:
		Node<T>* root;
		void clear(Node<T>* nod){if(nod==NULL||nod==(&double_black_null)) return ;clear(nod->left);clear(nod->right);free(nod);}
		Node<T>* insert(T t,Node<T>* nod);
		Node<T>* remove(T t,Node<T>* nod);
		void Inorder(Node<T>* nod){if(nod==NULL) return ;Inorder(nod->left);cout<<nod->key<<' ';Inorder(nod->right); }
		void Preorder(Node<T>* nod) { if(nod==NULL) return ; /*cout<<nod->key<<' ';*/ cout<<nod; Preorder(nod->left); Preorder(nod->right); }
		Node<T>* search(T t,Node<T>* nod);
		Node<T>* LeftRotate(Node<T>* nod);
		Node<T>* RightRotate(Node<T>* nod);
		void InsertBalance(Node<T>* x);
		void RemoveBalance(Node<T>* u);
		int BlackHeightBalanced(Node<T>* nod);
		bool ValidColor(Node<T>* nod);
	public:
		RedBlackTree();
		~RedBlackTree();

		void insert(T);
		void remove(T);
		void Inorder(){Inorder(root);}
		void Preorder(){Preorder(root);}
		Node<T>* search(T t){return search(t,root);}
		bool BlackHeightBalanced(){return BlackHeightBalanced(root)>=0;}
		bool ValidColor(){return ValidColor(root);}
};

template<typename T>
RedBlackTree<T>::RedBlackTree()
	:black_null(0,Black),double_black_null(0,Double_Black)
{
	root=NULL;
	node=NULL;
}

template<typename T>
RedBlackTree<T>::~RedBlackTree()
{
	clear(root);
	root=NULL;
}

template<typename T>
void RedBlackTree<T>::insert(T t)
{
	root=insert(t,root);
	InsertBalance(node);
	node=NULL;
}

template<typename T>
Node<T>* RedBlackTree<T>::insert(T t,Node<T>* nod)
{
	if(nod==NULL) return node=new Node<T>(t,Red);
	if(nod->key>t)//t is smaller, go to left
	{
		nod->left=insert(t,nod->left);
		nod->left->parent=nod;
	}else if(nod->key<t)//t is bigger, go to right
	{
		nod->right=insert(t,nod->right);
		nod->right->parent=nod;
	}else {
		return nod;//existed
	}
	//There should be rebalancing and recoloring
	return nod;
}

template<typename T>
void RedBlackTree<T>::remove(T t)
{
	root=remove(t,root);
	//this->Preorder();
	//cout<<"node:"<<endl<<node<<endl;
	RemoveBalance(node);
	if(root==(&double_black_null))
	{
		root=NULL;
	}
	node=NULL;
	double_black_null.parent=double_black_null.left=double_black_null.right=NULL;
	double_black_null.color=Double_Black;
}

template<typename T>
Node<T>* RedBlackTree<T>::remove(T t,Node<T>* nod)
{
	if(nod==NULL) return NULL;
	if(nod->key<t)//t is bigger, go to right
	{
		nod->right=remove(t,nod->right);
		if(nod->right!=NULL) nod->right->parent=nod;
		return nod;
	}else if(nod->key>t)//t is smaller, go to left
	{
		nod->left=remove(t,nod->left);
		if(nod->left!=NULL) nod->left->parent=nod;
		return nod;
	}else //nod->key == t
	{
		if(nod->left==NULL&&nod->right==NULL)//leaf node
		{
			if(nod->color==Red)
			{
				free(nod);
				return NULL;
			}else
			{
				node=&double_black_null;
				double_black_null.parent=nod->parent;
				free(nod);
				return &double_black_null;//deal the parent's child reference
			}
		}else if(nod->left!=NULL&&nod->right!=NULL)//nod has two children
		{
			Node<T>* pre=nod->left;
			while(pre->right!=NULL)//using precessor
			{
				pre=pre->right;
			}
			nod->key=pre->key;
			nod->left=remove(nod->key,nod->left);
			if(nod->left!=NULL) nod->left->parent=nod;
			return nod;
		}else //the nod has one child
		{
			Node<T>* rtn=(nod->left==NULL?nod->right:nod->left);
			rtn->parent=nod->parent;
			if(nod->color==Red||rtn->color==Red)
			{
				rtn->color=Black;
				node=NULL;
			}else
			{
				rtn->color=Double_Black;
				node=rtn;
			}
			free(nod);
			return rtn;
		}
	}
}

template<typename T>
Node<T>* RedBlackTree<T>::LeftRotate(Node<T>* z)//return the new top node
{
	if(z==NULL) return NULL;
	Node<T>* y=z->right;
	if(y==NULL) return z;//
	Node<T>* t2=y->left;

	//set the parent first
	if(z->parent!=NULL)
	{
		if(z->parent->left==z)
			z->parent->left=y;
		else
			z->parent->right=y;
	}

	y->parent=z->parent;
	z->parent=y;
	if(t2)
	t2->parent=z;

	z->right=t2;
	y->left=z;
	if(root==z)
		root=y;
	return y;
}
template<typename T>
Node<T>* RedBlackTree<T>::RightRotate(Node<T>* z)//return the top node
{
	if(z==NULL) return NULL;
	Node<T>* y=z->left;
	if(y==NULL) return z;
	Node<T>* t3=y->right;

	//set the parent first
	if(z->parent!=NULL)
	{
		if(z->parent->left==z)
			z->parent->left=y;
		else
			z->parent->right=y;
	}

	y->parent=z->parent;
	z->parent=y;
	if(t3)
	t3->parent=z;

	z->left=t3;
	y->right=z;

	if(root==z)
		root=y;
	return y;
}

template<typename T>
Node<T>* RedBlackTree<T>::search(T t,Node<T>* nod)
{
	if(nod==NULL) return NULL;
	if(nod->key<t)//t is bigger, go to right
	{
		return search(t,nod->right);
	}else if(nod->key>t)//t is smaller, go to left
	{
		return search(t,nod->left);
	}else {
		return nod;
	}
}

//OK
template<typename T>
void RedBlackTree<T>::InsertBalance(Node<T>* x)
{
	if(x==NULL) return ;
	if(x==root)
	{
		x->color=Black;
		return ;
	}
	Node<T>*p=x->parent;
	if(p==NULL) return ;
	if(p->color==Black) return ;//x is red, p is black ,return
	//below p must be red
	Node<T>*g=p->parent;
	if(g==NULL) return ;
	Node<T>*u;
	if(g->left==p)//Left
	{
		u=g->right;
		if(u==NULL)//then p,x must be red,g must be black
		{
			if(p->right==x)
			{
				LeftRotate(p);
				RightRotate(g);
				p->color=g->color=Red;
				x->color=Black;
				return ;
			}else
			{
				RightRotate(g);
				g->color=Red;
				p->color=Black;
				return ;
			}
		}
		if(u->color==Red)
		{
			p->color=u->color=Black;
			g->color=Red;
			InsertBalance(g);
			return ;
		}
		//uncle is Black
		if(p->left==x)//Left Left
		{
			RightRotate(g);
			g->color=Red;
			p->color=Black;
			return ;
		}else if(p->right==x)//Left Right
		{
			LeftRotate(p);
			RightRotate(g);
			x->color=Black;
			g->color=Red;
			return;
		}

	}
	else//g->right==p
		//Right
	{
		u=g->left;
		if(u==NULL)//then p,x must be red, g must be black
		{
			if(p->left==x)
			{
				RightRotate(p);
				LeftRotate(g);
				p->color=g->color=Red;
				x->color=Black;
				return ;
			}else
			{
				LeftRotate(g);
				g->color=Red;
				p->color=Black;
				return ;
			}
		}
		if(u->color==Red)
		{
			p->color=u->color=Black;
			g->color=Red;
			InsertBalance(g);
			return ;
		}
		if(p->right==x)//Right Right
		{
			LeftRotate(g);
			g->color=Red;
			p->color=Black;
			return ;
		}else if(p->left==x)//Right Left
		{
			RightRotate(p);
			LeftRotate(g);
			x->color=Black;
			g->color=Red;
			return ;
		}
	}
}

template<typename T>
void RedBlackTree<T>::RemoveBalance(Node<T>* u)//we shall repalce the double_black_null to NULL
{
	if(u==NULL) return ;
	if(u->color!=Double_Black) return ;//u's color is Double_Black now
	if(u==root)//if(u->parent==NULL)
	{
		root->color=Black;
		return ;
	}
	//u now is not root: u has a parent
	Node<T>* p=u->parent;
	if(p==NULL) return ;

	if(p->left==u)//Left
	{
		Node<T>* s=p->right;//get the slibing
		if(
				(s->left==NULL&&s->right==NULL)
				||(s->left!=NULL&&s->left->color==Black&&s->right==NULL)
				||(s->left==NULL&&s->right!=NULL&&s->right->color==Black)
				||(s->left!=NULL&&s->left->color==Black&&s->right!=NULL&&s->right->color==Black)
		  )//both children are black
		{
			if(s->color==Red)//s is red
			{
				LeftRotate(p);
				p->color=Red;
				s->color=Black;
				RemoveBalance(u);
				return ;
			}else //s's color is Black
			{
				s->color=Red;
				if(u==(&double_black_null))
					p->left=NULL;//replace the double_black_null
				else
					u->color=Black;
				if(p->color==Red)
				{
					p->color=Black;
				}
				else if(p->color==Black)
				{
					p->color=Double_Black;
					RemoveBalance(p);
				}
				return ;
			}

		}else //s is Black, and at least color of one child of s is red
		{
			Node<T>* r=s->right;
			Node<T>* l=s->left;//now l must be red
			if(r!=NULL&&r->color==Red)
			{
				LeftRotate(p);
				r->color=p->color;
				if(u==(&double_black_null))
				{
					p->left=NULL;
				}else
				{
					u->color=Black;
				}
				if(l!=NULL&&l->color==Red)
				{
					s->color=p->color;
					p->color=Black;
					r->color=Black;
				}
				return ;
			}
			{
				RightRotate(s);
				s->color=Red;
				l->color=Black;
				LeftRotate(p);
				s->color=p->color;//article not mentioned
				if(u==(&double_black_null))
				{
					p->left=NULL;
				}else
				{
					u->color=Black;
				}
				return ;
			}
		}
	}else //p->right == u
		//Right
	{
		Node<T>* s=p->left;//get the slibing
		if(
				(s->left==NULL&&s->right==NULL)
				||(s->left!=NULL&&s->left->color==Black&&s->right==NULL)
				||(s->left==NULL&&s->right!=NULL&&s->right->color==Black)
				||(s->left!=NULL&&s->left->color==Black&&s->right!=NULL&&s->right->color==Black)
		  )//color of both children of s are black
		{
			if(s->color==Red)//s's color is red
			{
				RightRotate(p);
				p->color=Red;
				s->color=Black;
				RemoveBalance(u);
				return ;
			}else
			{//s's color is black
				s->color=Red;
				if(u==(&double_black_null))
					p->right=NULL;//replace the double_black_null
				else
					u->color=Black;
				if(p->color==Red)
				{
					p->color=Black;
				}else if(p->color==Black)
				{
					p->color=Double_Black;
					RemoveBalance(p);
				}
				return ;
			}
		}else //s is Black, and at least color of one child of s is Red
		{
			Node<T>* l=s->left;
			Node<T>* r=s->right;
			if(l!=NULL&&l->color==Red)
			{
				RightRotate(p);
				l->color=p->color;
				if(u==(&double_black_null))
				{
					p->right=NULL;
				}else
				{
					u->color=Black;
				}
				if(r!=NULL&&r->color==Red)
				{
					s->color=p->color;
					p->color=Black;
					l->color=Black;
				}
				return ;
			}
			{
				LeftRotate(s);
				s->color=Red;
				r->color=Black;
				RightRotate(p);
				s->color=p->color;
				if(u==(&double_black_null))
				{
					p->right=NULL;
				}else
				{
					u->color=Black;
				}
				return ;
			}
		}
	}

}

//function OK
template<typename T>
int RedBlackTree<T>::BlackHeightBalanced(Node<T>* nod)
{
	if(nod==NULL) return 0;
	int l=BlackHeightBalanced(nod->left);
	int r=BlackHeightBalanced(nod->right);
	if(l<0||r<0||l!=r) return -1;
	return l+(nod->color==Black);
}

template<typename T>
bool RedBlackTree<T>::ValidColor(Node<T>* nod)
{
	if(nod==NULL) return true;
	if(nod->color==Red)
	{
		if(nod->left&&nod->left->color==Red) return false;
		if(nod->right&&nod->right->color==Red) return false;
	}
	return ValidColor(nod->left)&&ValidColor(nod->right);
}



//BST tests passed
//LeftRotate and RightRotate tests passed
int main()
{
	for(int j=0;j<40000;j++)
	{
		RedBlackTree<int> rb0;
		//vector<int> nums={4,2,6,1,3,5,7};
		//int del=1;
		vector<int> nums={};
		srand(time(NULL));
		int len=10000;
		for(int i=0;i<len;i++)
		{
			//nums.push_back(i*2+2);
			nums.push_back(rand()%100);
		}
		for(int i=0;i<nums.size();i++)
		{
			rb0.insert(nums[i]);
			//rb0.Preorder();
			if(rb0.ValidColor()==false||rb0.BlackHeightBalanced()==false)
			{
				cout<<"Insert ERROR"<<endl;
				return 1;
			}
			//cout<<rb0.BlackHeightBalanced()<<;
			//cout<<'\n';
		}
		//rb0.Preorder();
		//cout<<'\n';
		while(nums.size()!=0)
		{
			int idx=rand()%nums.size();
			swap(nums[idx],nums[nums.size()-1]);
			int num=nums[nums.size()-1];
			nums.pop_back();
			//cout<<"size: "<<nums.size()<<"\tremove "<<num<<endl;
			rb0.remove(num);
			//rb0.Preorder();
			//cout<<'\n';
			if(rb0.ValidColor()==false||rb0.BlackHeightBalanced()==false)
			{
				cout<<nums.size()<<"\tRemove ERROR"<<endl;
				return 1;
			}
		}
		//Node<int>* root=rb0.search(4);
		//queue<Node<int>*> que;
		//que.push(root);
		//while(!que.empty())
		//{
		//Node<int>* fnt=que.front();
		//que.pop();
		//fnt->color=Black;
		//if(fnt->left!=NULL) que.push(fnt->left);
		//if(fnt->right!=NULL) que.push(fnt->right);
		//}
		//rb0.Preorder();
		//cout<<endl<<rb0.ValidColor()<<endl;
		//cout<<endl<<rb0.BlackHeightBalanced()<<endl;
		//cout<<'\n';
		//rb0.remove(del);
		//rb0.Preorder();
		//cout<<endl<<rb0.ValidColor()<<endl;
		//cout<<endl<<rb0.BlackHeightBalanced()<<endl;

	}
	return 0;
}
