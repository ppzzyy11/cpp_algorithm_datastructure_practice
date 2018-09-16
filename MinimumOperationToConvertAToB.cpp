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

int MinimumOperation(const string &A,const string&B)
{
    if(A.size()!=B.size()) return -1;
    vector<int> cnt(256,0);
    for(int i=0;i<A.size();i++)
    {
        cnt[A[i]]++;
        cnt[B[i]]--;
    }
    for(int i=0;i<cnt.size();i++)
    {
        if(cnt[i]!=0)
            return -1;
    }

    int i=A.size()-1;
    int j=B.size()-1;

    int res=0;
    while(i>=0)
    {
        while(i>=0&&A[i]!=B[j])
        {
            i--;
            res++;
        }
        if(i>=0&&A[i]==B[j])
        {
            i--;
            j--;
        }
    }
    return res;
}

int main()
{
    const string A = "EACBD";
    const string B = "EABCD";
    cout<<MinimumOperation(A,B)<<endl;
    return 0;
}
