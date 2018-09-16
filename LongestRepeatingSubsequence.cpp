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

int LongestRepeatingSubsequence(const string& str)
{
	vector<vector<int>> mat(str.size()+1,vector<int>(str.size()+1,0));
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<str.size();j++)
		{
			if(i==j)
			{
				mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
			}else if(str[i]==str[j])
			{
				mat[i+1][j+1]=mat[i][j]+1;
			}else
			{
				mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
			}
		}
	}
	return mat.back().back();
}

int main()
{
	//string str="axxxy";
	//string str="axxy";
	//string str="axy";
	string str="aaxx";
	cout<<LongestRepeatingSubsequence(str)<<endl;
	return 0;
}
