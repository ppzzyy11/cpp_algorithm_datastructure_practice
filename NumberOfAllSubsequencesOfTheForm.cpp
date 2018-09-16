#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>//make_heap
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int NumberOfSubsequencesOfForm(const string&str)//Form a^ib^jc^k i,j,k>=1
{
    int A=0,B=0,C=0;

    for(auto s:str)
    {
        switch(s)
        {
            case 'a':
                A=A*2+1;
                break;

            case 'b':
                B=B*2+A;
                break;

            case 'c':
                C=2*C+B;
                break;

            default:
                break;
        }
    }
    return C;
}

int main()
{
    string str="abcabc";
    cout<<NumberOfSubsequencesOfForm(str)<<endl;
    return 0;
}
