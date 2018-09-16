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

int NumberOfTimesAStringOccursAsASubsequencesInGivenString(const string& txt,const string& pat)
{
	vector<int>times(pat.size(),0);
	for(auto t:txt)
	{
		for(int i=pat.size()-1;i>=0;i--)
		{
			if(pat[i]==t)
			{
				if(i!=0)
					times[i]+=times[i-1];
				else
					times[i]+=1;
			}
		}
	}
	return times.back();
}

int main()
{
	const string txt="GeeksforGeeks";
	const string pat="Gks";
	cout<<NumberOfTimesAStringOccursAsASubsequencesInGivenString(txt,pat)<<endl;
    return 0;
}
