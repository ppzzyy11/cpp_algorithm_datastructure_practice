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

template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

}

namespace std
{
    template<typename s, typename t> struct hash<pair<s, t>>
    {
        inline size_t operator()(const pair<s, t> & v) const
        {
            size_t seed = 0;
            ::hash_combine(seed, v.first);
            ::hash_combine(seed, v.second);
            return seed;

        }

    };

}
bool IsCircular(const string &path)
{
    int x=0;
    int y=0;
    pair<int,int> foo;
    //unordered_set<int> recX;
    //unordered_set<int,int> recY;
    //unordered_set<pair<int,int>>rec;//
    unordered_map<int,unordered_set<int>> rec;
    rec[x].insert(y);
    enum Direction{East,South,West,North};//东南西北
    Direction drt;
    drt=East;
    cout<<x<<":"<<y<<endl;
    for(auto p:path)
    {
        int d=(int)drt;
        //cout<<p<<endl;
        if(p=='G')
        {
            switch(drt)
            {
                case East:
                    x++;
                    break;

                case South:
                    y--;
                    break;

                case West:
                    x--;
                    break;

                case North:
                    y++;
                    break;

            };
            cout<<x<<":"<<y<<endl;
            //if(rec.count(make_pair(x,y))!=0)
            if(rec.count(x)!=0&&rec[x].count(y)!=0)
            {
                return 1;
            }else
            {
                rec[x].insert(y);
            }
        }else if(p=='L')
        {
            switch(drt)
            {
                case East:
                    drt=North;
                    break;

                case South:
                    drt=East;
                    break;

                case West:
                    drt=South;
                    break;

                case North:
                    drt=West;
                    break;
            }
        }else if(p=='R')
        {
            switch(drt)
            {
                case East:
                    drt=South;
                    break;

                case South:
                    drt=West;
                    break;

                case West:
                    drt=North;
                    break;

                case North:
                    drt=East;
                    break;
            }
        }
    }
    return 0;
}

int main()
{
    string path="GLGLGLGLG";
    cout<<IsCircular(path)<<endl;
    return 0;
}
