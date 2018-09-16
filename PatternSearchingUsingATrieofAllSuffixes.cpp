/*
 * Pattern Searching Using a Trie of Suffixes
 *
 * Different to KMP, Robin Karp, Finite Automate,Boyor Moore
 * we preprocess txt
 * We build a Trie of all Suffixes of txt,then we search pattern in the Trie
 *
 * We add an vector<int> int the Node to record the index in the Str when we insert the str
 *
 * When txt doesn't change very frequently and there are many patterns
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
#include<cmath>
#include<ctime>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}

const int ALPHABET_SIZE=256;

struct TrieNode{
	vector<TrieNode*> chldn;
	bool isEndOfWord;
	vector<int> indexes;
	TrieNode(bool end=0):isEndOfWord(end){chldn.resize(ALPHABET_SIZE,NULL);}
};

class Trie{
	private:
		TrieNode* head;
		inline int Index(const char& ch)
		{
			return ch;
		}
		void DestructNode(TrieNode* nod)
		{
			if(nod==NULL) return ;
			for(auto chld:nod->chldn)
			{
				DestructNode(chld);
			}
			free(nod);
		}
		TrieNode* InsertUntil(const string& str,const int i,TrieNode* root,const int index)
		{
			if(root==NULL)
			{
				TrieNode* nod=new TrieNode(0);
				if(i==str.size())
				{
					nod->isEndOfWord=1;
				}else
				{
					int idx=Index(str[i]);
					nod->chldn[idx]=InsertUntil(str,i+1,NULL,index+1);//mistake
				}
				nod->indexes.push_back(index);
				return nod;
			}else
			{
				root->indexes.push_back(index);
				if(i==str.size())
				{
					root->isEndOfWord=1;
				}else
				{
					int idx=Index(str[i]);
					root->chldn[idx]=InsertUntil(str,i+1,root->chldn[idx],index+1);
				}
				return root;
			}
		}
		bool SearchPatternUntil(const string& str, const int i,TrieNode* root,vector<int>& res)//search pattern and get the indexes
		{
			if(root==NULL) return false;
			if(i==str.size())
			{
				if( root->isEndOfWord==true )
				{
					return true;
				}
				res=root->indexes;
				return false;
			}
			int idx=Index(str[i]);
			return SearchPatternUntil(str,i+1,root->chldn[idx],res);
		}
		bool SearchUntil(const string& str, const int i,TrieNode* root)
		{
			if(root==NULL) return false;
			if(i==str.size())
			{
				if( root->isEndOfWord==true )
				{
					return true;
				}
				return false;
			}
			int idx=Index(str[i]);
			return SearchUntil(str,i+1,root->chldn[idx]);
		}
		bool NoChild(const TrieNode* nod)
		{
			if(nod==NULL)
			{
				return false;//can't delete this node
			}
			for(auto chld:nod->chldn)
			{
				if(chld!=NULL)
				{
					return false;
				}
			}
			return true;
		}
		TrieNode* DeleteUntil(const string& str,const int i,TrieNode* root)//we have ensured the str exiting in the Trie
		{
			if(i==str.size())
			{
				if(NoChild(root))
				{
					free(root);
					return NULL;
				}else
				{
					root->isEndOfWord=false;
					return root;
				}
			}

			int idx=Index(str[i]);
			root->chldn[idx]=DeleteUntil(str,i+1,root->chldn[idx]);//we are sure that chldn[idx] exit
			if(NoChild(root)&&root->isEndOfWord==false)
			{
				free(root);
				return NULL;
			}else
			{
				return root;
			}

		}
	public:
		Trie()
		{
			head=new TrieNode();
		}
		~Trie()
		{
			DestructNode(head);
		}
		bool Insert(const string& str,const int index)
		{
			if(Search(str))
			{
				return false;
			}
			InsertUntil(str,0,head,index);
			return true;
		}
		vector<int> SearchPattern(const string& str)
		{
			vector<int> res;
			SearchPatternUntil(str,0,head,res);
			for(int i=0;i<res.size();i++)
			{
				cout<<"Found "<<str<<" at index "<<res[i]-str.size()<<endl;
			}
			return res;
		}
		bool Search(const string& str)
		{
			return SearchUntil(str,0,head);
		}
		bool Delete(const string& str)
		{
			if(Search(str)==false)
			{
				return false;
			}
			DeleteUntil(str,0,head);
			return true;
		}

};

int main()

{
	string str="geeksforgeeks.org";
	Trie t;
	for(int i=0;i<str.size();i++)
	{
		t.Insert(str.substr(i),i);
		cout<<str.substr(i)<<endl;
	}
	cout<<endl<<"test:"<<endl;
	vector<string> pats=
	{
		"ee",
		"geek",
		"quiz",
		"forgeeks",
	};
	for(auto pat:pats)
	{
		t.SearchPattern(pat);
	}
	return 0;
}
