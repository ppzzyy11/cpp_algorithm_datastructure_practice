#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> nums{1, 0, 3};

    unordered_map<int,int> rec;
    int sum=0;
    rec[0]=-1;
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        if(rec.count(sum)!=0)
        {
            res=max(res,i-rec[sum]);
        }else
            rec[sum]=i;
    }
    cout<<res<<endl;
    return 0;
}
