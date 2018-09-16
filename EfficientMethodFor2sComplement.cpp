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

void EfficientMethodFor2sComplement(string& str)
{
	if(str.size()==0) return ;
	int pos=str.size()-1;
	while(pos>=0&&str[pos]!='1')
		pos--;
	if(pos==0) return ;
	if(pos<0)
	{
		str='1'+str;
		return ;
	}
	for(int i=pos-1;i>=0;i--)
	{
		str[i]=(str[i]=='1'?'0':'1');
	}
	return ;
}

int main()
{
	//string str="0111";
	//string str="1000";
	string str="0000";
	EfficientMethodFor2sComplement(str);
	cout<<str<<endl;
	return 0;
}
