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


int NumberOfCustomersNotGetAPC(const int& n,const string&str)
{
    unordered_set<char> rec;
    int res=0;
    for(auto s:str )
    {
        if(rec.count(s)==0)
        {
            if(rec.size()>=n)
            {
                res++;
            }
            rec.insert(s);
        }else
        {
            rec.erase(s);
        }
    }
    return res;
}

int main()
{
    cout << NumberOfCustomersNotGetAPC(2, "ABBAJJKZKZ") << endl;
    cout << NumberOfCustomersNotGetAPC(3, "GACCBDDBAGEE") << endl;
    cout << NumberOfCustomersNotGetAPC(3, "GACCBGDDBAEE") << endl;
    cout << NumberOfCustomersNotGetAPC(1, "ABCBCA") << endl;
    cout << NumberOfCustomersNotGetAPC(1, "ABCBCADEED") << endl;
    return 0;
}
