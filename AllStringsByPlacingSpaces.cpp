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
    tmp+=str[i];
    Helper(tmp,res,i+1,str);
    if(i!=str.size()-1)
    {
        tmp+=" ";
        Helper(tmp,res,i+1,str);
        tmp.pop_back();
    }
    tmp.pop_back();
}

void PrintAllPossiableStringsByPlacingSpaces(const string &str)
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
    PrintAllPossiableStringsByPlacingSpaces("abcdefg");
    return 0;
}
