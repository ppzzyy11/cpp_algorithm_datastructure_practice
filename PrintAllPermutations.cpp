#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//print all permutations of a string
//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/


void PrintAllPermutations(int pos,string& str)//pos 之前的位置上的char都已经fixed了
{
    static int cnt=0;
    if(pos==str.size()-1)
    {
        cout<<cnt<<"\t:"<<str<<endl;
        cnt++;
        return ;
    }
    for(int i=pos;i<str.size();i++)
    {
        swap(str[pos],str[i]);
        PrintAllPermutations(pos+1,str);
        swap(str[pos],str[i]);
    }
}

int main()
{
    string str="abce";
    PrintAllPermutations(0,str);
    return 0;
}
