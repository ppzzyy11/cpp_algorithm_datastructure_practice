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

string  ManachersAlgorithm(const string& str)
{
	if(str.size()==0)
		return "No Answer";
	int len=str.size();
	int N=2*len+1;
	vector<int> L(N,0);
	L[0]=0;
	L[1]=1;
	int C=1;//centerPosition
	int R=2;//centerRightPosition
	int i=0;//currentRightPosition
	int iMirror;//currentLeftPosition
	int expand=-1;
	int diff=-1;

	int MaxLPSLength=0;//record the Longest Palindromic Substring
	int MaxLPSCenterPosition=0;
	int start=-1,end=-1;

	for(i=2;i<N;i++)
	{
		iMirror=2*C-i;//get currentLeftPosition
		expand=0;
		diff=R-i;//centerRightPosition-currentRightPosition
		if(diff>0)//i is in already caculated Palirome
		{
			if(L[iMirror]<diff)//Case 1
			{
				L[i]=L[iMirror];//L[currentRightPosition]=L[currentLeftPosition]
			}else if(L[iMirror]==diff&&i==N-1)//case 2 		currentRightPosition==2*len 结尾
			{
				L[i]=L[iMirror];
			}else if(L[iMirror]==diff&&i<N-1)//case 3 		may epand
			{
				L[i]=L[iMirror];
				expand=1;
			}else if(L[iMirror]>diff)// Case 4 左边的palindrome 相对于右边来说太长了
			{
				L[i]=diff;
				expand=1;
			}
		}else //No already caculated palindrome
		{
			L[i]=0;
			expand=1;
		}

		if(expand==1)//expand =1 时, L[i]代表了从哪个地方开始比较
		{
			while(i+L[i]<N&&i-L[i]>0&&((i+L[i]+1)%2==0||str[(i+L[i]+1)/2]==str[(i-L[i]-1)/2]))
			{
				L[i]++;
			}
		}

		if(L[i]>MaxLPSLength)
		{
			MaxLPSLength=L[i];
			MaxLPSCenterPosition=i;
		}


		if(i+L[i]>R)// the right side of already caculated palindrome expands
		{
			C=i;
			R=i+L[i];
		}
	}
	//cout<<"L:"<<L;

	start=(MaxLPSCenterPosition-MaxLPSLength)/2;
	end=start+MaxLPSLength-1;
	//cout<<start<<":"<<end<<endl;
	return str.substr(start,end-start+1);
}

string ManachersAlgorithm2(const string& str)
{
	int len=str.size();
	if(len==0) return "No Answer";
	int N=2*len+1;
	vector<int> L(N,0);
	L[0]=0;
	L[1]=1;
	int C=1;//CenterPosition
	int R=2;//centerRightPosition
	int i=0;//currentRightPosition
	int iMirror;//currentLeftPosition

	int MaxLPSLength=0;
	int MaxLPSCenterPosition=0;
	int start=-1;
	int end=-1;
	int diff=-1;

	for(i=2;i<N;i++)
	{
		iMirror=2*C-i;
		L[i]=0;
		diff=R-i;//centerRightPosition-currentRightPosition
		if(diff>0)
		{
			L[i]=min(L[iMirror],diff);
		}
		 while((i+L[i]<N&&i-L[i]>0)&&((i+L[i]+1)%2==0||str[(i+L[i]+1)/2]==str[(i-L[i]-1)/2]))
		{
			L[i]++;
		}

		 if(L[i]>MaxLPSLength)
		 {
			 MaxLPSLength=L[i];
			 MaxLPSCenterPosition=i;
		 }

		 if(i+L[i]>R)
		 {
			 C=i;
			 R=i+L[i];
		 }
	}

	start=(MaxLPSCenterPosition-MaxLPSLength)/2;
	end=start+MaxLPSLength-1;
	//cout<<start<<":"<<end<<endl;
	return str.substr(start,end-start+1);
}

int main()
{
	vector<string> strs=
	{
		"babcbabcbaccba",
		"abaaba",
		"abababa",
		"abcbabcbabcba",
		"forgeeksskeegfor",
		"caba",
		"abacdfgdcaba",
		"abacdfgdcabba",
		"abacdedcaba"
	};
	for(auto str:strs)
	{
		cout<<"LPS of "<<str<<" is :"<<ManachersAlgorithm(str)<<endl;
		cout<<"LPS of "<<str<<" is :"<<ManachersAlgorithm2(str)<<endl;
	}
	return 0;
}
