class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>mp;
        for(auto v:deck){
            mp[v]++;
        }
        int g=0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
            g=__gcd(it->second,g);
        }
        return g>=2;
    }
};