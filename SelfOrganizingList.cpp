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


struct Data{
	int val;
	Data(int val):val(val){}
	bool operator==(const Data& data)const
	{
		return data.val==val;
	}
};

ostream& operator<<(ostream& os, const Data& data)
{
	cout<<data.val;
	return os;
}

struct ListNode{
	Data data;
	ListNode* next;
	ListNode(Data data=Data(0),ListNode* next=NULL):data(data),next(next){}
};

//SelfOrganizingList: move the most searching node front
//There are three methods to comple it,
//1.Move the searched node front;
//2.Use a count array
//3.Transpose. swap the searched node with its preceding node
//
//we will impple the hardest 2rd method
//We assume that there are no duplicates in the list. This is the case in the real life
class SelfOrganizingList{//count method
	private:
		ListNode* head;
		int size;
		unordered_map<long,int> hash;//use long to repesent pointer,none is -1
		vector<vector<ListNode*>> nodes;//idx
		int GetHash(const ListNode* nod)
		{
			long lnod=(long)nod;
			if(hash.count(lnod)==0)
			{
				return -1;
			}else
			{
				return hash[lnod];
			}
		}
		bool SetHash(const ListNode* nod,const int val)
		{
			hash[(long)nod]=val;
		}
		bool NodesIncrease(ListNode*  nod)//有则+1,无则压人
		{
			int cnt=-1;
			cnt=GetHash(nod);
			if(-1==cnt)
			{
				if(nodes.size()==0) nodes.push_back(vector<ListNode*>(0,NULL));
				nodes[0].push_back(nod);
				SetHash(nod,0);
			}else
			{
				//if(NodesDelete(nod)==false) return false;
				cnt++;
				//cout<<"cnt:"<<cnt<<endl;
				SetHash(nod,cnt);
				while(nodes.size()<=cnt)
				{
					nodes.push_back(vector<ListNode*>(0,NULL));
				}
				nodes[cnt].push_back(nod);
			}
			return true;
		}
		bool NodesDelete(const ListNode* nod)
		{
			int cnt=GetHash(nod);
			if(cnt==-1) return false;
			vector<ListNode*>& node=nodes[cnt];
			for(int i=0;i<node.size();i++)
			{
				if(node[i]==nod)
				{
					swap(node[i],node[node.size()-1]);
					node.pop_back();
					return true;
				}
			}
			return false;
		}
		bool SwapNode(ListNode* nod1,ListNode* nod2)
		{
			if(nod1==nod2) return true;
			if(nod1==NULL||nod2==NULL) return false;
			ListNode* pre1=head;
			while(pre1->next)
			{
				if(pre1->next==nod1) break;
				pre1=pre1->next;
				if(pre1->next==NULL) return false;
			}

			ListNode* pre2=head;
			while(pre2->next)
			{
				if(pre2->next==nod2) break;
				pre2=pre2->next;
				if(pre2->next==NULL) return false;
			}

			swap(pre1->next,pre2->next);
			swap(nod1->next,nod2->next);
			return true;
		}

		bool Rerange()
		{
			ListNode* cur=head->next;
			while(cur->next!=NULL&&GetHash(cur)>=GetHash(cur->next))
			{
				cur=cur->next;
			}
			if(cur->next==NULL) return true;
			ListNode* fnt=head->next;
			while(GetHash(fnt)!=GetHash(cur->next)-1)
			{
				fnt=fnt->next;
			}
			SwapNode(fnt,cur->next);
			return true;
		}
		bool Count(const Data& data)
		{
			ListNode* cur=head->next;
			while(cur)
			{
				if(cur->data==data)
				{
					return 1;
				}
				cur=cur->next;
			}
			return 0;
		}

	public:
		int GetSize(){return size;}
		SelfOrganizingList()
		{
			size=0;
			head= new ListNode();
		}
		~SelfOrganizingList()
		{
			//free other nodes
			ListNode* cur=head->next;
			ListNode* nxt;
			while(cur)
			{
				nxt=cur->next;
				free(cur);
				size--;
				cur=nxt;
			}
			free(head);
		}
		void Traversal()
		{
			ListNode* cur=head->next;
			while(cur)
			{
				cout<<cur->data<<'\t';
				cur=cur->next;
			}
			cout<<'\n';
			return ;
		}
		bool Insert(const Data& data,int pos=-1)//-1 the last position
		{
			pos=-1;//New node's access time is 0
			if(pos<-1||pos>size) return false;
			if(Count(data)==1) return false;
			if(pos==-1)
			{
				pos=size;
			}
			if(pos==0)
			{
				ListNode* nod=new ListNode(data,head->next);
				head->next=nod;
				NodesIncrease(nod);
			}else
			{
				ListNode* pre=head;
				int i=0;
				while(i<pos)
				{
					i++;
					pre=pre->next;
				}
				ListNode* nod= new ListNode(data,pre->next);
				pre->next=nod;
				NodesIncrease(nod);
			}
			size++;
			return true;
		}

		bool Delete(int n=-1)//-1 is the last node
		{
			if(n<-1||n>=size) return false;
			if(n==-1)
			{
				n=size-1;
			}
			int i=0;
			ListNode* pre=head;
			while(i<n)
			{
				i++;
				pre=pre->next;
			}
			ListNode* nod=pre->next;
			pre->next=nod->next;
			NodesDelete(nod);
			free(nod);
			return true;
		}

		ListNode* GetNthNode(const int n=0)
		{
			if(n<0||n>=size) return NULL;
			ListNode* nod=head->next;
			int i=0;
			while(i<n)
			{
				i++;
				nod=nod->next;
			}
			return nod;
		}

		ListNode* SearchData(const Data& data)
		{
			ListNode* nod= head->next;
			while(nod)
			{
				if(nod->data==data)
				{
					NodesDelete(nod);//wtf
					NodesIncrease(nod);//need to find a new position
					Rerange();
					return nod;
				}
				nod=nod->next;
			}
			return NULL;
		}


		void ShowNodes()
		{
			for(int i=0;i<nodes.size();i++)
			{
				cout<<"level:"<<i<<':';
				for(int j=0;j<nodes[i].size();j++)
				{
					cout<<nodes[i][j]->data<<'\t';
				}
				cout<<endl;
			}
		cout<<endl;
		}
};

int main()
{
	SelfOrganizingList sol;
	int len=10;
	vector<int> cnts(len,0);//We can verify the cnts
	for(int i=0;i<len;i++)
	{
		sol.Insert(Data(i));
		sol.Insert(Data(i));//wo can sure that there is no duplicates int this ListNode
	}

	srand(time(NULL));
	for(int i=0;i<len;i++)
	{
		int j=rand()%len;
		sol.SearchData(Data(j));
		cnts[j]++;
	}
	sol.Traversal();
	return 0;
}
