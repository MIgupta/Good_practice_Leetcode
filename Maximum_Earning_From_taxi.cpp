#include<bits/stdc++.h>
using namespace std;
int find(vector<vector<int>>&events,int start,int toFind)
    {
        int low=start;
        int high=events.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(events[mid][0]>=toFind)
            {
                ans=mid;
              high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
      
        return ans;
        
    }
    long long solve(int curr,vector<vector<int>> &rides,vector<long long > &dp,int n)
    {
        if(curr>=rides.size())return 0;
        if(dp[curr]!=-1)return dp[curr];

        // ------------------O(log(n))--------------------
        int i=find(rides,curr+1,rides[curr][1]);

        // ----------------O(n)-------------------
        // for(i=curr+1;i<n;i++)
        // {
        //     if(rides[i][0]>=rides[curr][1])
        //         break;
        // }
        long long take=-1e12;
        long long n_take=-1e12;
        take=rides[curr][1]-rides[curr][0]+rides[curr][2]+solve(i,rides,dp,n);
        n_take=0+solve(curr+1,rides,dp,n);
        return dp[curr]=max(take,n_take);

    }
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int idx=rides.size();
        vector<long long > dp(idx+1,-1);
        sort(begin(rides),end(rides));
        return solve(0,rides,dp,idx);
}

int main()
{
    int n=5;
    vector<vector<int>> rides = {{2,5,4},{1,5,1}};
    cout<<maxTaxiEarnings(n,rides);
    return 0;

}