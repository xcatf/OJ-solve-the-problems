class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        while(n>0&&nums[n]<=nums[n-1]) --n;
        reverse(nums.begin()+n,nums.end());
        if(n>0){
            for(int i=n;i<nums.size();++i){
                if(nums[i]>nums[n-1]){
                    swap(nums[n-1],nums[i]);
                    break;
                }
            }
        }
    }
};