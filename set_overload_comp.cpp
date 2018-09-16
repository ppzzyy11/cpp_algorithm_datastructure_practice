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

//这是两种set自定义comp的方法,分别是自定义ckass comp的方法,这个方法只对 pair也就是tuble中元素陈宫
//而第二种 fncomp则可以对自定义的struct E进行操作并成功
struct classcomp{
    bool operator()(const pair<int,pair<int,string>>&l,const pair<int,pair<int,string>>&r)const
    {
        //return l.first<r.first;
        return l.first>r.first;
    }
};
ostream& operator<<(ostream& os,const set<pair<int,pair<int,string>>,classcomp>&rec)
{
    for(auto r:rec)
    {
        cout<<r.first<<','<<r.second.first<<':'<<r.second.second<<endl;
    }
    return os;
}
bool fncomp(const pair<int,pair<int,string>>&l,const pair<int,pair<int,string>>&r)
{
        return l.first<r.first;
        //return l.first>r.first;
}
ostream& operator<<(ostream& os,const set<pair<int,pair<int,string>>,bool(*)(const pair<int,pair<int,string>>&,const pair<int,pair<int,string>>&)>&rec)
{
    for(auto r:rec)
    {
        cout<<r.first<<','<<r.second.first<<':'<<r.second.second<<endl;
    }
    return os;
}
struct E
{
    int x;
    int y;
    E(int x,int y):x(x),y(y){}
};
//class Ecomp{
    bool Ecomp(const E& l,const E&r)
    {
        //return l.x>r.x;
        return l.x<r.x;
    }
//}
//struct classcomp{
    //bool operator()(const pair<int,pair<int,string>>&l,const pair<int,pair<int,string>>&r)const
    //{
        ////return l.first<r.first;
        //return l.first>r.first;
    //}
//};
int main()
{
    //set<pair<int,pair<int,string>>,classcomp> rec;
    bool(*fn_pt)(const pair<int,pair<int,string>>&,const pair<int,pair<int,string>>&)=fncomp;
    set<pair<int,pair<int,string>>,bool(*)(const pair<int,pair<int,string>>&,const pair<int,pair<int,string>>&)> rec(fn_pt);
    //set<pair<int,pair<int,string>>> rec;
    rec.insert(make_pair(0,make_pair(1,"asdf")));
    rec.insert(make_pair(1,make_pair(-1,"asdf")));
    cout<<rec<<endl;
    bool(*Ec_pt)(const E&,const E&)=Ecomp;
    set<E,bool(*)(const E&,const E&)> es(Ec_pt);
    E e(2,4);
    es.insert(e);
    E f(3,5);
    es.insert(f);
    for(auto e:es)
    {
        cout<<e.x<<','<<e.y<<endl;
    }
    return 0;
}
