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

void Helper(TreeNode* node,vector<int>& anc,vector<vector<bool>>& mat)
{
	int j=node->val;
	for(auto i:anc)
	{
		mat[i][j]=1;
	}
	anc.push_back(j);
	if(node->left)
		Helper(node->left,anc,mat);
	if(node->right)
		Helper(node->right,anc,mat);
	anc.pop_back();
}

int NumberOfNode(TreeNode* node)
{
	if(node==NULL) return 0;
	return NumberOfNode(node->left)+NumberOfNode(node->right)+1;
}

vector<vector<bool>> ConstructAncestorMatrixFromAGivenBinaryTree(TreeNode* root)
{
	int N=NumberOfNode(root);
	vector<vector<bool>> mat(N,vector<bool>(N,0));
	vector<int> anc(0,0);
	Helper(root,anc,mat);
	return mat;
}

TreeNode* NewNode(int val)
{
	return (new TreeNode(val));
}

int main()
{
	TreeNode* root=NewNode(5);
	root->left=NewNode(1);
	root->right=NewNode(2);
	root->left->left=NewNode(0);
	root->left->right=NewNode(4);
	root->right->left=NewNode(3);
	cout<<ConstructAncestorMatrixFromAGivenBinaryTree(root)<<endl;
	return 0;
}
