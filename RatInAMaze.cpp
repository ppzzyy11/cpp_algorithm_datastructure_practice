#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;

class RatInAMaze
{
    private:
        vector<vector<int>> matrix;
        const vector<vector<int>> moves=
        {
            {+0,+1},
            {+0,-1},
            {+1,+0},
            {-1,+0}
        };
        bool OneSolutionHelper(int x,int y,int dx,int dy,int stps)
        {
            matrix[x][y]=stps;
            if(x==dx&&y==dy)
            {
                for(int i=0;i<matrix.size();i++)
                {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        cout<<matrix[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                matrix[x][y]=0;
                return 1;
            }
            for(int i=0;i<4;i++)
            {
                int mx=moves[i][0];
                int my=moves[i][1];
                if(CanGoto(x+mx,y+my))
                {
                    if(OneSolutionHelper(x+mx,y+my,dx,dy,stps-1))
                    {
                        matrix[x][y]=0;
                        return 1;
                    }
                }
            }
            matrix[x][y]=0;
            return 0;
        }
        bool AllSolutionsHelper(int x,int y,int dx,int dy,int stps)
        {
            matrix[x][y]=stps;
            if(x==dx&&y==dy)
            {
                for(int i=0;i<matrix.size();i++)
                {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        cout<<matrix[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                matrix[x][y]=0;
                cout<<endl;
                return 1;
            }
            for(int i=0;i<4;i++)
            {
                int mx=moves[i][0];
                int my=moves[i][1];
                if(CanGoto(x+mx,y+my))
                {
                    AllSolutionsHelper(x+mx,y+my,dx,dy,stps-1);
                }
            }
            matrix[x][y]=0;
            return 0;
        }
    public:
        RatInAMaze(vector<vector<int>>&Mat)//0 road, 1 obstacle, 2 zou guo de lu
        {
            matrix=Mat;
        }
        bool CanGoto(int x,int y)
        {
            if(x<0||y<0) return 0;
            if(x>=matrix.size()||y>=matrix[0].size()) return 0;
            return matrix[x][y]==0;
        }
        void OneSolution()
        {
            int x=0,y=0;
            int dx=matrix.size()-1;
            int dy=matrix[0].size()-1;
            int stps=-1;
            OneSolutionHelper(x,y,dx,dy,stps);
        }
        void AllSolutions()
        {
            int x=0,y=0;
            int dx=matrix.size()-1;
            int dy=matrix[0].size()-1;
            int stps=-1;
            AllSolutionsHelper(x,y,dx,dy,stps);
        }

};
int main()
{
    vector<vector<int>> mat=
    {
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };
    RatInAMaze rim(mat);
    //rim.OneSolution();
    rim.AllSolutions();
    return 0;
}
