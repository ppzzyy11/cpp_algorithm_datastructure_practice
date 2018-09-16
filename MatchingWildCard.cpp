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


bool Helper(const string& txt,int i,const string& pat,int j,vector<vector<int>>& mem)
{
    if(i<0||i>=txt.size()) return 0;
    if(j<0||j>=pat.size()) return 0;
    if(mem[i][j]!=-1) return mem[i][j];

    bool res;
    if(txt[i]==pat[j]||pat[j]=='?')
    {
        if(i==txt.size()-1&&j==pat.size()-1)
            return 1;
        res=Helper(txt,i+1,pat,j+1,mem);
    }else if(pat[j]=='*')
    {
        if(i==txt.size()-1&&j==pat.size()-1)
            return 1;
        res=Helper(txt,i+1,pat,j,mem)||Helper(txt,i,pat,j+1,mem);
    }else
    {
        res=0;
    }
    return mem[i][j]=res;
}
bool MatchingWildCardPattern(const string& txt, const string& pat)
{
    vector<vector<int>> mem(txt.size(),vector<int>(pat.size(),-1));
    return Helper(txt,0,pat,0,mem);
}
bool test(const string&pat,const string&txt)
{
    return MatchingWildCardPattern(txt,pat);
}

int main()
{
    cout<<endl<<test("g*ks", "geeks"); // Yes
    cout<<endl<<test("ge?ks*", "geeksforgeeks"); // Yes
    cout<<endl<<test("g*k", "gee");  // No because 'k' is not in second
    cout<<endl<<test("*pqrs", "pqrst"); // No because 't' is not in first
    cout<<endl<<test("abc*bcd", "abcdhghgbcd"); // Yes
    cout<<endl<<test("abc*c?d", "abcd"); // No because second must have 2 // instances of 'c'
    cout<<endl<<test("*c*d", "abcd"); // Yes
    cout<<endl<<test("*?c*d", "abcd"); // Yes
    return 0;
}
