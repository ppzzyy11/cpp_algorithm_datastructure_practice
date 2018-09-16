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

        void DFSUntil(int src,vector<bool>&visited,vector<int>&res)
        {
            cout<<src<<" ";
            visited[src]=1;
            res.push_back(src);
            vector<int>&arr=matrix[src];
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=0&&visited[i]==0)
                {
                    DFSUntil(i,visited,res);
                }
            }
        }
        bool isDirectedCycleUntil(int src,vector<bool>&visited,vector<bool>&rec)//test OK
        {
            if(visited[src]==0)
            {
                visited[src]=1;//避免重复访问
                rec[src]=1;
                vector<int> &arr=matrix[src];
                for(int i=0;i<arr.size();i++)
                {
                    if(rec[i]==1&&arr[i]!=0)
                        return 1;
                    else if(arr[i]!=0&&visited[i]==0&&isDirectedCycleUntil(i,visited,rec))
                        return 1;
                }
            }
            rec[src]=0;
            return 0;
        }
        bool isUndirectedCycleUntil(int src,vector<bool>&visited,int parent)
        {
            visited[src]=1;
            vector<int>&arr=matrix[src];
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=0)
                {
                    if(visited[i]==1&&i!=parent)
                        return 1;
                    else if(visited[i]==0&&isUndirectedCycleUntil(i,visited,src))
                        return 1;
                }
            }
            return 0;
        }
        void TopologicalSortingUntil(int src,vector<bool>&visited,stack<int>&st)
        {
            visited[src]=1;
            vector<int> &arr=matrix[src];
            for(int i=0;i<arr.size();i++)
            {
                if(visited[i]==0)
                {
                    TopologicalSortingUntil(i,visited,st);
                }
            }
            st.push(src);
        }
        void AllTopologicalSortingUntil(vector<bool>&visited,vector<int>&tmp,vector<vector<int>>&res)
        {
            for(int i=0;i<visited.size();i++)
            {
                if(visited[i]==0&&indegree[i]==0)
                {
                    visited[i]=1;
                    tmp.push_back(i);
                    vector<int>&arr=matrix[i];
                    for(int j=0;j<arr.size();j++)
                    {
                        if(visited[j]==0&&arr[j]!=0)
                        {
                            indegree[j]--;
                        }
                    }
                    AllTopologicalSortingUntil(visited,tmp,res);
                    visited[i]=0;
                    tmp.pop_back();
                    for(int j=0;j<arr.size();j++)
                    {
                        if(visited[j]==0&&arr[j]!=0)
                        {
                            indegree[j]++;
                        }
                    }
                }
            }
            if(tmp.size()==visited.size())
            {
                res.push_back(tmp);
                for(int i=0;i<tmp.size();i++)
                    cout<<tmp[i]<<" ";
                cout<<endl;
            }
        }

    public:
        Graph(int n)
        {
            matrix.resize(n,vector<int>(n,0));
            indegree.resize(n,0);
        }
        Graph(vector<vector<int>>&Mat)
        {
            if(Mat.size()==0)
            {
                cout<<"Graph Input Mat ERROR!"<<endl;
                return ;
            }
            if(Mat[0].size()!=Mat.size())
            {
                cout<<"Graph Input Mat ERROR!"<<endl;
                return ;
            }
            matrix=Mat;
            indegree.resize(matrix.size(),0);
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix.size();j++)
                {
                    if(matrix[i][j]!=0)
                        indegree[j]++;
                }
            }
        }
        bool AddDirectedEdge(int src,int des,int val=1)
        {
            if(matrix[src][des]==0&&val!=0) indegree[des]++;
            if(matrix[src][des]!=0&&val==0) indegree[des]--;
            matrix[src][des]=val;
            return 1;
        }
        bool AddEdge(int src,int des,int val=1)
        {
            if(src<0||src>=matrix.size()) return 0;
            if(des<0||des>=matrix.size()) return 0;
            AddDirectedEdge(src,des,val);
            AddDirectedEdge(des,src,val);
            return 1;
        }
        void PrintGraph()
        {
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix.size();j++)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        vector<int> BFS(int src=0)
        {
            vector<int> bfs;
            queue<int> que;
            vector<bool> visited(matrix.size(),0);
            que.push(src);
            visited[src]=1;
            while(!que.empty())
            {
                int fnt=que.front();
                que.pop();
                bfs.push_back(fnt);

                vector<int>&arr=matrix[fnt];
                for(int i=0;i<arr.size();i++)
                {
                    if(visited[i]==0&&arr[i]!=0)
                    {
                        que.push(i);
                        visited[i]=1;
                    }
                }
            }
            if(1)
            {
                for(int i=0;i<bfs.size();i++)
                    cout<<bfs[i]<<" ";
                cout<<endl;
            }
            return bfs;
        }
        vector<int> DFS()
        {
            vector<int> res;
            vector<bool> visited(matrix.size(),0);
            for(int i=0;i<matrix.size();i++)
                if(visited[i]==0)
                    DFSUntil(i,visited,res);
            cout<<endl;
            return res;
        }
        vector<int> DFS(int src)
        {
            vector<int> res;
            vector<bool> visited(matrix.size(),0);
            DFSUntil(src,visited,res);
            cout<<endl;
            return res;
        }
        bool isDirectedCycle()//test OK
        {
            vector<bool> visited(matrix.size(),0);
            vector<bool> rec(matrix.size(),0);
            for(int i=0;i<matrix.size();i++)
                if(isDirectedCycleUntil(i,visited,rec))
                    return 1;
            return 0;
        }
        bool isUndirectedCycle()//测试ok
        {
            vector<bool>visited(matrix.size(),0);
            for(int i=0;i<visited.size();i++)
            {
                if(visited[i]==0)
                    if(isUndirectedCycleUntil(i,visited,-1))
                        return 1;
            }
            return 0;
        }
        vector<int> TopologicalSorting()
        {
            stack<int> st;
            vector<bool> visited(matrix.size(),0);
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
            for(auto r:res)
                cout<<r<<" ";
            cout<<endl;
            return res;
        }
        vector<vector<int>> AllTopologicalSorting()
        {
            vector<vector<int>> res;
            vector<int> tmp;
            vector<bool> visited(matrix.size(),0);

            AllTopologicalSortingUntil(visited,tmp,res);

            return res;
        }
        void PrimMST()
        {
            vector<int> parent(matrix.size(),-1);
            vector<int> key(matrix.size(),INT_MAX);
            vector<bool> mstSet(matrix.size(),0);

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
                            pos=i;//选出key最小的那一个 pos
                    }
                }

                if(pos==-1)
                    break;

                mstSet[pos]=1;
                vector<int>&arr=matrix[pos];
                for(int i=0;i<arr.size();i++)
                {
                    if(arr[i]!=0&&mstSet[i]==0&&key[i]>arr[i])//更行pos的所有adjacent vertex
                    {
                        key[i]=arr[i];
                        parent[i]=pos;
                    }
                }

            }
            for(int i=0;i<parent.size();i++)
            {
                if(parent[i]==-1)
                {
                    cout<<parent[i]<<"->"<<i<<":"<<INT_MAX<<endl;
                }else
                {
                    cout<<parent[i]<<"->"<<i<<":"<<matrix[parent[i]][i]<<endl;
                }
            }
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
    //Graph gh(5);
    //gh.AddDirectedEdge(0,4);
    //gh.AddDirectedEdge(0,1);
    //gh.AddDirectedEdge(4,2);
    //gh.AddDirectedEdge(4,3);
    //gh.AddDirectedEdge(2,1);

    //gh.AddEdge(0,1);
    //gh.AddEdge(0,4);
    //gh.AddEdge(1,2);
    //gh.AddEdge(1,3);
    //gh.AddEdge(2,4);

    gh.PrintGraph();
    cout<<endl;

    //cout<<gh.isDirectedCycle()<<endl;
    //cout<<gh.isUndirectedCycle()<<endl;
    //gh.TopologicalSorting();
    //gh.AllTopologicalSorting();

    gh.PrimMST();

    //gh.DFS();
    //gh.DFS(0);
    //gh.DFS(1);
    //gh.DFS(2);
    //gh.DFS(4);
    //gh.BFS(0);
    //gh.BFS(4);
    //gh.BFS(2);
    //gh.BFS(3);
    //gh.PrimMST();
    return 0;
}
