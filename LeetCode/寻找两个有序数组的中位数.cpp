using namespace std;
class Solution {
public:
    int findKthNum(vector<int>& nums1, vector<int>& nums2, int k){
        int left=max(0,k-(int)nums2.size());
        int right=min(k,(int)nums1.size());
        while(left<right){
            int mid=left+right>>1;
            if(nums2[k-mid-1]>nums1[mid]) left=mid+1;
            else right=mid;
        }
        int nums1Max = left==0?INT_MIN:nums1[left-1];
        int nums2Max = left==k?INT_MIN:nums2[k-left-1];
        return max(nums1Max,nums2Max);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        if(n&1){
            return findKthNum(nums1,nums2,(n>>1)+1);
        }
        else{
            return (findKthNum(nums1,nums2,n>>1) + findKthNum(nums1,nums2,(n>>1)+1))/2.0;
        }
    }
};