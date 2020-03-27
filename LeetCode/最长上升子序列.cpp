class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,INT_MAX);
        int ans=0;
        for(auto v:nums){
            int p=lower_bound(dp.begin(),dp.end(),v)-dp.begin();
            dp[p]=v;
            ans=max(ans,p+1);
        }
        return ans;
    }
};