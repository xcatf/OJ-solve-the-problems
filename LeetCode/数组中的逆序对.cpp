class Solution {
public:
    typedef long long ll;
    static const int maxn = 5e4 + 5;
    int ans = 0;
    int b[maxn];
    void merge(int l, int r, vector<int>&nums){
        int pos = (l + r) / 2;
        int i = l, j = pos + 1;
        int idx = l;
        while(i <= pos && j <= r){
            if(nums[i] <= nums[j]) b[idx++] = nums[i++];
            else{
                b[idx++] = nums[j++];
                ans += pos - i + 1;
            }
        }
        while(i <= pos) b[idx++] = nums[i++];
        while(j <= r) b[idx++] = nums[j++];
        for(int k = l; k <= r; ++k) nums[k] = b[k];
    }
    void merge_sort(int l, int r, vector<int>&nums){
        if(l < r){
            int mid = (l + r) >> 1;
            merge_sort(l, mid, nums);
            merge_sort(mid + 1, r, nums);
            merge(l, r, nums);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge_sort(0, n - 1, nums);
        return ans;
    }
};