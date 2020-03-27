using ll=long long;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<long>sum(n);
        vector<vector<long>>dp(m,vector<long>(n,INT_MAX));
        sum[0]=dp[0][0]=nums[0];
        for(int i=1;i<n;++i){
            sum[i]=sum[i-1]+nums[i];
            dp[0][i]=sum[i];
        }
        for(int i=1;i<m;++i){
            for(int j=i;j<n;++j){
                for(int k=0;k<j;++k){
                    dp[i][j]=min(dp[i][j],max(dp[i-1][k],sum[j]-sum[k]));
                }
            }
        }
        return dp[m-1][n-1];
    }
};