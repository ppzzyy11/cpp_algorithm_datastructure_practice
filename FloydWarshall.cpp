#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<stack>
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
    }
};




int main()
{
    Graph gh(4);
    gh.AddDirectedEdge(0,1,5);
    gh.AddDirectedEdge(0,3,10);
    gh.AddDirectedEdge(1,2,3);
    gh.AddDirectedEdge(2,3,1);
    gh.PrintGraph();
    gh.FloydWarshall();
    cout<<endl;
    gh.PrintGraph();
    return 0;
}
