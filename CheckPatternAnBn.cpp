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

bool Pattern(const string& str)
{
	if(str.size()==0) return 1;
	if(str.size()%2) return 0;
	if(str[0]==str.back()) return 0;
	int i=0,j=str.size()-1;
	while(i<j)
	{
		if(str[i]!=str[0]||str[j]!=str.back())
			return 0;
		i++;
		j--;
	}
	return 1;
}

int main()
{
	vector<string> strs=
	{
		"aabb",
		"abab",
		"aabbb"
	};
	for(auto str:strs)
	{
		cout<<Pattern(str)<<endl;
	}
	return 0;
}
