#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthNum(vector<int>& nums1, vector<int>& nums2, int k){
        int left=max(0,k-(int)nums2.size());
        int right=min(k,(int)nums1.size());
        printf("k:%d\n", k);       
        while(left<right){
            int mid=left+right>>1;
            printf("left:%d mid:%d right:%d num2[k-mid-1]:%d num1[mid]:%d\n", left,mid,right,nums2[k-mid-1],nums1[mid]);
            if(nums2[k-mid-1]>nums1[mid]) left=mid+1;
            else right=mid;
        }
        printf("left-1:%d k-left-1:%d\n",left-1,k-left-1);
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
int main(){
    int a[] = {6,7,8,9};
    int b[] = {1,2,3,4,5};
    vector<int>num1(a,a+4),num2(b,b+5);
    for(int i=0;i<4;++i) printf("%d%c",a[i],i==3?'\n':' ');
    for(int i=0;i<5;++i) printf("%d%c",b[i],i==4?'\n':' ');
    Solution sol;
    printf("%.2f\n", sol.findMedianSortedArrays(num1,num2));

}