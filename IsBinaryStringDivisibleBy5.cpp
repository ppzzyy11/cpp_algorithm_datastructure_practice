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

const vector<int> rmds={1,2,4,3};

string IsBinaryStringDivisibleBy5(const string& str)
{
	int r=0;
	int res=0;
	for(int i=str.size()-1;i>=0;i--)
	{
		if(str[i]=='1')
		{
			res+=rmds[r];
			res%=5;
		}
		r++;
		r%=rmds.size();
	}
	return res==0?"YES":"NO";

}

int main()
{
	string str="10000101001";
	cout<<IsBinaryStringDivisiableBy5(str)<<endl;
	return 0;
}
