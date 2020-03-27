class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ans=0;
        for(auto v:nums){
            if(cnt==0) ans=v;
            if(v==ans) ++cnt;
            else --cnt;
        }
        return ans;
    }
};