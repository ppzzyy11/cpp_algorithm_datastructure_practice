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

ostream& operator <<(ostream&os ,const vector<vector<int>> & nums)
{
	for(int i=0;i<nums.size();i++)
	{
		for(int j=0;j<nums[i].size();j++)
		{
			cout<<nums[i][j]<<'\t';
		}
		cout<<endl;
	}
	return os;
}
set<string> FindAllLCS(const string&str1,int m,const string&str2,int n,const vector<vector<int>>& lcs)
{
	set<string> s;
	if(m==0||n==0)
	{
		s.insert("");
		return s;
	}

	if(str1[m-1]==str2[n-1])//charac
	{
		set<string> tmp=FindAllLCS(str1,m-1,str2,n-1,lcs);
		for(auto t:tmp)
		{
			s.insert(t+str1[m-1]);
		}
	}else
	{
		if(lcs[m-1][n]>=lcs[m][n-1])
		{
			s=FindAllLCS(str1,m-1,str2,n,lcs);
		}
		if(lcs[m][n-1]>=lcs[m-1][n])
		{
			set<string> tmp=FindAllLCS(str1,m,str2,n-1,lcs);
			s.insert(tmp.begin(),tmp.end());
		}
	}
	return s;
}

//Overlapping subproblems below
void FindAllLCS(string& tmp,set<string>&res,const string&str1,int m,const string& str2,int n,const vector<vector<int>>&lcs)
{
	if(m==0||n==0)
	{
		//这里需需要添加重复检测,
		res.insert( string(tmp.rbegin(),tmp.rend()) );
		return ;
	}
	if(str1[m-1]==str2[n-1])
	{
		tmp+=str1[m-1];
		FindAllLCS(tmp,res,str1,m-1,str2,n-1,lcs);
		tmp.pop_back();
	}else
	{
		if(lcs[m-1][n]>=lcs[m][n-1])
		{
			FindAllLCS(tmp,res,str1,m-1,str2,n,lcs);
		}
		if(lcs[m][n-1]>=lcs[m-1][n])
		{
			FindAllLCS(tmp,res,str1,m,str2,n-1,lcs);
		}
	}
}

void PrintAllLongestCommonSubsequencesInLexicograpgicalOrder(const string& str1,const string& str2)
{
	vector<vector<int>> lcs(str1.size()+1,vector<int>(str2.size()+1,0));// compute the lcs
	for(int i=1;i<=str1.size();i++)
	{
		for(int j=1;j<=str2.size();j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
			}else
			{
				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
			}
		}
	}
	cout<<lcs<<endl;
	set<string> AllLCS;
	string tmp="";
	FindAllLCS(tmp,AllLCS,str1,str1.size(),str2,str2.size(),lcs);
	for(auto str:AllLCS)
	{
		cout<<str<<endl;
	}

	//set<string> AllLCS=FindAllLCS(str1,str1.size(),str2,str2.size(),lcs);
	//for(auto it=AllLCS.begin();it!=AllLCS.end();it++)
	//{
		//cout<<*it<<endl;
	//}
}

int main()
{
	const string str1="abcabcaa";
	const string str2="acbacba";
	PrintAllLongestCommonSubsequencesInLexicograpgicalOrder(str1,str2);
    return 0;
}
