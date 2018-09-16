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

struct S
{
	int x;
	int y;
	string tmp;
	S(int x,int y,string &tmp):x(x),y(y),tmp(tmp){}
};
ostream& operator<<(ostream& os,const vector<vector<int>> mem)
{
	for(int i=0;i<mem.size();i++)
	{
		for(int j=0;j<mem[i].size();j++)
		{
			cout<<'('<<i<<','<<j<<')'<<" "<<mem[i][j]<<"\t\t";
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<string> & strs)
{
	for(int i=0;i<strs.size();i++)
	{
		cout<<strs[i]<<endl;
	}
	return os;
}
vector<S> rec;
inline bool operator==(const S&s0,const S&s1)
{
	if(s0.x!=s1.x)
		return 0;
	if(s0.y!=s1.y)
		return 0;
	if(s0.tmp!=s1.tmp)
		return 0;
	return 1;
}
bool exit(const S&s)
{
	for(int i=0;i<rec.size();i++)
	{
		if(rec[i]==s)
			return 1;
	}
	return 0;
}
void GetAllLongestCommonSubsequences(string &tmp,vector<string>& strs,int x,int y,const string& str1, const string & str2,const vector<vector<int>>& mem)//overlappin qusetion
{
	S s(x,y,tmp);
	if(exit(s))
		return ;
	rec.push_back(s);

	if(x==0&&y==0)
	{
		strs.push_back(string(tmp.rbegin(),tmp.rend()));
		return ;
	}else if(x==0||y==0)
		return;
	if(mem[x][y]==mem[x-1][y])
	{
		GetAllLongestCommonSubsequences(tmp,strs,x-1,y,str1,str2,mem);
	}
	if(mem[x][y]==mem[x][y-1])
	{
		GetAllLongestCommonSubsequences(tmp,strs,x,y-1,str1,str2,mem);
	}
	if(mem[x][y]==mem[x][y-1]+1&&mem[x][y]==mem[x-1][y]+1)
		//if(mem[x][y]==mem[x-1][y-1]+1)
	{
		tmp+=str1[x-1];
		GetAllLongestCommonSubsequences(tmp,strs,x-1,y-1,str1,str2,mem);
		tmp.pop_back();
	}
	if(str1[x-1]==str2[y-1])
	{
		tmp+=str1[x-1];
		if(mem[x][y]==mem[x][y-1]+1&&mem[x][y]==mem[x-1][y])
		{
			GetAllLongestCommonSubsequences(tmp,strs,x,y-1,str1,str2,mem);
		}
		if(mem[x][y]==mem[x-1][y]+1&&mem[x][y]==mem[x][y-1])
		{
			GetAllLongestCommonSubsequences(tmp,strs,x-1,y,str1,str2,mem);
		}
		tmp.pop_back();
	}
	return ;
}
int LongestCommonSubsequences(const string &str1,const string&str2)
{
	vector<vector<int>> mem(str1.size()+1,vector<int>(str2.size()+1,0));
	for(int i=1;i<=str1.size();i++)
	{
		for(int j=1;j<=str2.size();j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				mem[i][j]=mem[i-1][j-1]+1;
			}else
			{
				mem[i][j]=max(mem[i][j-1],mem[i-1][j]);
			}
		}
	}
	cout<<mem<<endl;
	vector<string> strs;
	string tmp="";
	GetAllLongestCommonSubsequences(tmp,strs,str1.size(),str2.size(),str1,str2,mem);
	sort(strs.begin(),strs.end());
	cout<<strs<<endl;
	return mem.back().back();
}

int main()
{
    const string str1="abcabcaa";
    const string str2="acbacba";
    cout<<LongestCommonSubsequences(str1,str2)<<endl;
    return 0;
}
