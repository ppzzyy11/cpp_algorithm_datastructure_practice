#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;
class mColoringProblem
{
    private:
        vector<vector<int>> matrix;
        int V;
        vector<int> color;
        int M;
        bool AllSolutionsHelper(int v)
        {
            if(v==V)
            {
                //output
                cout<<v<<endl;
                for(int i=0;i<matrix.size();i++)
                {
                    cout<<i<<":";
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        cout<<color[j]<<'\t';
                    }
                    cout<<endl;
                }
                cout<<endl;
                return 1;
            }
            for(int i=0;i<M;i++)
            {
                if(CanColor(v,i))//you dian sha bi, zeng jia le TC
                {
                    color[v]=i;
                    AllSolutionsHelper(v+1);
                    color[v]=-1;
                }
            }
            return 0;
        }

    public:
        mColoringProblem(vector<vector<int>>& mat,int m)
        {
            matrix=mat;
            V=mat.size();
            color.resize(V,-1);
            M=m;
        }
        bool CanColor(int v,int clr)
        {
            vector<int>&arr=matrix[v];
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=0&&color[i]==clr)
                {
                    return 0;
                }
            }
            return 1;
        }
        void AllSolutions()
        {
            AllSolutionsHelper(0);
        }

};
int main()
{
    vector<vector<int>> gph=
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    mColoringProblem mcp(gph,3);
    mcp.AllSolutions();
    return 0;
}
