#include<iostream>
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
//Recursively remove all adjacent duplicates
//two case: duplicates start from the beginning of the string;duplicastes start in of the string
//思路，来一个fake head就好

string RemoveAllDuplicatesHelper(int pos,string &str)
{
    if(pos==str.size()-1) return "";
    if(str[pos]==str[pos-1]||str[pos]==str[pos+1])
    {
        return RemoveAllDuplicatesHelper(pos+1,str);
    }
    return str[pos]+RemoveAllDuplicatesHelper(pos+1,str);
}
void RemoveAllDuplicates(string &str)
{
    if(str.size()<=1) return ;
    str=str[1]+str;
    char ch=str[str.size()-2];
    str=str+ch;
    cout<<str<<endl;
    str=RemoveAllDuplicatesHelper(1,str);

}
int main()
{
    string str="aaaabbb";
    cout<<str<<endl;
    RemoveAllDuplicates(str);
    cout<<str<<endl;
    return 0;
}
