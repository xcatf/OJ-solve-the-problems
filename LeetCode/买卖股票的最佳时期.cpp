class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,l=INT_MAX;
        for(auto p:prices){
            ans=max(ans,p-l);
            l=min(l,p);
        }
        return ans;
    }
};