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

int LongestValidSubstring(const string&str)
{
    stack<int> idx;
    idx.push(-1);
    int len=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            idx.push(i);
        }else
        {
            idx.pop();
            if(idx.size()==0)
            {
                idx.push(i);
            }else
            {
                len=max(len,i-idx.top());
            }
        }
    }
    return len;
}

int main()
{
    const vector<string> strs={ "()()))", "()(()))))", "((()" };
    for(auto str:strs)
    {
        cout<<"res:"<<LongestValidSubstring(str)<<endl;
    }
    return 0;
}
