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

ostream& operator<<(ostream& os,const set<string>& strs)
{
	for(auto it=strs.begin();it!=strs.end();it++)
	{
		cout<<*it<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}

int CountWordsThatAppearExactlyTwoTimesInAnArrayOfWords(const vector<string>& words)
{
	int res=0;
	unordered_map<string,int> rec;
	for(auto word:words)
	{
		rec[word]++;
		if(rec[word]==2)
		{
			res++;
		}else if(rec[word]==3)
		{
			res--;
		}
	}
	return res;
}

int main()
{
	vector<string> words=
	{"Om", "Om", "Shankar", "Tripathi",
	                "Tom", "Jerry", "Jerry"};
	//{"hate", "love", "peace", "love",
				   //"peace", "hate", "love", "peace",
				   //"love", "peace"};
	cout<<CountWordsThatAppearExactlyTwoTimesInAnArrayOfWords(words)<<endl;
	return 0;
}
