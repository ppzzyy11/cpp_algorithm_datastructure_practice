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

void TopologicalSorting(int src,vector<bool>&visited,vector<vector<bool>>&gh,stack<int>&st)
{
    visited[src]=1;
    vector<bool> & arr=gh[src];
    for(int i=0;i<arr.size();i++)
    {
        if(gh[src][i]==1&&visited[i]==0)
        {
            TopologicalSorting(i,visited,gh,st);
        }
    }
    st.push(src);
}

void FindOrderOfCharacters(const vector<string>& strings)
{
    unordered_map<char,int> rec;
    unordered_map<int,char> anti;

    int index=0;
    for(auto str:strings)
    {
        for(auto s:str)
        {
            if(rec.count(s)==0)
            {
                rec[s]=index;
                anti[index]=s;
                index++;
            }
        }
    }


    vector<vector<bool>> gh(index,vector<bool>(index,0));

    for(int i=0;i<strings.size();i++)
    {
        for(int j=i+1;j<strings.size();j++)
        {
            int pos=0;
            int len=min(strings[i].size(),strings[j].size());
            while(pos<len&&strings[i][pos]==strings[j][pos])
                pos++;
            gh[rec[strings[i][pos]]][rec[strings[j][pos]]]=1;
        }
    }

    vector<bool> visited(index,0);
    stack<int> st;
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            TopologicalSorting(i,visited,gh,st);
        }
    }

    while(!st.empty())
    {
        cout<<anti[st.top()]<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    vector<string> strings={"baa", "abcd", "abca", "cab", "cad"};//'b', 'd', 'a', 'c'
    FindOrderOfCharacters(strings);
    strings={"caa", "aaa", "aab"};//'c', 'a', 'b'
    FindOrderOfCharacters(strings);
    return 0;
}
