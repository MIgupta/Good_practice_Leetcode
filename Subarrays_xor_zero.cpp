#include<bits/stdc++.h>
using namespace std;
long long beautifulSubarrays(vector<int>& nums) {
        
        unordered_map<long long,long long> mp;
        int xo=0;
        mp[0]=1;
        int i=0;
        int n=nums.size();
        long long cnt=0;
        while(i<n)
        {
            xo=xo^nums[i];
            if(mp.find(xo^0)!=mp.end())
            {
                cnt+=mp[xo^0];
            }
            mp[xo]++;
            i++;
        }
        return cnt;
}

int main()
{
    vector<int> nums={4,2,4,1,5};
    cout<<beautifulSubarrays(nums);
    return 0;

}