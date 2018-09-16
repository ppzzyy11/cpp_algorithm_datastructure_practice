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

int NumberOfSubsequencesDivisibleByN(const string&str,const int n)//记录所有的玉树，对一个新的str[i]分为2种情况，1.不使用该str[i],原数照搬;2.使用该数,那么分为a.之前为空.b.之前不为空,之前余数*10+此数 对n取余得结果
    //同时注意是:vector.resize(n,0);并不可以将所有元素置0!!!!
{
    if(n<=0) return -1;
    vector<int> remainder(n,0);
    vector<int> tmp(n,0);
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            tmp[j]=0;
        }
        const int num=str[i]-'0';
        for(int i=0;i<n;i++)
        {
            int idx=(i*10+num)%n;
            tmp[idx]+=remainder[i];
        }
        for(int i=0;i<n;i++)
        {
            remainder[i]+=tmp[i];
        }
        remainder[num%n]++;
    }
    return remainder[0];
}

int main()
{
    const vector<string> strs=
    {
        "1234",
        "330",
        "676"
    };
    const vector<int> divisors=
    {
        4,6,6
    };
    for(int i=0;i<strs.size();i++)
    {
        cout<<NumberOfSubsequencesDivisibleByN(strs[i],divisors[i])<<endl;
    }
    return 0;
}
