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

string FindLongestSubstringWithKUniqueCharacters(const string &str,const int &k)
{
    if(k<=0)
        return "";
    string res;
    if(str.size()==0)
        return res;

    int I=0;
    int J=0;
    unordered_map<char,int> rec;
    rec[str[0]]=1;
    int cnt=1;//number of unique characters in the substring
    int i=0;
    int j=1;
    while(j<str.size())
    {
        if(rec[str[j]]==0)
        {
            cnt++;
        }
        rec[str[j]]++;
        while(cnt>k&&i<=j)
        {
            if(rec[str[i]]==1)
            {
                cnt--;
            }
            rec[str[i]]--;
            i++;
        }
        if(cnt==k)
        {
            if(J-I<j-i)
            {
                I=i;
                J=j;
            }
        }
        j++;
    }
    if(I==J&&k!=1)
    {
        return "";
    }
    return str.substr(I,J-I+1);
}

int main()
{
    string str="aabbccbbbc";
    cout<<FindLongestSubstringWithKUniqueCharacters(str,2)<<endl;//bbccbbbc
    return 0;
}
