//http://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
 using namespace std;

 int GetCnt(const char&e,unordered_map<char,vector<char>>&mp,unordered_map<char,int>&cnt)
{
    if(cnt.count(e)!=0)
    {
        //cout<<e<<":"<<cnt[e]<<endl;
        return cnt[e]+1;
    }else
    {
        int res=0;
        for(int i=0;i<mp[e].size();i++)
        {
            if(e!=mp[e][i])
                res+=GetCnt(mp[e][i],mp,cnt);
        }
        //cout<<e<<":"<<res<<endl;
        cnt[e]=res;
        return res+1;
    }
}
 int main()
{
    vector<pair<char,char>> EM={
        {'A','C'},
        {'B','C'},
        {'C','F'},
        {'D','E'},
        {'E','F'},
        {'F','G'},
        {'G','G'},
        {'H','D'},
        {'I','B'},
        {'J','H'}
    };

    unordered_map<char,vector<char>> mp;//manager ,directly report employee
    unordered_map<char,int> cnt;//
    vector<pair<char,int>> res;
    res.resize(EM.size());
    for(int i=0;i<EM.size();i++)
    {
        mp[EM[i].second].push_back(EM[i].first);
    }

    for(int i=0;i<EM.size();i++)
    {
        char e=EM[i].first;

        if(cnt.count(e)==0)
        {
            GetCnt(e,mp,cnt);

        }
    }
    for(auto m:mp)
    {
        cout<<m.first<<":";
        for(int i=0;i<m.second.size();i++)
        {
            cout<<m.second[i]<<" ";
        }
        cout<<endl;
    }
    for(auto c:cnt)
    {
        cout<<c.first<<" "<<c.second<<endl;
    }

    return 0;
}
