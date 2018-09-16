#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
//Adjacency List Node
using namespace std;

struct ListNode{
    int num;
    int val;
    ListNode* next;
    ListNode(int n,int v):num(n),val(v),next(NULL){}
};
class Graph
{
    private:
    vector<ListNode*> vertex;
    vector<int> indegree;
    void DFSUntil(int v,vector<int>&visited)
    {
        visited[v]=1;
        ListNode* cur=vertex[v];
        cout<<cur->num<<" ";
        while(cur)
        {
            if(visited[cur->num]==0)
            {
                DFSUntil(cur->num,visited);
            }
            cur=cur->next;
        }
    }
    bool isCycleUntil(int i,vector<int>&visited,vector<int>&rec)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            rec[i]=1;

            ListNode* cur=vertex[i];
            while(cur)
            {
                if(visited[cur->num]==0&&isCycleUntil(cur->num,visited,rec))
                    return 1;
                else if(i!=cur->num&&rec[cur->num])
                    return 1;
                cur=cur->next;
            }
        }
        rec[i]=0;
        return 0;
    }
    bool isCycleUndirectedUntil(int i,vector<int>&visited,int parent)
    {
        visited[i]=1;
        ListNode* cur=vertex[i];
        cur=cur->next;
        while(cur)
        {
            if(visited[cur->num]==1&&cur->num!=parent)
                return 1;
            else if(visited[cur->num]==0&&isCycleUndirectedUntil(cur->num,visited,i))
                return 1;
            cur=cur->next;
        }
        return 0;
    }
    void TopologicalSortingUntil(int i,vector<int> & visited,stack<int> &st)
    {
        visited[i]=1;
        ListNode* tmp=vertex[i];

        while(tmp)
        {
            if(visited[tmp->num]==0)
            {
                TopologicalSortingUntil(tmp->num,visited,st);
            }
            tmp=tmp->next;
        }
        st.push(i);
    }
    void AllTopologicalSortingUntil(vector<int>&visited,vector<int>&tmp,vector<vector<int>> & res)
    {
        for(int i=0;i<vertex.size();i++)
        {
            if(visited[i]==0&&indegree[i]==0)
            {
                ListNode* cur=vertex[i];
                cur=cur->next;
                while(cur)
                {
                    indegree[cur->num]--;
                    cur=cur->next;
                }
                tmp.push_back(i);
                visited[i]=1;

                AllTopologicalSortingUntil(visited,tmp,res);

                visited[i]=0;
                cur=vertex[i];
                cur=cur->next;
                while(cur)
                {
                    indegree[cur->num]++;
                    cur=cur->next;
                } tmp.pop_back();
            }
        }
        if(tmp.size()==vertex.size())
            res.push_back(tmp);
    }
    public:
    Graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            vertex.push_back(new ListNode(i,0));
        }
        indegree.resize(vertex.size(),0);
    }
    bool AddEdge(int s,int d,int val=1)
    {
        if(s>=vertex.size()||s<0) return 0;
        if(d>=vertex.size()||d<0) return 0;

        indegree[d]++;
        ListNode* cur=vertex[s];
        while(cur->next)
        {
            if(cur->num==d)
            {
                cur->val=val;
                return 0;
            }
            cur=cur->next;
        }
        cur->next=new ListNode(d,val);
        return 1;
    }
    bool AddEdgeUndirected(int s,int d,int val=1 )
    {
        AddEdge(s,d,val);
        AddEdge(d,s,val);
    }
    void PrintGraph()
    {
        for(int i=0;i<vertex.size();i++)
        {
            ListNode* cur=vertex[i];
            while(cur)
            {
                cout<<cur->num<<":"<<cur->val<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }
    }
    void BFS(int src=0)
    {
        queue<ListNode*> que;
        vector<int>visited(vertex.size(),0);
        que.push(vertex[src]);
        visited[src]=1;
        while(!que.empty())
        {
            ListNode* fnt=que.front();
            que.pop();
            cout<<fnt->num<<":"<<fnt->val<<" ";
            ListNode* tmp=vertex[fnt->num];
            while(tmp)
            {
                if(visited[tmp->num]==0)
                {
                    que.push(tmp);
                    visited[tmp->num]=1;
                }
                tmp=tmp->next;
            }
        }
        cout<<endl;
    }
    void DFS()//可以处理非连接图 ok
    {
        vector<int> visited(vertex.size(),0);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0)
                DFSUntil(i,visited);
        }
        cout<<endl;
    }
    void DFS(int src)
    {
        stack<int> st;
        st.push(src);
        vector<int> visited(vertex.size(),0);
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            ListNode* cur=vertex[top];
            if(visited[top]==0)
            {
                visited[top]=1;
                cout<<top<<" ";
            }
            stack<int> tmp;
            while(cur)
            {
                if(visited[cur->num]==0)
                {
                    tmp.push(cur->num);
                }
                cur=cur->next;
            }
            while(!tmp.empty())
            {
                st.push(tmp.top());
                tmp.pop();
            }
        }
        cout<<endl;
    }
    bool isCycle()//for directed graph
    {
        vector<int> visited(vertex.size(),0);
        vector<int> rec(vertex.size(),0);

        for(int i=0;i<vertex.size();i++)
        {
            if(isCycleUntil(i,visited,rec))
                return 1;
        }
        return 0;
    }
    bool isCycleUndirected()
    {
        vector<int> visited(vertex.size(),0);
        for(int i=0;i<vertex.size();i++)
        {
            if(visited[i]==0)
            {
                if(isCycleUndirectedUntil(i,visited,-1))
                    return 1;
            }
        }
        return 0;
    }
    vector<int> TopologicalSorting()//可以处理非连通图
    {
        stack<int> st;
        vector<int> visited(vertex.size(),0);
        for(int i=0;i<vertex.size();i++)
        {
            if(visited[i]==0)
                TopologicalSortingUntil(i,visited,st);
        }
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    vector<vector<int>> AllTopologicalSorting()
    {
        vector<int> visited(vertex.size(),0);
        vector<vector<int>>res;
        vector<int> tmp;
        AllTopologicalSortingUntil(visited,tmp,res);
        return res;
    }
    void PrimMST()
    {
        vector<int> parent(vertex.size(),-1);
        vector<int> key(vertex.size(),INT_MAX);
        vector<int> mstSet(vertex.size(),0);

        key[0]=0;

        while(1)
        {
            int pos=-1;
            for(int i=0;i<key.size();i++)
            {
                if(mstSet[i]==0&&key[i]!=INT_MAX)
                {
                    if(pos==-1)
                        pos=i;
                    else if(key[i]<key[pos])
                        pos=i;
                }
            }

            if(pos==-1) break;

            mstSet[pos]=1;
            ListNode* cur=vertex[pos];
            while(cur)
            {
                if(mstSet[cur->num]==0&&key[cur->num]>cur->val)
                {
                    parent[cur->num]=pos;
                    key[cur->num]=cur->val;
                }
                cur=cur->next;
            }
        }
        for(int i=0;i<parent.size();i++)
        {
            cout<<parent[i]<<"->"<<i<<":"<<key[i]<<endl;
        }
    }
};




int main()
{
    Graph gh(9);
    gh.AddEdgeUndirected(0,1,4);
    gh.AddEdgeUndirected(0,7,8);
    gh.AddEdgeUndirected(1,2,8);
    gh.AddEdgeUndirected(1,7,11);
    gh.AddEdgeUndirected(2,3,7);
    gh.AddEdgeUndirected(2,5,4);
    gh.AddEdgeUndirected(2,8,2);
    gh.AddEdgeUndirected(3,4,9);
    gh.AddEdgeUndirected(3,5,14);
    gh.AddEdgeUndirected(4,5,10);
    gh.AddEdgeUndirected(5,6,2);
    gh.AddEdgeUndirected(6,7,1);
    gh.AddEdgeUndirected(6,8,6);
    gh.AddEdgeUndirected(7,8,7);


    gh.PrintGraph();
    gh.PrimMST();
    return 0;
}
