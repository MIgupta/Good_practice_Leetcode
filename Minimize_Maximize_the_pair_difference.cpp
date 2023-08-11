#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> &nums,int target,int p,int n)
    {
        int pairs=0;

        for(int i=0;i<n-1;)
        {
            if(nums[i+1]-nums[i]<=target)
            {
                pairs++;
                i=i+2;
            }
            else i++;
        }
        if(pairs>=p)return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        int res=0;
        while(low<=high)
        {
            
            int mid=(low+high)/2;
            
            if(solve(nums,mid,p,n))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }

int main()
{
    int pair=2;
    vector<int> nums={4,2,4,1,5};
    cout<<minimizeMax(nums,pair);
    return 0;

}