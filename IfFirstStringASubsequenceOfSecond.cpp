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

bool IfFirstStringASubsequenceOfSecond(const string& str1,const string& str2)
{
	int i=0;
	int j=0;
	while(j<str2.size())
	{
		if(str2[j]==str1[i])
		{
			i++;
		}
		j++;
		if(i==str1.size()) return 1;
		if(i+str1.size()>str2.size()) return 0;
	}
	return 0;
}

int main()
{
	string str1="GTAB";
	//string str1="GGTAB";
	string str2="GXTXAYB";
	cout<<IfFirstStringASubsequenceOfSecond(str1,str2)<<endl;
	return 0;
}
