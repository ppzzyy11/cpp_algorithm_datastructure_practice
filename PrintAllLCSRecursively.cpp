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

void Helper(const string& str1,int i,const string& str2,int j,const vector<vector<int>>& mat,vector<string>& res,string& tmp)
{
	if(i==0||j==0)
	{
		reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		reverse(tmp.begin(),tmp.end());
		//res.push_back( string(tmp.rend(),tmp.rbegin()) );
		//ERROR
		return ;
	}

	if(str1[i-1]==str2[j-1])
	{
		tmp+=str1[i-1];
		Helper(str1,i-1,str2,j-1,mat,res,tmp);
		tmp.pop_back();
	}else
	{
		if(mat[i][j-1]>=mat[i-1][j])
		{
			Helper(str1,i,str2,j-1,mat,res,tmp);
		}
		if(mat[i][j-1]<=mat[i-1][j])
		{
			Helper(str1,i-1,str2,j,mat,res,tmp);
		}
	}
}
void PrintAllLCRecursively(const string & str1,const string &str2)
{
	vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1,0));
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
			{
				mat[i+1][j+1]=mat[i][j]+1;
			}else
			{
				mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
			}
		}
	}

	vector<string> res;
	string tmp="";
	Helper(str1,str1.size(),str2,str2.size(),mat,res,tmp);
	for(auto r:res)
	{
		cout<<r<<endl;
	}
}

int main()
{
	string str1="AGTGATG";
	string str2="GTTAG";
	PrintAllLCRecursively(str1,str2);
	//output
	//GTTG
	//GTAG
	//GTAG
	//注意:并不是重复,str2中可以出翔两个不同的T(位置不同)
	//Press ENTER or type command to continue
	//
	return 0;
}
