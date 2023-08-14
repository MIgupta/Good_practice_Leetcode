#include<bits/stdc++.h>
using namespace std;
void find_non_repeating(vector<int> &nums)
{
    int n=nums.size();
    int xxory=0;
    for(int i=0;i<n;i++)
    {
        xxory=xxory^nums[i];
    }
    int mask=xxory & -xxory;
    int x=0,y=0;
    
    for(int i=0;i<n;i++)
    {
        if((mask & nums[i])==0)
        {
            x=x^nums[i];
        }
        else{
            y=y^nums[i];
        }
    }
    if(x>y)cout<<y<<" "<<x;
    else cout<<x<<" "<<y;
    return ;
}
int main()
{
    vector<int> nums= {1,2,2,1,3,4};

    find_non_repeating(nums);
    return 0;

}