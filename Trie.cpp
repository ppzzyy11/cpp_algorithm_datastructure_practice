/*
 * Trie
 *
 * We will implement an Trie of Alphabet
 * Every word should be lower case
 *
 * We didnt implement delete function,but we may have zero or one or two things to do:
 * 1.set the last node's isEndOfWord 0
 * 2.delete the useless node
 *
 * so if u want to use the 2th idea to delete word in Trie. U must make sure u won't delete the still useful node.
 *
 * OMG ,below is some tips from the article
 *
 * During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie,
 * 1.Key may not be there in trie. Delete operation should not modify trie.
 * 2.Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
 * 3.Key is prefix key of another long key in trie. Unmark the leaf node.
 * 4.Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.
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

};

int main()
{
	vector<string> strs=
	{
		"there",
		"their",
		"any",
		"answer",
		"by",
		"bye",
	};
	Trie t(strs);
	vector<string> words=
	{
		"theref",
		"their",
		"anys",
		"answer",
		"by",
		"bye",
	};
	for(auto str:strs)
	{
		if(t.Search(str)==true)
		{
			cout<<"Found "<<str<<" in Trie\n";
		}else
		{
			cout<<"Not Found "<<str<<" in Trie\n";
		}
	}
	//for(auto str:words)
	//{
		//if(t.Insert(str)==true)
		//{
			//cout<<"Insert "<<str<<" into Trie\n";
		//}else
		//{
			//cout<<"Not Insert "<<str<<" into Trie\n";
		//}
	//}
	t.Delete("there");
	t.Delete("bye");
	for(auto str:strs)
	{
		if(t.Search(str)==true)
		{
			cout<<"Found "<<str<<" in Trie\n";
		}else
		{
			cout<<"Not Found "<<str<<" in Trie\n";
		}
	}
	return 0;
}
