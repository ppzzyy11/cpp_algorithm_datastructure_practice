#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main()
{
    vector<int> nums{1, 9, 3, 10, 4, 20, 2};

    unordered_set<int> rec(nums.begin(),nums.end());


    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        if(rec.count(nums[i])!=0)
        {
            int len=1;
            rec.erase(nums[i]);
            int l=nums[i]-1;
            int r=nums[i]+1;
            while(rec.count(l)!=0)
            {
                rec.erase(l);
                l--;
                len++;
            }
            while(rec.count(r)!=0)
            {
                rec.erase(r);
                r++;
                len++;
            }
            res=max(res,len);
        }
    }
    cout<<res<<endl;
    return 0;
}
