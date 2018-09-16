#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>//make_heap
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;

ostream& operator<<(ostream& os,const set<string>& strs)
{
	for(auto it=strs.begin();it!=strs.end();it++)
	{
		cout<<*it<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<bool>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>& mat)
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
ostream& operator<<(ostream& os,const vector<char>& chs)
{
	for(int i=0;i<chs.size();i++)
	{
		cout<<chs[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<string>>& mat)
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
ostream& operator<<(ostream& os,const vector<vector<vector<int>>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			for(int k=0;k<mat[i][j].size();k++)
			{
				cout<<mat[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<bool>>& mat)
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

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};


TreeNode* NewNode(int val)
{
	return (new TreeNode(val));
}

TreeNode* DeleteTree(TreeNode* node)
{
	if(node==NULL) return NULL;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
	return NULL;
}

void InorderTraversal(TreeNode* node)
{
	if(node==NULL) return ;
	InorderTraversal(node->left);
	cout<<node->val<<' ';
	InorderTraversal(node->right);
}

void PreorderTraversal(TreeNode* node)
{
	if(node==NULL) return ;
	cout<<node->val<<' ';
	PreorderTraversal(node->left);
	PreorderTraversal(node->right);
}

void PostorderTraversal(TreeNode* node)
{
	if(node==NULL) return ;
	PostorderTraversal(node->left);
	PostorderTraversal(node->right);
	cout<<node->val<<' ';
}

TreeNode* ConstructTreeFromAncestorMatrix(const vector<vector<bool>>& mat)
{
	vector<vector<int>> lvl(mat.size(),vector<int>(0,0));
	vector<int> ancs(mat.size(),0);
	for(int j=0;j<mat[0].size();j++)//O(N^2)
	{
		int cnt=0;
		for(int i=0;i<mat.size();i++)
		{
			if(mat[i][j]==1)
			{
				cnt++;
			}
		}
		lvl[cnt].push_back(j);
	}
	vector<TreeNode*> nodes;
	for(int i=0;i<mat.size();i++)
	{
		nodes.push_back(NewNode(i));
	}

	for(int i=1;i<lvl.size();i++)
	{
		for(int j=0;j<lvl[i].size();j++)
		{
			int son=lvl[i][j];
			for(int k=0;k<mat.size();k++)//k is ancestor
			{
				if(mat[k][son]==1&&ancs[k]<2)
				{
					TreeNode* p=nodes[k];
					TreeNode* s=nodes[son];
					if(p->left==NULL)
					{
						p->left=s;
					}
					else if(p->right==NULL)
					{
						p->right=s;
					}
					//cout<<k<<" is father of "<<son<<endl;
					ancs[k]++;
				}
			}
		}
	}
	cout<<ancs<<endl;
	return nodes[lvl[0][0]];
}
int main()
{
	vector<vector<bool>> mat=
	{
		{ 0, 0, 0, 0, 0, 0  },
		{ 1, 0, 0, 0, 1, 0  },
		{ 0, 0, 0, 1, 0, 0  },
		{ 0, 0, 0, 0, 0, 0  },
		{ 0, 0, 0, 0, 0, 0  },
		{ 1, 1, 1, 1, 1, 0  }
	};
	TreeNode* root=ConstructTreeFromAncestorMatrix(mat);
	cout<<endl<<"Inorder:"<<endl;
	InorderTraversal(root);
	cout<<endl<<"Preorder:"<<endl;
	PreorderTraversal(root);
	cout<<endl<<"Postorder:"<<endl;
	PostorderTraversal(root);
	DeleteTree(root);
	return 0;
}
