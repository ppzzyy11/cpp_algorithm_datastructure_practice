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


ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<'\t';
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os, const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(auto num:nums)
	{
		cout<<num<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os, const vector<vector<string>>& strs)
{
	for(int i=0;i<strs.size();i++)
	{
		for(int j=0;j<strs[i].size();j++)
		{
			cout<<strs[i][j]<<' ';
			//cout<<i<<":"<<j<<endl;
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return os;
}

const int LENGTH_OF_POINTER =8;
//in this machine its its length is equal to long. below is how we do XOR of pointers in C++
//XORListNode* nxt=( XORListNode* )( (long)pre^(long)cur );//

struct Data{
	int val;
	Data(int v=0):val(v){}
};
ostream& operator<<(ostream& os,const Data& data)
{
	cout<<data.val;
	return os;
}
struct XORListNode{
	Data data;
	XORListNode* pnt;
	//XORListNode(){}
	XORListNode(Data data=Data(0),XORListNode* pnt=NULL):data(data),pnt(pnt){}
	//XORListNode
};
XORListNode* XOR(const XORListNode* p1,const XORListNode* p2)
{
	return ( XORListNode *)((long)p1^(long)p2);
}

//overload operator ^ for pointesr//Fail
//XORListNode* operator^(const XORListNode* p1,const void* p2)
//{
//return (XORListNode*)((long)p1^(long)p2);

//}
//XORListNode* operator^(const void* p1,XORListNode p2)
//{
//return (XORListNode*)((long)p1^(long)p2.data.val);
//}
//XORListNode operator^(const XORListNode& node1,const XORListNode& node2)
//{
//return node1;
//}
class XORList{
private:
	XORListNode* head;
	XORListNode* tail;
	int size;
public:
	XORList()
	{
		head= new XORListNode();
		tail= new XORListNode();
		head->pnt=tail;
		tail->pnt=head;
		size=0;
	}
	~XORList()
	{
		//free other nodes
		XORListNode* pre=head;
		XORListNode* cur=head->pnt;
		XORListNode* nxt=XOR(pre,cur->pnt);

		while(cur!=tail)
		{
			free(cur);
			nxt=XOR(pre,cur->pnt);
			pre=cur;
			cur=nxt;
		}

		free(head);
		free(tail);
	}
	int GetSize(){return size;}
	XORListNode* Insert(const Data& data,const int pos=-1)
	{
		if(pos<-1||pos>size) return NULL;

		XORListNode* pre;
		XORListNode* nxt;
		//new node will be inserted between pre and nxt

		if(pos==-1||pos==size)// new node will be inserted at the last pos
		{
			nxt=tail;
			pre=nxt->pnt;
		}else if(pos==0)//node will be inserted at the beginning
		{
			pre=head;
			nxt=head->pnt;
		}else
		{
			pre=GetNthNode(pos-1);
			nxt=GetNthNode(pos);
		}
		XORListNode* node=new XORListNode(data);
		node->pnt=XOR(pre,nxt);
		XORListNode* pre_pnt=pre->pnt;
		XORListNode* nxt_pnt=nxt->pnt;

		pre->pnt=XOR(pre_pnt,XOR(node,nxt));
		nxt->pnt=XOR(nxt_pnt,XOR(pre,node));
		size++;
		return node;
	}
	void ForwardTraversal()
	{
		XORListNode* pre=head;
		XORListNode* cur=head->pnt;
		XORListNode* nxt=XOR(pre,cur->pnt);//

		while(cur!=tail)
		{
			//do someting
			cout<<cur->data<<' ';

			nxt=XOR(cur->pnt,pre);
			pre=cur;
			cur=nxt;
		}
		cout<<endl;
	}
	void BackTraversal()
	{
		XORListNode* pre=tail;
		XORListNode* cur=tail->pnt;
		XORListNode* nxt=XOR(pre,cur->pnt);//


		while(cur!=head)
		{
			//do someting
			cout<<cur->data<<' ';

			nxt=XOR(cur->pnt,pre);
			pre=cur;
			cur=nxt;
		}
		cout<<endl;
	}
	XORListNode* GetNthNode(const int n=0)
	{
		if(n==-1) return head;
		if(n==size) return tail;
		if(n<-1||n>size)  return NULL;

		XORListNode* pre=head;
		XORListNode* cur=head->pnt;
		XORListNode* nxt=XOR(pre,cur->pnt);

		int i=0;
		while(i<n)
		{
			i++;
			nxt=XOR(pre,cur->pnt);
			pre=cur;
			cur=nxt;
		}
		return cur;
	}
	bool DeleteNthNode(const int n=0)
	{
		if(n<0||n>=size) return false;
		XORListNode* pre=GetNthNode(n-1);
		XORListNode* nxt=GetNthNode(n+1);
		XORListNode* nod=GetNthNode(n);

		pre->pnt=XOR(nxt,XOR(pre->pnt,nod));
		nxt->pnt=XOR(pre,XOR(nxt->pnt,nod));
		free(nod);
        size--;
		return true;
	}
};



int main()
{
	XORList lt;
	XORListNode* node=lt.GetNthNode();
	if(node!=NULL)
		cout<<node->data.val<<endl;
	for(int i=0;i<10;i++)
	{
		lt.Insert(Data(i));
	}
	if(lt.DeleteNthNode(0)==false) return 1;
	lt.ForwardTraversal();
	lt.BackTraversal();
	return 0;
}
