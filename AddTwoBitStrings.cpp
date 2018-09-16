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

string AddTwoBitStrings(const string& str1,const string& str2)
{
	string res="";

	int i=str1.size()-1;
	int j=str2.size()-1;
	bool add=0;

	while(i>=0||j>=0||add)
	{
		int num=0;
		if(i>=0) {num+=str1[i]-'0';i--;}
		if(j>=0) {num+=str2[j]-'0';j--;}
		if(add) {num++;add=0;}
		res=(char)('0'+num%2)+res;
		add=num/2;
	}
	return res;
}

int main()
{
	//string str1="1100011";
	//string str2="10";
	string str1="111111";
	string str2="1";
	cout<<AddTwoBitStrings(str1,str2)<<endl;
	return 0;
}
