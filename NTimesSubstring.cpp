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

bool NTimesSubstring(const string&str)
{
    int s=-1,e=1;
    int i=0;
    while(e<str.size())
    {
        if(str[e]==str[i])
        {
            if(s==-1)
            {
                s=e;
            }
            e++;
            i++;
        }else
        {
            s=-1;
            i=0;
            e++;
        }
        //cout<<i<<" "<<s<<" "<<e<<endl;
    }
    return i>=s&&s!=-1;
}

int main()
{
    const vector<string> strs={"ABCABC", "ABABAB", "ABCDABCD", "GEEKSFORGEEKS", "GEEKGEEK", "AAAACAAAAC", "ABCDABC"};
    for(auto str:strs)
    {
        cout<<NTimesSubstring(str)<<endl;
    }
    return 0;
}
