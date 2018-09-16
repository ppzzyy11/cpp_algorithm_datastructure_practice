/*
 * Segment Tree | Minimum Range Query
 *
 * Two interface:
 * 1.Update(int idx,int val);//set val to nums[idx]
 * 2.GetMin(l,r) //get the Minimum of range from l to r
 *
 * Range Minimum Query
 * http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
 *
 */
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct TreeNode{
    int val;
    int l;
    int r;
    TreeNode* left,*right;
    TreeNode(int s,int e,int v):l(s),r(e),val(v),left(NULL),right(NULL){}
};
class SegmentTree{
    private:
        TreeNode* root;

        int getMin(TreeNode*,int l,int r);
        int Update(TreeNode*,int index,int val);
        TreeNode* BuildHelper(vector<int>&nums,int s,int e);
    public:
        int getMin(int l,int r)
        {
            return getMin(root,l,r);
        }
        int Update(int index,int val)
        {
            //没有对index进行判断
            return Update(root,index,val);
        }
        SegmentTree(vector<int>nums)
        {
            root=BuildHelper(nums,0,nums.size()-1);
        }
        ~SegmentTree()
        {
            if(root==NULL) return ;
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty())
            {
                TreeNode* fnt=que.front();
                que.pop();
                if(fnt->left) que.push(fnt->left);
                if(fnt->right) que.push(fnt->right);
                delete fnt;
            }
        }
};

int SegmentTree::getMin(TreeNode* node,int l,int r)
{
    if(node==NULL) return INT_MAX;
    if(l>r) return INT_MAX;
    if(l>node->r||r<node->l) return INT_MAX;
    if(node->r<=r&&node->l>=l) return node->val;
    return min( getMin(node->left,l,r),getMin(node->right,l,r) );
}

int SegmentTree::Update(TreeNode* node,int index,int val)
{
    if(node==NULL) return INT_MAX;
    if(node->l==node->r&&node->l==index)
    {
        node->val=val;
        return val;
    }else
    {
        if(node->left->l<=index&&node->left->r>=index)
        {
            int diff=Update(node->left,index,val);
        }else if(node->right->l<=index&&node->right->r>=index)
        {
            int diff=Update(node->right,index,val);
        }
        int l=(node->left==NULL?INT_MAX:node->left->val);
        int r=(node->right==NULL?INT_MAX:node->right->val);
        node->val=min(l,r);
        return node->val;
    }
}
TreeNode* SegmentTree::BuildHelper(vector<int>&nums,int s,int e)
{
    if(s>e) return NULL;
    if(s==e)
    {
        TreeNode* node= new TreeNode(s,e,nums[s]);
        return node;
    }else
    {
        TreeNode* node= new TreeNode(s,e,0);
        int m=(s+e)>>1;
        node->left=BuildHelper(nums,s,m);
        node->right=BuildHelper(nums,m+1,e);
        int val_l=(node->left==NULL?INT_MAX:node->left->val);
        int val_r=(node->right==NULL?INT_MAX:node->right->val);
        node->val=min(val_l,val_r);
        return node;
    }
}
int main()
{
    vector<int> nums{2,5,1,4,9,3};
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    SegmentTree seg(nums);
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
            cout<<seg.getMin(i,j)<<" ";
        cout<<endl;
    }
    seg.Update(3,100);
    nums[3]=100;
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
            cout<<seg.getMin(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
