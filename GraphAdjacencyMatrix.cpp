#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
//Adjacency Matrix
using namespace std;

class Graph
{
    private:
        vector<vector<int>> matrix;
        vector<int> indegree;
        void DFSUntil(int v,vector<int>&visited)
        {
            visited[v]=1;
            cout<<v<<" ";//cao zuo

            vector<int> &arr=matrix[v];
            for(int i=0;i<arr.size();i++)
            {
                if(visited[i]==0&&matrix[v][i]!=0)
                {
                    DFSUntil(i,visited);
                }
            }
        }
        bool isCycleUntil(int i,vector<int>&visited,vector<int>&rec)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                rec[i]=1;

                vector<int>&arr=matrix[i];
                for(int j=0;j<arr.size();j++)
                {
                    if(matrix[i][j])
                    if(visited[j]==0&&isCycleUntil(j,visited,rec))
                        return 1;
                    else if(rec[j])
                        return 1;
                }
            }
            rec[i]=0;
            return 0;

        }
        bool isCycleUndirectedUntil(int v,vector<int>&visted,int parent)
        {
            visted[v]=1;
            vector<int>&arr=matrix[v];
            for(int i=0;i<arr.size();i++)
            {
                if(matrix[v][i]==1)
                {
                    if(visted[i]==1&&i!=parent)
                        return 1;
                    else if(visted[i]==0&&isCycleUndirectedUntil(i,visted,v))
                        return 1;
                }
            }
            return 0;

        }
        void TopologicalSortingUntil(int i,vector<int>&visited,stack<int>&st)
        {
            visited[i]=1;
            vector<int>&arr=matrix[i];
            for(int j=0;j<matrix.size();j++)
            {
                if(visited[j]==0&&matrix[i][j]!=0)
                {
                    TopologicalSortingUntil(j,visited,st);
                }
            }
            st.push(i);
        }
        void AllTopologicalSortingUntil(vector<int>&visited,vector<int>&tmp,vector<vector<int>>&res)
        {
            for(int i=0;i<visited.size();i++)
            {
                if(visited[i]==0&&indegree[i]==0)
                {
                    visited[i]=1;
                    tmp.push_back(i);
                    vector<int> &arr=matrix[i];
                    for(int j=0;j<arr.size();j++)
                    {
                        if(visited[j]==0&&matrix[i][j]!=0)
                            indegree[j]--;
                    }

                    AllTopologicalSortingUntil(visited,tmp,res);

                    visited[i]=0;
                    tmp.pop_back();
                    for(int j=0;j<arr.size();j++)
                    {
                        if(visited[j]==0&&matrix[i][j]!=0)
                            indegree[j]++;
                    }
                }
            }
            if(tmp.size()==visited.size()) res.push_back(tmp);
        }
    void AllPathsUntil(int src,vector<int>&vertices,vector<vector<int>>&res,vector<bool>&visited,vector<int> &sum)
    {
        visited[src]=1;
        vertices.push_back(src);
        if(vertices.size()==matrix.size())
        {
            for(int i=0;i<vertices.size();i++)
            {
                cout<<vertices[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<sum.size();i++)
            {
                cout<<sum[i]<<" ";
            }
            cout<<endl;

            res.push_back(vertices);
            vertices.pop_back();
            visited[src]=0;
            return ;
        }
        vector<int> &arr=matrix[src];
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0&&visited[i]==0)
            {
                sum.push_back(arr[i]);
                AllPathsUntil(i,vertices,res,visited,sum);
                sum.pop_back();
            }
        }
        vertices.pop_back();
        visited[src]=0;
    }
    public:
    Graph(int n)
    {
        matrix.resize(n,vector<int>(n,0));
        indegree.resize(n,0);
    }
    Graph(vector<vector<int>>& Mat)
    {
        if(Mat.size()==0) return ;
        if(Mat[0].size()!=Mat.size()) return ;
        matrix=Mat;
    }
    bool AddDirectedEdge(int s,int e,int val=1)
    {
        if(s<0||s>=matrix.size()) return 0;
        if(e<0||e>=matrix.size()) return 0;
        matrix[s][e]=val;
        indegree[e]++;
    }
    bool AddEdge(int s,int e,int val=1)
    {
        if(s<0||s>=matrix.size()) return 0;
        if(e<0||e>=matrix.size()) return 0;
        if(s==e) return 0;
        matrix[s][e]=val;
        matrix[e][s]=val;
        indegree[s]++;
        indegree[e]++;
    }
    void PrintGraph()
    {
        for(int i=0;i<matrix.size();i++)
        {
            cout<<i<<":\t";
            for(int j=0;j<matrix.size();j++)
            {
                //cout<<i<<">"<<j<<": "<<matrix[i][j]<<"\t\t";
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void BFS(int src=0)//ok 仅仅是对与连接图,非连通图要在每次que为空之后检查是否还有未visted的点，同时visited的点不可以变
    {
        queue<int> que;
        que.push(src);
        vector<int> visited(matrix.size(),0);
        visited[src]=1;
        while(!que.empty())
        {
            int fnt=que.front();
            que.pop();
            cout<<fnt<<" ";//cao zuo
            vector<int> & arr=matrix[fnt];
            for(int i=0;i<arr.size();i++)
            {
                if(visited[i]==0&&arr[i]!=0)
                {
                    visited[i]=1;
                    que.push(i);
                }
            }
        }
        cout<<endl;
    }
    void DFS()//ok ,可以处理非连接图
    {
        vector<int> visited(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            if(visited[i]==0)
            {
                DFSUntil(i,visited);
            }
        }
        cout<<endl;
    }
    void DFS(int src)//iterative stack  只是针对连通图，非连通图需要一直DFSUntil的函数，要逆序压人 // 这个 visited在cout时置位
    {
        stack<int> st;
        st.push(src);
        vector<int> visited(matrix.size(),0);
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(visited[top]==0)//输出时置1
            {
                visited[top]=1;
                cout<<top<<" ";//cao zuo
            }
            vector<int> &arr=matrix[top];
            for(int i=arr.size()-1;i>=0;i--)// 注意压的顺序
            {
                if(visited[i]==0&&matrix[top][i]!=0)
                {
                    st.push(i);
                }
            }
        }
        cout<<endl;
    }
    bool isCycle()//for directed graph
    {
        vector<int> visted(matrix.size(),0);
        vector<int> rec(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            if(isCycleUntil(i,visted,rec))
                return 1;
        }
        return 0;
    }
    bool isCycleUndirected()//for undirected graph
    {
        vector<int> visted(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            if(visted[i]==0)
                if(isCycleUndirectedUntil(i,visted,-1))
                    return 1;
        }
        return 0;
    }
    vector<int> TopologicalSorting()
    {
        stack<int> st;
        vector<int> visited(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
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
        //reverse(res.begin(),res.end());
        return res;
    }
    vector<vector<int>> AllTopologicalSorting()
    {
        vector<int> visited(matrix.size(),0);
        vector<int> tmp;
        vector<vector<int>> res;
        AllTopologicalSortingUntil(visited,tmp,res);
        return res;
    }
    void PrimMST()
    {
        vector<int> parent(matrix.size(),-1);
        vector<int> key(matrix.size(),INT_MAX);
        vector<int> mstSet(matrix.size(),0);

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
            if(pos==-1)
                break;

            mstSet[pos]=1;
            vector<int> &arr=matrix[pos];

            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=0&&mstSet[i]==0&&key[i]>arr[i])
                {
                    key[i]=arr[i];
                    parent[i]=pos;
                }
            }
        }


        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]!=-1)
                cout<<parent[i]<<"->"<<i<<":"<<matrix[parent[i]][i]<<endl;
            else
                cout<<parent[i]<<"->"<<i<<":"<<INT_MAX<<endl;
        }
    }
    vector<vector<int>> AllPaths(const int src=0)//test past
    {
        vector<bool> visited(matrix.size(),0);
        vector<int> sum;
        vector<int> vertices;
        vector<vector<int>> res;
        AllPathsUntil(src,vertices,res,visited,sum);
        return res;
    }
};




int main()
{
    vector<vector<int>> Mat={
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    Graph gh(Mat);
    //gh.AddDirectedEdge(0,4);
    //gh.AddDirectedEdge(0,1);
    //gh.AddDirectedEdge(4,2);
    //gh.AddDirectedEdge(4,3);
    //gh.AddDirectedEdge(2,1);

    //gh.AddDirectedEdge(0,1);
    //gh.AddDirectedEdge(0,4);
    //gh.AddDirectedEdge(1,2);
    //gh.AddDirectedEdge(1,3);
    //gh.AddDirectedEdge(2,4);

    //gh.PrimMST();
    //gh.PathMoreThanK(0,10);
    gh.AllPaths();
    return 0;
}
