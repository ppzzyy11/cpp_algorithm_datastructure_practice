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

void Helper(string & tmp,vector<string>&res, int i,const vector<vector<string>>&words)
{
    if(i==words.size())
    {
        tmp.pop_back();
        res.push_back(tmp);
        return ;
    }

    const vector<string>& strs=words[i];
    for(auto str:strs)
    {
        string backup=tmp;
        tmp+=str+" ";
        Helper(tmp,res,i+1,words);
        tmp=backup;
    }
}
void PrintAllSentencesThatCanBeFormedFromWords(const vector<vector<string>>& words)
{
    string tmp;
    vector<string> res;
    Helper(tmp,res,0,words);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;;
    }
}

int main()
{
    vector<vector<string>> words={
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}
    };
    PrintAllSentencesThatCanBeFormedFromWords(words);
    return 0;
}
