#include<iostream>
#include<time.h>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

enum Color{red='R',black='B',double_black='D'};
struct TreeNode {
    int val;
    char color;
    int Bheight;
    TreeNode* left,*right,*parent;
    TreeNode(int x):val(x),color(red),Bheight(0),left(NULL),right(NULL),parent(NULL){}
};

class RedBlackTree{
    private:
        TreeNode* root;
        TreeNode* nil;
        TreeNode* INSERT;
        TreeNode* DELETION;


        inline TreeNode* getCousin(TreeNode* node)//可以对root和nil进行处理
        {
            TreeNode* p=node->parent;
            if(p->left==node) return p->right;
            else return p->left;
        }

        TreeNode* LeftRotate(TreeNode*);//OK
        TreeNode* RightRotate(TreeNode*);
        inline TreeNode* newNode(const int key);


        TreeNode* InOrder(TreeNode*) const;
        TreeNode* PreOrder(TreeNode*) const;
        TreeNode* PostOrder(TreeNode*) const;
        TreeNode* LevelOrder(TreeNode*) const;
        TreeNode* insertHelper(TreeNode* root,const int key);
        TreeNode* delHelper(TreeNode* root,const int key);
        TreeNode* search(TreeNode*,const int) const;
        inline TreeNode* getMinRight(TreeNode* node)//OK
        {
            node=node->right;
            while(node->left!=nil)
                node=node->left;
            return node;
        }

        TreeNode* IRC(TreeNode*);
        TreeNode* DRC(TreeNode*);



        const bool DEBUG =1;
    public:
        TreeNode* insert(const int key);
        TreeNode* del(const int key);
        TreeNode* search(const int key) const{return search(root,key);}

        void TEST_INSERT(){
            if(INSERT!=NULL)
            {
                cout<<"INSERT\t\tp\t\tCousin"<<endl;
                cout<<INSERT->val<<"\t\t"<<INSERT->parent->val<<"\t\t"<<getCousin(INSERT)->val<<endl;
            }
        }
        void TEST_DELETION(){
            if(DELETION!=NULL)
            {
                {
                    cout<<"DELETION\t\tp\t\tCousin"<<endl;
                    cout<<DELETION->val<<"\t\t"<<DELETION->parent->val<<"\t\t"<<getCousin(DELETION)->val<<endl;
                    cout<<DELETION->color<<"\t\t"<<DELETION->parent->color<<"\t\t"<<getCousin(DELETION)->color<<endl;
                }
            }
        }
        void InOrder(void) const {cout<<"InOrder:"<<endl;InOrder(root);cout<<endl;}
        void PreOrder(void) const {cout<<"PreOrder:"<<endl;PreOrder(root);cout<<endl;}
        void PostOrder(void) const {cout<<"PostOrder:"<<endl;PostOrder(root);cout<<endl;}
        void LevelOrder(void) const {cout<<"LevelOrder:"<<endl; LevelOrder(root); cout<<endl;}

        RedBlackTree(void){nil=new TreeNode(INT_MIN);nil->color=black;nil->left=nil->right=nil->parent=nil;root=nil;}
        ~RedBlackTree()
        {
            if(root==nil)
            {
                delete nil;
                return ;
            }
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty())
            {
                TreeNode* frnt=que.front();
                que.pop();
                if(frnt->left!=nil) que.push(frnt->left);
                if(frnt->right!=nil) que.push(frnt->right);
                delete frnt;
            }
            delete nil;
        }
};

TreeNode* RedBlackTree::insert(const int key)
{
    root=insertHelper(root,key);
    IRC(INSERT);
    return root;
}
TreeNode* RedBlackTree::insertHelper(TreeNode* root,const int key)//insert 没问题
//2017年 11月 25日 星期六 15:39:39 CST
{
    if(root==NULL) return NULL;
    if(root==nil)
    {
        if(DEBUG) cout<<"new Node:"<<key<<endl;
        TreeNode* node =newNode(key);
        INSERT=node;
        return node;
    } else if(root->val==key) {INSERT=NULL;return root;
    } else if(root->val<key) {
        //向right subtree search
        TreeNode* right=insertHelper(root->right,key);
        root->right=right;
        right->parent=root;
    }else if(root->val>key)
    {
        //search in left subtree
        TreeNode* left=insertHelper(root->left,key);
        root->left=left;
        left->parent=root;
    }
    INSERT=NULL;
    return root;
}
TreeNode* RedBlackTree::IRC(TreeNode* x)
{
    if(x==NULL) return NULL;
    if(x==root)
    {
        x->color=black;
        return x;
    }
    TreeNode* p=x->parent;
    TreeNode* u=getCousin(p);
    TreeNode* g=p->parent;

    if(DEBUG) cout<<"p,u,g GET"<<endl;
    if(DEBUG) cout<<p->val<<" "<<u->val<<" "<<g->val<<endl;

    if(p->color==black)
        return x;
    else if(p->color==red)
    {
        if(u->color==red)
        {
            if(DEBUG) cout<<"p:red\tu:red\n";
            if(DEBUG) cout<<"p:"<<p->val<<"\t"<<"u:"<<u->val<<endl;
            p->color=u->color=black;
            g->color=red;
            IRC(g);
            return x;
        }else
        {
            if(DEBUG) cout<<"p:red\tu:black\n";
            if(DEBUG) cout<<"p:"<<p->val<<"\t"<<"u:"<<u->val<<endl;
            if(g->left==p&&p->left==x)
            {
                if(DEBUG) cout<<"LL\n";
                RightRotate(g);
                x->color=g->color=red;
                p->color=black;
            }else if(g->left==p&&p->right==x)
            {
                if(DEBUG) cout<<"LR\n";
                LeftRotate(p);
                RightRotate(g);
                p->color=g->color=red;
                x->color=black;
            }else if(g->right==p&&p->right==x)//RR
            {
                if(DEBUG) cout<<"RR\n";
                LeftRotate(g);
                g->color=x->color=red;
                p->color=black;
            }else if(g->right==p&&p->left==x)
            {
                if(DEBUG) cout<<"RL\n";
                RightRotate(p);
                LeftRotate(g);
                g->color=p->color=red;
                x->color=black;
            }
            return x;
        }
    }
}
TreeNode* RedBlackTree::del(const int key)
{
    if(DEBUG)cout<<"del:"<<key<<endl;
    root=delHelper(root,key);
    //TEST_DELETION();
    DRC(DELETION);
    return root;
}
TreeNode* RedBlackTree::delHelper(TreeNode* node,const int key)
{
    if(node==NULL) return NULL;
    if(node==nil) {DELETION=NULL;return nil;}
    if(node->val>key) node->left=delHelper(node->left,key);
    else if(node->val<key) node->right=delHelper(node->right,key);
    else
    {
        if(DEBUG) cout<<"find key"<<endl;
        if(node->left==nil&&node->right==nil)
        {
            if(node==root)
            {
                delete node;
                root=nil;
                DELETION=NULL;
                return nil;
            }
            if(node->color==red)
            {
                TreeNode* p=node->parent;
                if(p->left==node) p->left=nil;
                else if(p->right==node) p->right=nil;
                DELETION=nil;
                delete node;
                return nil;
            }else if(node->color==black)
            {
                node->color=double_black;
                node->val=INT_MAX;
                DELETION=node;
            }
        }
        else if(node->left==nil)
        {
            TreeNode* right=node->right;
            //这3句可以删?
            TreeNode* p=node->parent;
            if(p->left==node) p->left=right;
            else if(p->right==node) p->right=right;

            right->parent=p;

            if(node->color==red||right->color==red) right->color=black;
            else if(right!=nil) right->color=double_black;
            delete node;
            DELETION=right;

            return right;
        }else if(node->right==nil)
        {
            TreeNode* left=node->left;

            //3
            TreeNode* p=node->parent;
            if(p->left==node) p->left=left;
            else if(p->right==node) p->right=node;

            left->parent=p;

            if(node->color==red||left->color==red) left->color=black;
            else if(left!=nil) left->color=double_black;
            delete node;
            DELETION=left;

            return left;

        }else
        {
            if(DEBUG) cout<<"Two children"<<endl;
            TreeNode* minRight=getMinRight(node);
            swap(node->val,minRight->val);
            if(DEBUG) cout<<"swap OK\nnode->val\tminRight->val"<<endl;
            if(DEBUG) cout<<"node->color\tminRight->color"<<endl;

            DELETION=NULL;
            node->right=delHelper(node->right,key);
        }
    }
    return node;

}
TreeNode* RedBlackTree::DRC(TreeNode* u)
{
    if(u==NULL) return NULL;
    if(u->color==black) return u;
    if(u->color==double_black)
    {
        if(u==root)
        {
            if(u->val==INT_MAX)
            {
                if(DEBUG) cout<<"\n\n\nroot last Node\n\n\n\n"<<endl;
                root=nil;
                delete u;
                return nil;
            }
            if(DEBUG) cout<<"root"<<endl;
            u->color=black;
            return u;
        }else
        {
            if(DEBUG) cout<<"u double_black"<<endl;
            TreeNode* p=u->parent;
            TreeNode*s=getCousin(u);
            TreeNode* r;
            if(s->color==black)
            {
                if(DEBUG) cout<<"s is black"<<endl;
                if(s==p->right&&s->right->color==red)//R R
                {
                    if(DEBUG) cout<<"RR"<<endl;
                    r=s->right;
                    LeftRotate(p);
                    s->color=p->color;
                    p->color=black;
                    r->color=black;
                    u->color=black;
                    if(DEBUG) cout<<"ReColor OK"<<endl;
                }else if(s==p->right&&s->left->color==red)//R L
                {
                    if(DEBUG) cout<<"RL"<<endl;
                    r=s->left;
                    RightRotate(s);
                    RightRotate(p);
                    s->color=p->color;
                    p->color=black;
                    r->color=black;
                    u->color=black;
                    if(DEBUG) cout<<"ReColor OK"<<endl;
                }else if(s==p->left&&s->left->color==red)//L L
                {
                    if(DEBUG) cout<<"LL"<<endl;
                    r=s->left;
                    RightRotate(p);
                    s->color=p->color;
                    p->color=black;
                    r->color=black;
                    u->color=black;
                    if(DEBUG) cout<<"ReColor OK"<<endl;
                }else if(s==p->left&&s->right->color==red)// L R
                {
                    if(DEBUG) cout<<"LR"<<endl;
                    r=s->right;
                    LeftRotate(s);
                    RightRotate(p);
                    s->color=p->color;
                    p->color=black;
                    r->color=black;
                    u->color=black;
                    if(DEBUG) cout<<"ReColor OK"<<endl;
                }else if(s->left->color==black&&s->right->color==black)// s has two black children case
                {
                    if(DEBUG) cout<<"tow black children"<<endl;
                    u->color=black;
                    s->color=red;
                    if(p->color==red)
                    {
                        p->color=black;
                    }
                    else if(p->color==black) {p->color=double_black;DRC(p);}
                }else
                {
                    if(DEBUG) cout<<"program never go here"<<endl;
                    if(DEBUG) cout<<"p:"<<p->val<<" "<<p->color<<endl;
                    if(DEBUG) cout<<"s:"<<s->val<<" "<<s->color<<endl;
                    if(DEBUG) cout<<"left child:"<<s->left->val<<" "<<s->left->color<<endl;
                    if(DEBUG) cout<<"right child:"<<s->right->val<<" "<<s->right->color<<endl;
                }
            }else //s is RED
            {
                if(DEBUG) cout<<"s is Red"<<endl;
                if(s==p->right)
                {
                    if(DEBUG) cout<<"s is p's right child"<<endl;
                    LeftRotate(p);
                    s->color=black;
                    p->color=red;
                    DRC(u);
                }else if(s==p->left)
                {
                    if(DEBUG) cout<<"s is p's left child"<<endl;
                    RightRotate(p);
                    p->color=red;
                    s->color=black;
                    DRC(u);
                }
            }
        }
    }
    if(DEBUG) cout<<"DELETION:"<<u->val<<" "<<u->color<<endl;
    if(u->val==INT_MAX&&u->color==black)
    {
        TreeNode* p=u->parent;
        if(p->left==u) {p->left=nil;}
        else if(p->right==u) {p->right=nil;}
        delete u;
    }
    if(DEBUG) cout<<"DELETE OVER"<<endl;
    return NULL;
}
inline TreeNode* RedBlackTree::newNode(const int key)
{
    TreeNode* node=new TreeNode(key);
    node->left=node->right=node->parent=nil;
    return node;
}
TreeNode* RedBlackTree::InOrder(TreeNode* root) const
{
    if(root==nil) return nil;
    InOrder(root->left);
    cout<<root->val<<":"<<root->color<<"  ";
    InOrder(root->right);
    return root;
}
TreeNode* RedBlackTree::LevelOrder(TreeNode* root)const
{
    if(root==nil) return nil;
    queue<TreeNode*> que;
    que.push(root);
    que.push(nil);
    while(!que.empty())
    {
        TreeNode* f= que.front();
        que.pop();
        if(f==nil)
        {
            cout<<endl;
            if(!que.empty()) que.push(nil);
        }else
        {
            cout<<f->val<<":"<<f->color<<"  ";
            if(f->left!=nil) que.push(f->left);
            if(f->right!=nil) que.push(f->right);
        }
    }
    return root;
}
TreeNode* RedBlackTree::LeftRotate(TreeNode* g)
{
    if(DEBUG)cout<<"LEFT ROTATE\n";
    TreeNode* god=g->parent;
    TreeNode* p=g->right;

    g->parent=p;
    g->right=p->left;
    p->left->parent=g;

    p->left=g;
    p->parent=god;

    if(god->left==g) god->left=p;
    else if(god->right==g) god->right=p;
    if(root==g) root=p;
    if(DEBUG)cout<<"LEFT ROTATE OVER\n";
    return g;
}
TreeNode* RedBlackTree::RightRotate(TreeNode* g)
{
    if(DEBUG)cout<<"RIGHT ROTATE\n";
    TreeNode* god=g->parent;
    TreeNode* p=g->left;

    g->parent=p;
    g->left=p->right;
    p->right->parent=g;

    p->right=g;
    p->parent=god;

    if(god->left==g) god->left=p;
    else if(god->right==g) god->right=p;
    if(root==g) root=p;
    if(DEBUG)cout<<"RIGHT ROTATE OVER\n";
    return g;
}
TreeNode* RedBlackTree::search(TreeNode* node,const int key) const
{
    if(node==nil)
    {
        cout<<"No val"<<key<<"found\n";
        return nil;
    }
    if(node->val>key)
    {
        return search(node->left,key);
    }else if(node->val<key)
    {
        return search(node->right,key);
    }else
    {
        TreeNode* p=node->parent;
        TreeNode* l=node->left;
        TreeNode* r=node->right;
        cout<<"find "<<key<<endl;
        cout<<"p\tl\tr\n";
        cout<<p->val<<"\t"<<l->val<<"\t"<<r->val<<endl;
        return node;
    }
}
int main()
{
    RedBlackTree RBT;
    //vector<int> nums{8,7,10,12,13,14,15,6,5,4,3,2,1,9};
    //for(int i=0;i<nums.size();i++)
        //RBT.insert(nums[i]);
    //RBT.InOrder();
    //RBT.LevelOrder();
    //int num=1;
    //RBT.del(8);
    //for(int f=1;f<16;f++)
    //{
        //cout<<endl;
        //RBT.search(f);
    //}
    //RBT.InOrder();
    //RBT.LevelOrder();
    {
        srand(time(NULL));
        vector<int> tmp;
        for(int j=0;j<100;j++)
        {
            for(int i=0;i<100;i++)
            {
                int num=random()%50000;
                tmp.push_back(num);
                RBT.insert(num);
                RBT.TEST_INSERT();
                RBT.InOrder();
                RBT.LevelOrder();
            }
            while(!tmp.empty())
            {
                bool DEBUG =0;
                int i=random()%tmp.size();
                if(DEBUG) cout<<"i:"<<i<<endl;
                RBT.del(tmp[i]);
                RBT.TEST_DELETION();
                RBT.InOrder();
                RBT.LevelOrder();
                if(DEBUG) cout<<"erase:"<<tmp[i]<<endl;
                tmp.erase(tmp.begin()+i);
                if(DEBUG) cout<<"erase ok! tmp.size():"<<tmp.size()<<endl;
            }
            RBT.InOrder();
            RBT.LevelOrder();
            cout<<j<<" "<<tmp.size()<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }
    }
    return 0;
}
