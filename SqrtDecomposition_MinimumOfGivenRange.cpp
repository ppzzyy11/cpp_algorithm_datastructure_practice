/*
 * Square Root(Sqrt) Decomposition | Minimum of given range
 * Proprocessing takes O(n) time and O(n^1/2) space
 *
 * Query TC O(n^1/2)
 * Update TC O(n^1/2)
 *
 * We decompose the array into n^1/2 chunks to store the minimum of their range to save time of Query
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
		vector<int> minis;//store the minimums of chunks
		vector<int> nums;
		int len;
	public:
		int Query(const int l,const int r)
		{
			int s=l/len;
			int e=r/len;

			int res=INT_MAX;
            if(s==e)
            {
                for(int i=l;i<=r;i++)
                {
                    res=min(res,nums[i]);
                }
            }else
            {
				for(int i=s+1;i<e;i++)//start form s+1 to e-1 chunk
				{
                    res=min(res,minis[i]);
				}

				for(int i=l;i<(s+1)*len;i++)//start from l element to the end of s chunk
				{
                    res=min(res,nums[i]);
				}
				for(int i=e*len;i<=r;i++)//start form the beign of e chunk to r
				{
                    res=min(res,nums[i]);
				}
            }
			return res;
		}
		bool Update(const int idx,const int val)
		{
			nums[idx]=val;
			int i=idx/len;//minis index
			int s=i*len;
			int e=min((i+1)*len,(int)nums.size());
			int res=INT_MAX;
			for(int k=s;k<e;k++)
			{
				res=min(res,nums[k]);
			}
			minis[i]=res;
			return true;
		}
		SqrtDecompostion(const vector<int>& nums0)//ok
		{
			len=sqrt(nums0.size());//minis every chunk len
			int n=nums0.size()/len;//minis size
			if(len*n<nums0.size())
			{
				n++;//another nums0 element
			}

			minis.resize(n,INT_MAX);

			for(int i=0;i<n;i++)
			{
				for(int j=i*len;j<nums0.size()&&j<(i+1)*len;j++)
				{
					minis[i]=min(minis[i],nums0[j]);
				}
			}
			nums=nums0;
			//test pass
			//cout<<minis<<endl;
		}
		~SqrtDecompostion()
		{
			//Size=0;
			nums.resize(0,0);
			minis.resize(0,0);
		}
		int GetNthNum(const int n)
		{
			if(n<0||n>=nums.size()) return INT_MAX;
			return nums[n];
		}

};

int main()
{
	//vector<int> nums={7, 2, 3, 0, 5, 10, 3, 12, 18, 19};
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
		sq.Update(idx,num);
		nums[idx]=num;
		for(int j=i;j<nums.size();j++)
		{
			int mini=INT_MAX;
			for(int k=i;k<=j;k++)
			{
				mini=min(mini,nums[k]);
			}
			int res=sq.Query(i,j);
			if(res==mini)
			{
				cout<<i<<" to "<<j<<" same "<<res<<"\n";
			}else
			{
				cout<<i<<" to "<<j<<" different res: "<<res<<" mini: "<<mini<<"\n";
				cout<<"idx: "<<idx<<" num: "<<num<<endl;
				return 1;
			}
		}
	}
	//cout<<nums<<endl;
	return 0;
}
