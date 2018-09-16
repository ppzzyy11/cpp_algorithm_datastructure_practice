/*
 * Print All Words Matching A Pattern In CamelCase Notation Dictionary
 *
 * Different to KMP, Robin Karp, Finite Automate,Boyor Moore
 * we preprocess txt
 * We build a Trie of all Suffixes of txt,then we search pattern in the Trie
 *
 * We use the Uppercase character as keys and store the string in the leaf node when inserted
 * When we search the whole str and end at a leaf node, we print all the strs in that leaf node.
 *
 * We Have two ways to define the corresponds. Below is code:
	 if( root->isEndOfWord==true )
	 {
	//cout<<root->strs;//This only output the strict correspond ,eg For str"H", we all out strs only with one uppercase 'H'
	OutputAllStrs(root);//This output all the correspond that starts with a uppercase "H"
	return true;
	}
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
			while(i<str.size()&&!isUpper(str[i]))
			{
				i++;
			}
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
			while(i<str.size()&&!isUpper(str[i]))
			{
				i++;
			}
			if(root==NULL) return false;
			if(i==str.size())
			{
				if( root->isEndOfWord==true )
				{
					//cout<<root->strs;//This only output the strict correspond ,eg For str"H", we all out strs only with one uppercase 'H'
					OutputAllStrs(root);//This output all the correspond that starts with a uppercase "H"
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
		void LongestCommonPrefixUntil(TrieNode* root,string& res)
		{
			if(NumberOfChildren(root)>=2) return ;
			if(NumberOfChildren(root)==0) return ;
			for(int i=0;i<root->chldn.size();i++)
			{
				if(root->chldn[i]!=NULL)
				{
					res+=(char)i;
					LongestCommonPrefixUntil(root->chldn[i],res);
					break;
				}
			}
			return ;
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
		string LongestCommonPrefix()
		{
			string res="";
			LongestCommonPrefixUntil(head,res);
			return res;
		}

};

int main()
{
	vector<string> strs=
	{
		"Hi", "Hello", "HelloWorld",  "HiTech", "HiGeek",
		"HiTechWorld", "HiTechCity", "HiTechLab"
	};
	vector<string> tests=
	{
		"HT","H","HTC",
	};
	Trie t;
	for(auto str:strs)
	{
		t.Insert(str);
	}

	for(auto test:tests)
	{
		cout<<"Serach "<<test<<":\n";
		t.Search(test);
	}
	return 0;
}
