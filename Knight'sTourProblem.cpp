#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;
//the Knight's tour problem
//ok

class KnightTourProblem{
    private:
        vector<vector<int>> moves= {
            {+1,+2},{+2,+1},
            {+1,-2},{-2,+1},
            {-1,+2},{+2,-1},
            {-1,-2},{-2,-1},
        };
        int Up;
        int Cnt=0;

        vector<vector<int>> matrix;

        void AllSolutionsHelper(int x,int y,int stps)
        {
            //cout<<stps<<endl;
            matrix[x][y]=stps;
            if(stps==Up-1)
            {
                //count the solutions to solve
                Cnt++;
                //output
                for(int i=0;i<matrix.size();i++)
                {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        cout<<matrix[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
                matrix[x][y]=-1;
                return ;
            }
            // 8 moves BackTracking
            for(int i=0;i<8;i++)
            {
                int mx=moves[i][0];
                int my=moves[i][1];
                int dx=mx+x;
                int dy=my+y;
                if(CanGoTo(dx,dy))
                    AllSolutionsHelper(dx,dy,stps+1);
            }

            //BackTracking chu li
            matrix[x][y]=-1;
        }
        bool OneSolutionsHelper(int x,int y,int stps)
        {
            //cout<<stps<<endl;
            matrix[x][y]=stps;
            if(stps==Up-1)
            {
                //count the solutions to solve
                Cnt++;
                //output
                for(int i=0;i<matrix.size();i++)
                {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        cout<<matrix[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
                matrix[x][y]=-1;
                return 1;
            }
            // 8 moves BackTracking
            for(int i=0;i<8;i++)
            {
                int mx=moves[i][0];
                int my=moves[i][1];
                int dx=mx+x;
                int dy=my+y;
                if(CanGoTo(dx,dy))
                    if( OneSolutionsHelper(dx,dy,stps+1))
                        return 1;
            }

            //BackTracking chu li
            matrix[x][y]=-1;
            return 0;
        }

    public:
        KnightTourProblem(int r=8)
        {
            matrix.resize(r,vector<int>(r,-1));
            Up=r*r;
        }
        KnightTourProblem(int r,int c=8)
        {
            matrix.resize(r,vector<int>(c,-1));
            Up=r*c;
        }
        void AllSolutions()
        {
            int stps=0;
            for(int x=0;x<matrix.size();x++)
            {
                for(int y=0;y<matrix[0].size();y++)
                {
                    AllSolutionsHelper(x,y,stps);
                }
            }
            cout<<Cnt<<" solutions\n";

        }
        bool OneSolution()
        {
            int stps=0;
            for(int x=0;x<matrix.size();x++)
            {
                for(int y=0;y<matrix[0].size();y++)
                {
                    if( OneSolutionsHelper(x,y,stps) )
                        return 0;
                }
            }
            cout<<"No Solution found"<<endl;
            return 0;
        }
        bool CanGoTo(int x,int y)
        {
            if(x<0||y<0) return 0;
            if(x>=matrix.size()) return 0;
            if(y>=matrix[0].size()) return 0;
            if(matrix[x][y]!=-1) return 0;
            return 1;
        }
};
int main()
{
    //KnightTourProblem ktp(5,5);//1728 种可能，从任一一个地方出发Lw'
    //KnightTourProblem ktp(3,4);
    //KnightTourProblem ktp(8,8);//计算机仍未知，时间复杂度过大
    KnightTourProblem ktp(7,7);//165575218320 算了吧
    //ktp.AllSolutions();
    ktp.OneSolution();
    return 0;
}
