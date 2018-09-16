#include<iostream>
#include<time.h>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int cnt;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),cnt(1),left(NULL),right(NULL){}
};
class BinarySearchTree{
    private:
        void InOrder(TreeNode*) const;
        void PreOrder(TreeNode*) const;
        void PostOrder(TreeNode*) const;
        void LevelOrder(TreeNode*) const ;
        TreeNode* BuildHelper(const vector<int>& in,int s,int e);
        TreeNode* delHelper(TreeNode* root,const int key);

        TreeNode* root=NULL;
        const bool DEBUG=0;

    public:
        BinarySearchTree(const vector<int>);
        BinarySearchTree(void){;}
        ~BinarySearchTree();
        void InOrder(void) const
        {
            if(DEBUG) cout<<"InOrder:";
            InOrder(root);
            cout<<endl;
        }
        void PreOrder(void) const
        {
            if(DEBUG) cout<<"PreOrder:";
            PreOrder(root);
            cout<<endl;
        }
        void PostOrder(void) const
        {
            if(DEBUG) cout<<"PostOrder:";
            PostOrder(root);
            cout<<endl;
        }
        void LevelOrder(void)
        {
            if(DEBUG) cout<<"LevelOrder:\n";
            LevelOrder(root);
        }
        friend std::ostream& operator<<(std::ostream& stream,const BinarySearchTree& BST)
        {
            BST.InOrder();
            return stream;
        }

        TreeNode* searchKey(const int key) const;
        TreeNode* insert(const int key);
        TreeNode* del(const int key){if(DEBUG) cout<<"del"<<key<<endl;return root=delHelper(root,key);}
        TreeNode* leftMost(TreeNode* node)
        {
            if(node==NULL) return NULL;
            while(node->left)
            {
                node=node->left;
            }
            return node;
        }

};
BinarySearchTree::BinarySearchTree(const vector<int> in )
{
    root=BuildHelper(in,0,in.size()-1);
}
BinarySearchTree::~BinarySearchTree()
{
    if(root==NULL) return ;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        TreeNode* front=que.front();
        que.pop();
        if(front->left) que.push(front->left);
        if(front->right) que.push(front->right);
        if(DEBUG) { cout<<"del:"<<front->val<<":"<<front->cnt<<endl; }
        delete front;
    }
    return ;
}
TreeNode* BinarySearchTree::BuildHelper(const vector<int>& in,int s,int e)
{
    if(s>e||s<0||e>=in.size()) return NULL;

    if(s==e)
    {
        TreeNode* node = new TreeNode(in[s]);
        if(DEBUG) cout<<"create:"<<in[s]<<endl;
        return node;
    }

    int m=(s+e)>>1;
    if(DEBUG) cout<<"create:"<<in[m]<<endl;
    TreeNode* node = new TreeNode(in[m]);
    node->left=BuildHelper(in,s,m-1);
    node->right=BuildHelper(in,m+1,e);
    return node;
}
void BinarySearchTree::InOrder(TreeNode* root) const
{
    if(root==NULL) return ;
    InOrder(root->left);
    cout<<root->val<<":"<<root->cnt<<" ";
    InOrder(root->right);
}
void BinarySearchTree::PreOrder(TreeNode* root) const
{
    if(root==NULL) return ;
    cout<<root->val<<":"<<root->cnt<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void BinarySearchTree::PostOrder(TreeNode* root) const
{
    if(root==NULL) return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<":"<<root->cnt<<" ";
}
void BinarySearchTree::LevelOrder(TreeNode* root) const
{
    if(root==NULL) return ;

    queue<TreeNode*> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty())
    {
        TreeNode* frt=que.front();
        que.pop();
        if(frt==NULL)
        {
            cout<<endl;
            if(!que.empty())
                que.push(NULL);
        }
        else
        {
			cout<<frt->val<<":"<<frt->cnt<<" ";
            if(frt->left) que.push(frt->left);
            if(frt->right) que.push(frt->right);
        }
    }
    return ;
}
TreeNode* BinarySearchTree:: searchKey(const int key) const
{
    TreeNode* cur=root;
    while(cur!=NULL&&cur->val!=key)
    {
        if(cur->val>key) cur=cur->left;
        else cur=cur->right;
    }
    return cur;
}
TreeNode* BinarySearchTree::insert(const int key)
{
    if(DEBUG) cout<<"insert"<<key<<endl;
    TreeNode* cur=root;
    if(root==NULL) {root= new TreeNode(key);return root;}
    TreeNode* pre;
    while(cur!=NULL)
    {
        pre=cur;
         if(cur->val==key)
		 {
			 cur->cnt++;
			 return NULL;
		 }
         else if(cur->val>key) cur=cur->left;
         else cur=cur->right;
    }
    cur=new TreeNode(key);
    if(pre->val>key) pre->left=cur;
    else pre->right=cur;
    return cur;
}
TreeNode* BinarySearchTree::delHelper(TreeNode* root,const int key)
{
	if(root==NULL) return NULL;
	if(root->val>key) root->left=delHelper(root->left,key);
	else if(root->val<key) root->right=delHelper(root->right,key);

	else
	{
		if(root->cnt>1)
		{
			root->cnt--;return root;
		}else if(root->left==NULL)
		{
			TreeNode* right=root->right;
			delete root;
			return right;
		}else if(root->right==NULL)
		{
			TreeNode* left=root->left;
			delete root;
			return left;
		}else
		{
			TreeNode* node= leftMost(root->right);
            swap(root->cnt,node->cnt);
			swap(root->val,node->val);
			root->right=delHelper(root->right,key);
			return root;
		}
	}
}
int main()
{
	//vector<int> in{0,1,2,3,4,5,6,7,8,9,10};
	//BinarySearchTree BST(in);
	BinarySearchTree BST;
	//cout<<"YES:\n"<<BST<<endl<<"OMG"<<endl;
	//for(int i=4;i>=0;i--)
	//{
	//BST.insert(i);
	//cout<<BST<<endl;
	//}
	//BST.insert(100);
	//cout<<BST<<endl;
	//BST.PreOrder();
	//BST.PostOrder();
	//BST.LevelOrder();
	//for(int i=0;i<in.size();i++)
	//{
	//BST.del(in[i]);
	//cout<<BST<<endl;
	//}
	vector<int> tmp;
	srand(time(NULL));
	for(int i=0;i<10000;i++)
	{
		for(int j=0;j<10000;j++)
		{
			int num=random()%1000;
			BST.insert(num);
			//BST.InOrder();
			//BST.LevelOrder();
			tmp.push_back(num);
		}
        //BST.InOrder();
        //BST.LevelOrder();
		while(!tmp.empty())
		{
			int index=random()%tmp.size();
			BST.del(tmp[index]);
			tmp.erase(tmp.begin()+index);
			//BST.InOrder();
			//BST.LevelOrder();
		}
		cout<<i<<":"<<tmp.size()<<endl;
		BST.InOrder();
		BST.LevelOrder();
	}
	return 0;
}
