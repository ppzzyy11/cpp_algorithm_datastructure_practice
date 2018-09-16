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

int NumberOfFlipsToMakeBinaryStringAlternate(const string& str)
{
	int cnt=0;
	bool num=0;
	for(auto s:str)
	{
		if(num)
		{
			if(s!='1')
			{
				cnt++;
			}
			num=0;
		}else
		{
			if(s!='0')
			{
				cnt++;
			}
			num=1;
		}
	}
	return min(cnt,(int)str.size()-cnt);
}

int main()
{
	//string str="001";
	string str="0001010111";
	cout<<NumberOfFlipsToMakeBinaryStringAlternate(str)<<endl;
	return 0;
}
