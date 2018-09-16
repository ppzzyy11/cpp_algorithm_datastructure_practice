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

struct ele
{
    char ch;
    int fre;
    ele(char ch='\0',int fre=0):ch(ch),fre(fre){}
};

inline bool operator <(const ele& ele1,const ele& ele2)//shall ele1 be after ele2
{
    return ele1.fre<ele2.fre;
}

void Rearrange(string &str,int dstn)
{
    vector<ele> eles(26);

    for(int i=0;i<eles.size();i++)
    {
        eles[i].ch='a'+i;
        eles[i].fre=0;
    }

    for(auto s:str)
    {
        eles[s-'a'].fre++;
    }

    string tmp(str.size(),'\0');
    make_heap(eles.begin(),eles.end());
    while(eles.size()&&eles[0].fre!=0)
    {
        char ch=eles[0].ch;
        int fre=eles[0].fre;

        pop_heap(eles.begin(),eles.end());
        eles.pop_back();

        int pos=0;
        while(pos<tmp.size()&&tmp[pos]!='\0')
            pos++;

        while(fre!=0&&pos<tmp.size())
        {
            fre--;

            tmp[pos]=ch;
            pos+=dstn;
        }
    }

    cout<<tmp<<endl;


}

int main()
{
    string txt="aaasdfasdfasdfasdfafassdfjgjklsdsadofiueoriqupoire";
    cout<<txt<<endl;
    Rearrange(txt,3);
    return 0;
}
