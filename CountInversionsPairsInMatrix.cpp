/*
 * Count Inversions Pair In A Matrix
 * 2D Binary Indexed Tree
 *
 * Inversions Pair:smaller cordinates but biger value
 * x1<=x2
 * y1<=y2
 *
 * And A[x2][y2]<A[x1][y1]
 *
 * We insert GetSum of all coordinates of the Bigger elements first
 * Then we update all coordinates of all the Bigger elements second
 *
 * INSERT THE BIGGER FIRST
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

template<typename Value>
ostream& operator<<(ostream& os,const vector<Value>& nums)
{
	for(auto num:nums)
	{
		 cout<<num<<' ';
	}
	return os;
}

template<typename Value>
ostream& operator<<(ostream& os,const vector<vector<Value>>& mat)
{
	for(auto nums:mat)
	{
		for(auto num:nums)
		{
			cout<<num<<' ';
		}
		cout<<'\n';
	}
	return os;
}

template<typename Value>
class TwoDBIT{
	public:
		TwoDBIT(vector<vector<Value>>& mat)
		{
			vector<vector<int>> tmp(mat.size(),vector<int>(mat[0].size(),0));
			vector<Value> nums;
			unordered_map<int,vector<pair<int,int>>> hash;
			for(int i=0;i<mat.size();i++)
			{
				for(int j=0;j<mat[i].size();j++)
				{
					nums.push_back(mat[i][j]);
					hash[mat[i][j]].push_back(make_pair(i,j));
				}
			}
			sort(nums.begin(),nums.end());
			for(int i=0;i<nums.size();i++)
			{
				for(auto cor:hash[nums[i]])
				{
					int x=cor.first;
					int y=cor.second;
					tmp[x][y]=i;
				}
			}
			cout<<tmp<<endl;

			BIT.resize(mat.size()+1,vector<int>(mat[0].size()+1,0));
			Cnt=0;
			//insert form the bigger element
			for(int i=nums.size();i>=0;i--)
			{
				for(auto coor:hash[nums[i]])//split the GetSum and Update to get the right result
				{
					int x=coor.first;
					int y=coor.second;
					Cnt+=GetSum(x,y);
				}
				for(auto coor:hash[nums[i]])
				{
					int x=coor.first;
					int y=coor.second;
					Update(x,y);
				}
				while(i>0&&nums[i]==nums[i-1])
				{
					i--;
				}
			}
		}
		int GetCnt() const {return Cnt;}
	protected:
		vector<vector<int>> BIT;
		int Cnt;
	private:
		int GetSum(const int x,const int y)
		{
			int sum=0;
			int i=x+1;
			int j=y+1;
			while(i>0)
			{
				j=y+1;
				while(j>0)
				{
					sum+=BIT[i][j];
					j=j-(j&(-j));
				}
				i=i-(i&(-i));
			}
			return sum;
		}
		bool Update(const int x,const int y)
		{
			int i=x+1;
			int j=y+1;
			while(i<BIT.size())
			{
				j=y+1;
				while(j<BIT[i].size())
				{
					BIT[i][j]+=1;
					j=j+(j&(-j));
				}
				i=i+(i&(-i));
			}
			return true;
		}
};

int main()
{
	vector<vector<int>> mat=
	{
		{ 4, 7, 2, 9  },
		{ 6, 4, 1, 7  },
		{ 5, 3, 8, 1  },
		{ 3, 2, 5, 6  }
	};
	TwoDBIT<int> tb(mat);
	cout<<tb.GetCnt()<<endl;
	return 0;
}
