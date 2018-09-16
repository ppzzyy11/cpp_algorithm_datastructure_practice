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

const vector<string> hashtable=
{
    "",//0
    "",//1
    "abc",//2
    "def",//3
    "ghi",//4
    "jkl",//5
    "mno",//6
    "pqrs",//7
    "tuv",//8
    "wxyz"//9
};
void Helper(string& tmp,vector<string>& res,int i,const vector<int>& nums)
{
    if(tmp.size()==nums.size())
    {
        res.push_back(tmp);
        return ;
    }
    if(nums[i]==0||nums[i]==1)
    {
        Helper(tmp,res,i+1,nums);
        return ;
    }

    const string & str=hashtable[nums[i]];
    for(auto s:str)
    {
        tmp.push_back(s);
        Helper(tmp,res,i+1,nums);
        tmp.pop_back();
    }
}
void PrintAllPossibleWordsFromPhoneDigits(const vector<int>&nums)
{
    string tmp;
    vector<string> res;
    Helper(tmp,res,0,nums);
    for(int i=0;i<res.size();i++)
    {
        if(i%10==0)
        {
            cout<<endl;
        }
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> nums={2, 3, 4};
    PrintAllPossibleWordsFromPhoneDigits(nums);
    //adg adh adi aeg aeh aei afg afh afi bdg
    //bdh bdi beg beh bei bfg bfh bfi cdg cdh
    //cdi ceg ceh cei cfg cfh cfi
    return 0;
}
