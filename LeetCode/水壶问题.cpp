using PII = pair<int, int>;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x==0&&y==0||z>x+y) return false;
        int g=__gcd(x,y);
        return z%g==0;
    }
};