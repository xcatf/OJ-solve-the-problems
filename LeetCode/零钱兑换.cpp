class Solution {
public:
    void dfs(vector<int>&coins,int s,int amount,int cnt,int &ans){
        if(amount==0){
            ans=min(ans,cnt);
            return ;
        }
        if(s==coins.size()) return;
        for(int k=amount/coins[s];k>=0&&k+cnt<ans;--k){
            dfs(coins,s+1,amount-k*coins[s],cnt+k,ans);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.rbegin(),coins.rend());
        int ans=INT_MAX;
        dfs(coins,0,amount,0,ans);
        return ans==INT_MAX?-1:ans;
    }
};