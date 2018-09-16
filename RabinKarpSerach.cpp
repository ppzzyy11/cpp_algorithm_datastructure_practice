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




void RabinKarpSearch(const string &txt,const string &pat)
{
    int i=0,j=0;
    int hash_txt=0;
    int hash_pat=0;
    int k=131;
    for(int i=0;i<pat.size();i++)
    {
        hash_txt+=txt[i];
        hash_pat+=pat[i];
        hash_txt%=k;
        hash_pat%=k;
    }
    for(i=0;i<=txt.size()-pat.size();i++)
    {
        if(i==0)
        {
            ;
        }else
        {
            hash_txt=hash_txt-txt[i-1]+txt[i+pat.size()-1];
            hash_txt%=k;
        }
        if(hash_txt==hash_pat)
        {
            bool same=1;
            for(int j=0;j<pat.size();j++)
            {
                if(pat[j]!=txt[i+j])
                {
                    same=0;
                    break;
                }
            }
            if(same==1)
            {
                cout<<"Found at index "<<i<<endl;
            }
        }
    }
}
int main()
{
    string txt="aabaacaabaa";
    string pat="aa";
    RabinKarpSearch(txt,pat);
    return 0;
}
