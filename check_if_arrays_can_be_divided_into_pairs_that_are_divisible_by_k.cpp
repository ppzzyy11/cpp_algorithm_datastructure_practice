#include<iostream>
#include<vector>
//http://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/
using namespace std;

int main()
{
    vector<int> nums{12, 9, 6, 3};
    int k=3;

    int res=1;
    vector<int> rmd(k,0);//remainders 0->k-1 k ge
    for(int i=0;i<nums.size();i++)
    {
        rmd[nums[i]%k]++;
    }
    for(int i=1,j=k-1;i<=j;i++,j--)
    {
        if(i==j)
        {
         res=(rmd[i]%2==0);
         break;
        }
        else
        {
            if(rmd[i]==rmd[j])
                ;
            else
            {
                res=0;
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
