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

ostream& operator<<(ostream& os,const set<string>& strs)
{
	for(auto it=strs.begin();it!=strs.end();it++)
	{
		cout<<*it<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<char>& chs)
{
	for(int i=0;i<chs.size();i++)
	{
		cout<<chs[i]<<' ';
	}
	cout<<endl;
	return os;
}

string FindNthLexicographicallyPermutation(const string& str, int n=1)// 1 base
{//罗技是有点麻烦的
	if(n==0)
	{
		string tmp=str;
		reverse(tmp.begin(),tmp.end());
		return tmp;
	}
	vector<int> rec(256,0);
	int ttl=0;//total kinds of character

	for(auto s:str)
	{
		if(rec[s]==0)
		{
			ttl++;
		}
		rec[s]++;
	}

	vector<int> cnt;
	vector<char> chs;
	vector<int> n_n(str.size()+1,0);

	for(int i=0;i<rec.size();i++)
	{
		if(rec[i]!=0)
		{
			cnt.push_back(rec[i]);
			chs.push_back(i);
		}
	}
	n_n[0]=n_n[1]=1;
	for(int i=2;i<=str.size();i++)
	{
		n_n[i]=n_n[i-1]*i;
	}
	//cout<<cnt<<chs<<n_n<<endl;

	int sum=str.size();
	string res="";
	while(n>0)
	{
		//cout<<n<<":"<<str.size()<<":"<<res.size()<<endl;
		//cout<<res<<endl;
		for(int i=0;i<chs.size();i++)
		{
			if(cnt[i]>0)
			{
				cnt[i]--;
				int  num=1;
				for(int i=0;i<cnt.size();i++)
				{
					//cout<<"num:"<<num<<endl;
					//cout<<"cnt[i]"<<cnt[i]<<endl;
					num*=n_n[cnt[i]];
				}
				num=n_n[str.size()-res.size()-1]/num;
				//cout<<"NUM:"<<num<<":"<<n<<":"<<res<<endl;
				if(num>=n)
				{
					if(n==0)
					{
						res+=chs[i];
						for(int i=chs.size()-1;i>=0;i--)
						{
							while(cnt[i]!=0)
							{
								res+=chs[i];
								cnt[i]--;
							}
						}
						return res;
					}else if(n==1)
					{
						res+=chs[i];
						for(int i=0;i<str.size();i++)
						{
							while(cnt[i]!=0)
							{
								res+=chs[i];
								cnt[i]--;
							}
						}
						return res;
					}
					{
						res+=chs[i];
						break;
					}

				}else
				{
					n-=num;
					cnt[i]++;
				}
			}
		}
	}

	return res;
}

string NextPermutation(string& str)
{
	if(str.size()<=1) return 0;
	int i=str.size()-2;
	while(i>=0)
	{
		if(str[i]<str[i+1])
			break;
		i--;

	}
	if(i==-1)
	{
		reverse(str.begin(),str.end());
		return str;

	}
	int j=i+1;
	for(int k=i+2;k<str.size();k++)
	{
		if(str[k]>str[i]&&str[k]<str[j])
			j=k;

	}
	swap(str[i],str[j]);
	sort(str.begin()+i+1,str.end());
	return str;

}


int main()
{
	string str="aabbc";
	string cpy=str;
	for(int i=0;i<50;i++)
	{
		cout<<i+1<<endl;
		cout<<FindNthLexicographicallyPermutation(cpy,i+1)<<endl;
		cout<<str<<endl;
		cout<<endl;
		NextPermutation(str);
	}
	return 0;
}
