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


string PrintLongesstCommonSubsequences(const string& str1,const string& str2)
{
	vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1,0));
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
			{
				//mat[i+1][j+1]=max(mat[i][j],mat[i][j+1],mat[i+1][j])+1;
				mat[i+1][j+1]=mat[i][j]+1;//mat[i][j] = max( mat[i][j-1], mat[i-1][j] ), at least
			}else
			{
				mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
			}
		}
	}

	string res="";

	int i=str1.size(),j=str2.size();
	while(i!=0&&j!=0)
	{
		if(mat[i][j]==mat[i-1][j]+1&&mat[i][j]==mat[i][j-1]+1)
		{
			res+=str1[i-1];
			i--;
			j--;
		}else if(mat[i][j]==mat[i-1][j]+1)
		{
			j--;
		}else
		{
			i--;
		}
	}

	reverse(res.begin(),res.end());
	return res;

}

int main()
{
	const string str1="1234567890";
	const string str2="24680";
	cout<<PrintLongesstCommonSubsequences(str1,str2)<<endl;
    return 0;
}
