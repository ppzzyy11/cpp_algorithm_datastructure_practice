#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


int main()
{
    vector<int> nums{6, 3, -1, -3, 4, -2, 2,
                     4, 6, -12, -7};
    unordered_map<int,vector<int>> rec;//sun vector of index

    rec[0].push_back(-1);
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        cout<<i<<":"<<sum<<endl;
        rec[sum].push_back(i);
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(auto r:rec)
    {
        for(int i=0;i<r.second.size()-1;i++)
        {
            for(int j=i+1;j<r.second.size();j++)
            {
                for(int k=r.second[i]+1;k<=r.second[j];k++)
                {
                    cout<<nums[k]<<" ";
                }
                cout<<endl;
            }
        }
    }
}
