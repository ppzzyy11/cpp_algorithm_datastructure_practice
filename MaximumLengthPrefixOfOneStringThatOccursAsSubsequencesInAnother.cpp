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

int MaximumLengthPrefixOfOneStringThatOccursAsSubsequencesInAnother(const string&s,const string& t)
{
	int i=0,j=0;
	while(i<s.size()&&j<t.size())
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}else
		{
			j++;
		}
	}
	return i;
}

int main()
{
	const string s="geeksforgeeks";
	const string t="agbcedfeitk";
	cout<<MaximumLengthPrefixOfOneStringThatOccursAsSubsequencesInAnother(s,t)<<endl;
    return 0;
}
