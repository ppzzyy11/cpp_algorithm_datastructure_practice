/*
 * Square Root(Sqrt) Decomposition | Sum of Given Range
 * Proprocessing takes O(n) time and O(n^1/2) space
 *
 * Query TC O(n^1/2)
 * Update TC O(n^1/2)
 *
 * We decompose the array into n^1/2 chunks to store the sum of their range to save time of Query
 *
 * BRUET TEST PASSED
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<' ';
	}
	cout<<endl;
	return os;
}

class SqrtDecompostion{
	private:
		vector<int> sums;//store the sum of chunks
		vector<int> nums;//store every element of the input array
		int len;
	public:
		int Query(const int l,const int r)
		{
			int s=l/len;
			int e=r/len;
			int res=0;
			if(s==e)//l and r are in one chunk
			{
				for(int i=l;i<=r;i++)
				{
					res+=nums[i];
				}
			}else
			{
				for(int i=s+1;i<e;i++)//start from s+1 to e-1
				{
					res+=sums[i];
				}

				for(int i=l;i<(s+1)*len;i++)//add the elements from l to the end of s chunk (just before the s+1 chunk)
				{
					res+=nums[i];
				}
				for(int i=e*len;i<=r;i++)//add the element from the begin of e chunk to r
				{
					res+=nums[i];
				}
			}
			return res;
		}
		bool Update(const int idx,const int val)//val to be added at index idx
		{
			nums[idx]+=val;
			int i=idx/len;//sums index
			sums[i]+=val;
			return true;
		}
		SqrtDecompostion(const vector<int>& nums0)//ok
		{
			len=sqrt(nums0.size());//sums every chunk len
			int n=nums0.size()/len;//sums size
			if(len*n<nums0.size())
			{
				n++;//another chunk
			}

			sums.resize(n,0);

			for(int i=0;i<n;i++)
			{
				for(int j=i*len;j<nums0.size()&&j<(i+1)*len;j++)
				{
					sums[i]+=nums0[j];
				}
			}
			nums=nums0;
		}
		~SqrtDecompostion()
		{
			nums.resize(0,0);
			sums.resize(0,0);
		}

};

int main()
{
	srand(time(NULL));
	vector<int> nums;
	int len=2000;
	for(int i=0;i<len;i++)
	{
		nums.push_back(rand()%10000);
	}
	SqrtDecompostion sq(nums);
	for(int i=0;i<nums.size();i++)
	{
	int idx=rand()%nums.size();
	int num=rand()%10000;
	sq.Update(idx,num);//add num at index
	nums[idx]+=num;
		for(int j=i;j<nums.size();j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=nums[k];
			}
			int res=sq.Query(i,j);
			if(res==sum)
			{
				cout<<i<<" to "<<j<<" same "<<res<<"\n";
			}else
			{
				cout<<i<<" to "<<j<<" different res: "<<res<<" sum: "<<sum<<"\n";
				return 1;
			}
		}
	}
	return 0;
}
