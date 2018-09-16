#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;


// Z array value : the longest substring starting from str[i] which is also a prefix of str[0..n-1]
// when Z value is equal to the pattern's length we find a pattern here
// P$T
void BuildZTwoLoops(const string &tp,vector<int>&Z)
{
    int pos=0;
    while(tp[pos]!='$') pos++;
    pos++;

    for(;pos<tp.size();pos++)
    {
        int i=pos;
        while(i<tp.size()&&tp[i]==tp[i-pos])
            i++;
        Z[pos]=i-pos;
    }
}
void BuildZ(const string &tp,vector<int>&Z)
{
    ;
}
void ZAlgorithm(const string &txt,const string &pat)
{
        string tp=pat+"$"+txt;
        vector<int> Z(tp.size(),0);
        BuildZTwoLoops(tp,Z);
        for(int i=0;i<Z.size();i++)
        {
            //cout<<Z[i]<<endl;
            if(Z[i]==pat.size())
            {
                cout<<"Found index at "<<i-pat.size()-1<<endl;
            }
        }

}


int main()
{
    string txt="aabaacaabaa";
    string pat="aa";
    ZAlgorithm(txt,pat);
    return 0;
}
