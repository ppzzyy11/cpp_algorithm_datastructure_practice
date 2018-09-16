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


void KMPAlgorithm(const string& txt,const string& pat)
{
    vector<int> lps(pat.size(),0);
    int i=1,j=0;

    while(i<pat.size())//compute lps for pat
    {
        if(pat[i]==pat[j])
        {
            j++;//j forward
            lps[i]=j;
            i++;
        }else if(j!=0)//j decrease
        {
            j=lps[j-1];
        }else
        {
            i++;
        }
    }

    for(auto l:lps)
    {
        cout<<l<<" ";
    }
    cout<<endl;

    i=j=0;

    while(i<txt.size())
    {
        if(pat[j]==txt[i])
        {
            i++;//j forward
            j++;
        }

        if(j==pat.size())
        {
            cout<<"Found at index :"<<i-j<<endl;//found
            j=lps[j-1];
        }else if(i<txt.size()&&pat[j]!=txt[i])
        {
            if(j==0)// j decrease
            {
                i++;
            }else
            {
                j=lps[j-1];
            }
        }
    }
}
int main()
{
    string pat="aabaa";
    string txt="aabaacaabaa";
    KMPAlgorithm(txt,pat);
    return 0;
}
