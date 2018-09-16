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

void AnagramAlgorithm(const string&txt,const string&pat)
{
    vector<int> cnt(256,0);
    for(int i=0;i<pat.size();i++)
    {
        cnt[pat[i]]++;
    }
    vector<int>rec(256,0);
    for(int i=0;i<pat.size();i++)
    {
        rec[txt[i]]++;
    }
    if(rec==cnt)
    {
        cout<<"Found at index:"<<0<<endl;
    }
    for(int i=pat.size();i<txt.size();i++)
    {
        rec[txt[i-pat.size()]]--;
        rec[txt[i]]++;
        if(rec==cnt)
            cout<<"Found at index:"<<i-pat.size()+1<<endl;
    }
}

int main()
{
    AnagramAlgorithm("BACDGABCDA","ABCD");
    return 0;
}
