/*
 * Implement A Phone Directory | Trie
 *
 * We suggest every prefix
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

ostream& operator<<(ostream& os,const vector<string> &strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}

const int ALPHABET_SIZE=256;

struct TrieNode{
	vector<TrieNode*> chldn;
	bool isEndOfWord;
	vector<string> strs;
	TrieNode(bool end=0):isEndOfWord(end){chldn.resize(ALPHABET_SIZE,NULL);strs.resize(0,"");}
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
		inline bool isUpper(const char ch)
		{
			return ch>='A'&&ch<='Z';
		}
		TrieNode* InsertUntil(const string& str,int i,TrieNode* root)
		{
			if(root==NULL)
			{
				TrieNode* nod=new TrieNode(0);
				if(i==str.size())
				{
					nod->isEndOfWord=1;
					nod->strs.push_back(str);
				}else
				{
					int idx=Index(str[i]);
					nod->chldn[idx]=InsertUntil(str,i+1,NULL);//mistake
				}

				return nod;
			}else
			{
				if(i==str.size())
				{
					root->isEndOfWord=1;
					root->strs.push_back(str);
				}else
				{
					int idx=Index(str[i]);
					root->chldn[idx]=InsertUntil(str,i+1,root->chldn[idx]);
				}
				return root;
			}
		}
		bool SearchUntil(const string& str, int i,TrieNode* root)
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
		int NumberOfChildren(const TrieNode* nod)
		{
			int cnt=0;
			for(auto child:nod->chldn)
			{
				if(child!=NULL)
				{
					cnt++;
				}
			}
			return cnt;
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
		void OutputAllStrs(const TrieNode* nod)
		{
			if(nod==NULL) return ;
			if(nod->isEndOfWord)
			{
				cout<<nod->strs;
			}
			for(auto chld:nod->chldn)
			{
				if(chld!=NULL)
				{
					OutputAllStrs(chld);
				}
			}
		}
		void PhoneSuggestUntil(const string& str,int i,TrieNode* root)
		{
			if(root==NULL)
			{
				return;
			}
			if(i==str.size())
			{
				return ;
			}
			cout<<"\nSuggest "<<str.substr(0,i)<<":\n";
			OutputAllStrs(root);

			int idx=Index(str[i]);
			PhoneSuggestUntil(str,i+1,root->chldn[idx]);
			return ;

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
		bool Insert(const string& str)
		{
			if(Search(str)==true)
			{
				return false;
			}
			InsertUntil(str,0,head);
			return true;
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
		void PhoneSuggest(const string& str)
		{
			PhoneSuggestUntil(str,0,head);
		}

};

int main()
{
	vector<string> strs=
	{
		"gforgeeks",
	   	"geeksquiz",
	};
	vector<string> tests=
	{
		"gekk",
	};
	Trie t;
	for(auto str:strs)
	{
		t.Insert(str);
	}

	for(auto test:tests)
	{
		cout<<"Suggest "<<test<<":\n";
		t.PhoneSuggest(test);
	}
	return 0;
}
