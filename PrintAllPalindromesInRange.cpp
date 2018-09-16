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

bool IfPalindromic(int n)
{
	int p=0;
	int t=n;
	while(t)
	{
		p=p*10+t%10;
		t=t/10;
	}
	return p==n;
}

void PrintAllPalindromes(const int& s,const int& e)
{
	for(int i=s;i<=e;i++)
	{
		if(IfPalindromic(i))
		{
			cout<<i<<endl;
		}
	}
}

int main()
{
	PrintAllPalindromes(10,115);
	return 0;
}
