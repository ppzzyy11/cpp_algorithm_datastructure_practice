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


string FindLongestStringWithKUniqueCharacters(const string&str,int k)
{
    if(str.size()==0) return "";
    {
        unordered_set<char> rec;
        int cnt=0;
        for(auto s:str)
        {
            if(rec.count(s)==0)
            {
                rec.insert(s);
            }
        }
        if(rec.size()<k) return "";
    }
    int I=0,J=0;
    int cnt=1;
    unordered_map<char,int> rec;
    rec[str[0]]=1;
    int i=0,j=1;

    while(j<str.size())
    {
        const char c=str[j];
        if(rec[c]==0)
        {
            cnt++;
            rec[c]++;
        }else
        {
            rec[c]++;
        }

        if(cnt==k)
        {
            if(j-i>J-I)
            {
                I=i;
                J=j;
            }
        }else if(cnt>k)
        {
            const char h=str[i];
            while(i<=j&&cnt>k)
            {
                if(rec[h]==1)
                {
                    cnt--;
                    rec[h]--;
                }else
                {
                    rec[h]--;
                }
                i++;
            }
        }
        j++;
    }
    return str.substr(I,J-I+1);
}

int main()
{
    cout<<FindLongestStringWithKUniqueCharacters("aabbccc",4)<<endl;
    return 0;
}
