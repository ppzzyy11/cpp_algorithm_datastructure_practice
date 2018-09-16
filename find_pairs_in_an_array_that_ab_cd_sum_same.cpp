//http://www.geeksforgeeks.org/find-four-elements-a-b-c-and-d-in-an-array-such-that-ab-cd/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> nums{3, 4, 7, 1, 12, 9};
    unordered_map<int,int> rec;

    int l1,r1;
    int l2,r2;
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            rec[nums[i]+nums[j]]++;
            if(rec[nums[i]+nums[j]]==2)
            {
                res=1;
                l2=i;
                r2=j;
                break;
            }
        }
    }
    for(int i=0;i<nums.size();i++)
    {
        if(i==l2||i==r2)
            continue;
        for(int j=i+1;j<nums.size();j++)
        {
            if(j==l2||j==r2) continue;
            if(nums[i]+nums[j]==nums[l2]+nums[r2])
            {
                l1=i;
                r1=j;
                break;
            }
        }
    }
    cout<<nums[ l1 ]<<":"<<nums[ r1 ]<<endl;
    cout<<nums[ l2 ]<<":"<<nums[ r2 ]<<endl;
    cout<<res<<endl;
    return 0;
}
