class Solution {
public:
    int squareSum(int n){
        int res=0;
        while(n){
            int v=n%10;
            n/=10;
            res+=v*v;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast=n,slow=n;
        do{
            slow=squareSum(slow);
            fast=squareSum(fast);
            fast=squareSum(fast);
        }while(fast!=slow);
        return fast==1;
    }
};