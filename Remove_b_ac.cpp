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

string Remove_b_ac(const string & str)
{
    int i=0;
    string res;
    while(i<str.size())
    {
        if(str[i]=='b')
        {
            i++;
        }else if(i<str.size()-1&&str[i]=='a'&&str[i+1]=='c')
        {
            i=i+2;
        }else
        {
            res+=str[i];
            i++;
        }
    }
    return res;
}

int main()
{
    string str="acdbd";
    cout<<Remove_b_ac(str);
    return 0;
}
