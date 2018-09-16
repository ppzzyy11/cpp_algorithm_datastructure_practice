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

string  Helper(int pos,string &str)
{
    if(pos==str.size()-1)
    {
        return "";
    }
    if(str[pos]==str[pos-1]||str[pos]==str[pos+1])
    {
        return ""+Helper(pos+1,str);
    }else
    {
        return str[pos]+Helper(pos+1,str);
    }

}
void RemoveDuplicatesRecursively(string &str)
{
    if(str.size()<=1) return ;
    str=str[1]+str;
    str=str+str[str.size()-2];
    str=Helper(1,str);
    cout<<str<<endl;

}

int main()
{
    string str="aaaabcbba";
    RemoveDuplicatesRecursively(str);
    return 0;
}
