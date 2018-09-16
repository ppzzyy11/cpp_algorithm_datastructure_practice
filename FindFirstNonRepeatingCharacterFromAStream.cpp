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


void FindFirstNonRepeatingCharacterFromAStream(const string& str)
{
    vector<bool> rep(26,0);//repeated
    vector<bool> addr(26,0);//have a addreess(exsit) in dll
    list<char> dll;//double linked list

    for(auto s:str)
    {
        int idx=s-'a';
        if(rep[idx]==1)
        {
            ;
        }else if(addr[idx]==0)
        {
            addr[idx]=1;
            dll.push_back(s);
        }else
        {
            rep[idx]=1;
            dll.remove(s);
        }

        if(dll.size())
        {
            cout<<"First non-repeating character: "<<dll.front()<<endl;
        }else
        {
            cout<<"dll empty."<<endl;
        }
    }
}

int main()
{
    string str="abcdefghacdebaaaa";
    FindFirstNonRepeatingCharacterFromAStream(str);
    return 0;
}
