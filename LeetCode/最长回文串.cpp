class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>v(52,0);
        for(auto ch:s){
           if(ch>='a'&&ch<='z') v[ch-'a']++;
           else v[ch-'A'+26]++;
        }
        int ans=0;
        for(int i=0;i<52;++i){
            ans+=(v[i]/2)*2;
            if(v[i]%2==1&&ans%2==0) ++ans;
        }
        return ans;
    }
};