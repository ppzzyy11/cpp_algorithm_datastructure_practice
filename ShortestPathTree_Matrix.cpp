#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<stack>
#include<set>
//Adjacency Matrix
//这里i i的值为0
//i j 无连则为INT_MAX
//这里用了FloydWarshall 算法,可以求出所有节点之间的最短路径,TC(n^3)
using namespace std;

class Graph
{
    private:
        vector<vector<int>> matrix;

    public:
    Graph(int n)
    {
        matrix.resize(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
            matrix[i][i]=0;
    }
    Graph(vector<vector<int>>& Mat)
    {
        if(Mat.size()==0) return ;
        if(Mat[0].size()!=Mat.size()) return ;
        matrix=Mat;
        if(1)
        for(int i=0;i<Mat.size();i++)
        {
            for(int j=0;j<Mat.size();j++)
            {
                if(i==j) {matrix[i][j]=0;}
                else if(matrix[i][j]==0)
                {
                    matrix[i][j]=INT_MAX;
                }
            }
        }
    }
    bool AddDirectedEdge(int s,int e,int val=1)
    {
        if(s<0||s>=matrix.size()) return 0;
        if(e<0||e>=matrix.size()) return 0;
        if(s==e) return 0;
        matrix[s][e]=val;
    }
    bool AddEdge(int s,int e,int val=1)
    {
        if(s<0||s>=matrix.size()) return 0;
        if(e<0||e>=matrix.size()) return 0;
        if(s==e) return 0;
        matrix[s][e]=val;
        matrix[e][s]=val;
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
    void BFS(const int s)
    {
        if(s<0||s>=matrix.size()) return ;
        queue<int> que;
        vector<int> visited(matrix.size(),0);
        que.push(s);
        while(!que.empty())
        {
            int tmp=que.front();
            visited[tmp]=1;
            cout<<tmp<<" ";
            que.pop();
            vector<int> &arr=matrix[tmp];
            for(int i=0;i<arr.size();i++)
            {
                if(visited[i]==0&&matrix[i][tmp]!=0)
                {
                    que.push(i);
                    visited[i]=1;
                }
            }
        }
        cout<<endl;
    }
    void DFS(const int s)
    {
        if(s<0||s>=matrix.size()) return ;
        stack<int> st;
        vector<int> visited(matrix.size(),0);
        st.push(s);
        while(!st.empty())
        {
            int tmp=st.top();
            if(visited[tmp]==0)
                cout<<tmp<<" ";
            visited[tmp]=1;
            st.pop();
            vector<int> &arr=matrix[s];
            for(int i=arr.size()-1;i>=0;i--)
            {
                if(visited[i]==0&&matrix[i][tmp])
                {
                    visited[i]=0;
                    st.push(i);
                    //cout<<"push";
                }
            }
        }
        cout<<endl;
    }
    vector<vector<int>> FloydWarshall()
    {
        vector<vector<int>> sol=matrix;
        for(int k=0;k<matrix.size();k++)
        {
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix.size();j++)
                {
                    if(sol[i][k]!=INT_MAX&&sol[k][j]!=INT_MAX&&sol[i][k]+sol[k][j]<sol[i][j])
                    {
                        sol[i][j]=sol[i][k]+sol[k][j];
                    }
                }
            }
        }
        return sol;
    }
    vector<int> Dijkstra(int src)//one test passed
    {
        vector<int> spt(matrix.size(),-1);
        vector<int> dist(matrix.size(),INT_MAX);
        dist[src]=0;
        while(1)
        {
            int pos=-1;
            for(int i=0;i<dist.size();i++)
            {
                if(dist[i]!=-1)
                {
                    if(pos==-1)
                        pos=i;
                    else
                    {
                        if(dist[i]<dist[pos])
                            pos=i;
                    }
                }
            }
            if(pos==-1) return spt;
            cout<<pos<<" "<<dist[pos]<<endl;
            spt[pos]=dist[pos];
            vector<int>& arr=matrix[pos];
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=0&&arr[i]!=INT_MAX&&dist[i]!=-1)
                {
                    dist[i]=min(dist[i],dist[pos]+arr[i]);
                }
            }
            dist[pos]=-1;
        }
    }
    vector<int> BellmanFord(int src)
    {
        vector<int> dist(matrix.size(),INT_MAX);
        dist[src]=0;
        for(int k=0;k<matrix.size();k++)
        {
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix.size();j++)
                {
                    if(dist[i]==INT_MAX||matrix[i][j]==0||matrix[i][j]==INT_MAX)
                        continue;
                    else if(dist[j]>dist[i]+matrix[i][j])
                    {
                        dist[j]=dist[i]+matrix[i][j];
                    }
                }
            }
        }
        return dist;
    }
};




int main()
{
    vector<vector<int>> mat={
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    Graph gh(mat);
    gh.PrintGraph();
    vector<int> spt=gh.Dijkstra(1);
    for(int i=0;i<spt.size();i++)
    {
        cout<<i<<"\t\t";
    }
    cout<<endl;
    for(int i=0;i<spt.size();i++)
    {
        cout<<spt[i]<<"\t\t";
    }
    cout<<endl;
    spt=gh.BellmanFord(1);
    for(int i=0;i<spt.size();i++)
    {
        cout<<i<<"\t\t";
    }
    cout<<endl;
    for(int i=0;i<spt.size();i++)
    {
        cout<<spt[i]<<"\t\t";
    }
    cout<<endl;
    cout<<endl;
    vector<vector<int>> sol=gh.FloydWarshall();
    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol.size();j++)
        {
            cout<<sol[i][j]<<"\t\t";
        }
        cout<<endl;
    }
    return 0;
}
