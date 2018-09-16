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

void Helper(string&tmp,vector<string>&res,int i,const string&str)
{
    if(i==str.size())
    {
        res.push_back(tmp);
        return ;
    }

    for(int j=i;j<str.size();j++)
    {
        tmp=tmp+"("+str.substr(i,j-i+1)+")";
        Helper(tmp,res,j+1,str);
        while(tmp.size()&&tmp[tmp.size()-1]!='(')
            tmp.pop_back();
        tmp.pop_back();
    }
}
void AllWaysToBreakAStringWithBrackets(const string&str)
{
    string tmp;
    vector<string> res;
    Helper(tmp,res,0,str);
    for(auto r:res)
    {
        cout<<r<<endl;
    }
}

int main()
{
    AllWaysToBreakAStringWithBrackets("abcde");
    return 0;
}
