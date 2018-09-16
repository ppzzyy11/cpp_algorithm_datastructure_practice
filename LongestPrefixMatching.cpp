/*
 * LongestPrefixMatching
 * According to two different ways, we have two functions:
 *
 * LongestPrefixMatching: the longest prefix matching that needn't to be a word
 *
 * LongestPrefixMatchingWord: the longest prefix matching that is also a word
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

const int ALPHABET_SIZE=26;

struct TrieNode{
	vector<TrieNode*> chldn;
	bool isEndOfWord;
	TrieNode(bool end=0):isEndOfWord(end){chldn.resize(ALPHABET_SIZE,NULL);}
};

class Trie{
	private:
		TrieNode* head;
		inline int Index(const char& ch)
		{
			if(ch>='a'&&ch<='z') return ch-'a';
			if(ch>='A'&&ch<='Z') return ch-'A';
			cerr<<"A character not in Alphabet: "<<ch<<endl;
			exit(1);
			return -1;
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
		TrieNode* InsertUntil(const string& str,const int i,TrieNode* root)
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
					nod->chldn[idx]=InsertUntil(str,i+1,NULL);//mistake
				}
				return nod;
			}else
			{
				if(i==str.size())
				{
					root->isEndOfWord=1;
				}else
				{
					int idx=Index(str[i]);
					root->chldn[idx]=InsertUntil(str,i+1,root->chldn[idx]);
				}
				return root;
			}
		}
		bool SearchUntil(const string& str, const int i,TrieNode* root)
		{
			if(root==NULL) return false;
			if(i==str.size()) return root->isEndOfWord==true;
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
		void LongestPrefixMatchingUntil(const string& str,const int i,TrieNode* root,string& res)
		{
			if(root==NULL) return ;
			if(i==str.size()) return ;
			int idx=Index(str[i]);
			if(root->chldn[idx]==NULL)
			{
				return ;
			}
			else res.push_back(str[i]);
			LongestPrefixMatchingUntil(str,i+1,root->chldn[idx],res);
		}
		void LongestPrefixMatchingWordUntil(const string& str,const int i,TrieNode* root,string& res,int& len)
		{
			if(root==NULL) return ;
			if(root->isEndOfWord==true)
			{
				len=i;
			}
			if(i==str.size()) return ;
			int idx=Index(str[i]);
			if(root->chldn[idx]==NULL)
			{
				return ;
			}
			else res.push_back(str[i]);
			LongestPrefixMatchingWordUntil(str,i+1,root->chldn[idx],res,len);
		}
	public:
		Trie(const vector<string>& strs)
		{
			head=new TrieNode();
			for(auto str:strs)
			{
				Insert(str);
			}
		}
		~Trie()
		{
			DestructNode(head);
		}
		bool Insert(const string& str)
		{
			if(Search(str))
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
		string LongestPrefixMatching(const string& str)//only longest prefix matching
		{
			string res;
			LongestPrefixMatchingUntil(str,0,head,res);
			return res;
		}
		string LongestPrefixMatchingWord(const string& str)//the longest prefix matching that is also a word
		{
			int len=0;
			string res;
			LongestPrefixMatchingWordUntil(str,0,head,res,len);
			while(res.size()>len)
			{
				res.pop_back();
			}
			return res;
		}

};

int main()
{
	vector<string> strs=
	{
		"are",
		"area",
		"base",
		"cat",
		"cater",
		"basement",
	};
	Trie t(strs);
	vector<string> tests=
	{
		"caterer",
		"basement",
		"are",
		"arex",
		"basemexz",
		"xyz",
	};
	for(auto test:tests)
	{
		cout<<test<<" LongestPrefixMatching is "<<t.LongestPrefixMatching(test)<<endl;
		cout<<test<<" LongestPrefixMatchingWord is "<<t.LongestPrefixMatchingWord(test)<<endl;
	}
	return 0;
}
