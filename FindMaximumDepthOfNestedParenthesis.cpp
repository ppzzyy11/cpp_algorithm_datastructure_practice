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

int FindMaximumDepthOfNestedParenthesis(const string&str)
{
    int left=0;
    int res=0;
    int cur=0;
    for(auto s:str)
    {
        if(s=='(')
        {
            left++;
            res=max(res,left);
        }else if(s==')')
        {
            if(left==0)
                return -1;
            else
            {
                left--;
            }
        }
    }
    return left==0?res:-1;
}

int main()
{
    cout<<FindMaximumDepthOfNestedParenthesis("( ((X)) (((Y)))  )")<<endl;
    return 0;
}
