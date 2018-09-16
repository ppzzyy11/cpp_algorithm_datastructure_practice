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

int CountDistinctSubsequences(const string& str)
{
	unordered_map<char,int> last;
	int res=1;
	for(auto s:str)
	{
		if(last.count(s)==0)
		{
			last[s]=res;
			res=2*res;
		}else
		{
			int tmp=res;
			res=2*res-last[s];
			last[s]=tmp;
		}
	}
	return res;
}

int main()
{
	const string str="gfg";
	cout<<CountDistinctSubsequences(str)<<endl;
    return 0;
}
