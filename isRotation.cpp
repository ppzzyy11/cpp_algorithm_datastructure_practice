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

//check if string are rotations of each other
//str1 ,str2
//If str1+str1 has a substring str2.use string.find !=
//
//std::string str ("There are two needles in this haystack with needles.");
//std::string str2 ("needle");
//std::size_t found = str.find(str2);
//found=str.find("needles are small",found+1,6);
//found=str.find("haystack");
//found=str.find('.');
//if (found!=std::string::npos)
//std::cout << "Period found at: " << found << '\n';


bool IsRotation(const string &str1,const string &str2)
{
    if(str1.size()!=str2.size()) return 0;
    string tmp=str1+str1;
    return tmp.find(str2)!=string::npos;
}

int main()
{
    string str1="cedfac";
    string str2="abcdef";

    cout<<IsRotation(str1,str2)<<endl;

    return 0;
}
