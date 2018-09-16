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

inline bool isUpper(const char & ch)
{
    return ch>='A'&&ch<='Z';
}
inline bool isLower(const char & ch)
{
    return ch>='a'&&ch<='z';
}
bool ValidSentence(const string&str)
{
    if(str.size()<=1) return 0;
    if(isUpper(str[0])==0)
        return 0;
    else if(str[str.size()-1]!='.')
        return 0;

    int state=0;//0 Upper. 1 Lower, 2 Space
    for(int i=1;i<str.size()-1;i++)
    {
        const char ch=str[i];
        switch(state)
        {
            case 0:
                if(isUpper(ch))
                    return 0;
                else if(isLower(ch))
                    state=1;
                else if(ch==' ')
                    state=2;
                break;

            case 1:
                if(isUpper(ch))
                    return 0;
                else if(isLower(ch))
                    state=1;
                else if(ch==' ')
                    state=2;
                break;

            case 2:
                if(isUpper(ch))
                    state=0;
                else if(isLower(ch))
                    state=1;
                else if(ch==' ')
                    return 0;
        }
    }
    return 1;
}

int main()
{
    const vector<string> strs={ "I love cinema.", "The vertex is S.", "I am single.", "My name is KG.", "I lovE cinema.", "GeeksQuiz. is a quiz site.", "I love Geeksquiz and Geeksforgeeks.", "  You are my friend.", "I love cinema" };
    for(int i=0;i<strs.size();i++)
    {
        cout<<ValidSentence(strs[i])<<endl;
    }
    return 0;
}
