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

int LexicographicRankOfAString(const string & str)
{
    vector<int> scm(str.size(),0);//smaller characters after this character. we asummed that there are no duplicates in the str. why? aa is 1st or 2rd
    for(int i=0;i<str.size();i++)
    {
        for(int j=i+1;j<str.size();j++)
        {
            if(str[i]>str[j])
               scm[i]++;
        }
        //cout<<scm[i]<<endl;
    }
    int res=1;// self
    int tmp=1;
    for(int i=0;i<scm.size()-1;i++)
    {
        tmp*=(i+1);
        res+=tmp*scm[scm.size()-2-i];
        //cout<<tmp<<":"<<scm[scm.size()-2-i]<<endl;
    }
    return res;
}
int main()
{
    string str="string";
    cout<<LexicographicRankOfAString(str)<<endl;//598
    return 0;
}
