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

struct UnrolledListNode{
	vector<Data> datas;
	UnrolledListNode* next;
	UnrolledListNode(vector<Data> datas=vector<Data>(0,Data(0)),UnrolledListNode* next=NULL):datas(datas),next(next){}
};

class UnrolledLinkedListNode{//:) there is no strategies to insert Data,let it go, we can complement customized methods to saticify the demand.
	private:
		UnrolledListNode* head;
		int size;//size of nodes

	public:
		UnrolledLinkedListNode(const vector<vector<Data>>& datass=vector<vector<Data>>(0,vector<Data>(0,Data(0))))
		{
			head=new UnrolledListNode();
			UnrolledListNode* cur=head;
			for(int i=0;i<datass.size();i++)
			{
				//vector<Data>& datas=datass[i];
				cur->next=new UnrolledListNode(datass[i],NULL);
				cur=cur->next;
			}
			size=datas.size();
		}
		~UnrolledLinkedListNode()
		{
			//free other nodes
			UnrolledListNode* cur=head->next;
			UnrolledListNode* nxt=head->next;
			while(cur)
			{
				nxt=cur->next;
				free(cur);
				cur=nxt;
			}
			free(head);
		}

};


int main()
{

	return 0;
}
