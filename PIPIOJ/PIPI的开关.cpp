#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
int main(){
    ll n;
    while (~scanf("%lld", &n)){
        ll l = 1, r = 1e9;
        while (l < r){
            ll mid = l + r >> 1;
            if (mid*(mid+2)<n)
                l = mid + 1;
            else
                r = mid;
        }
        printf("%lld\n", r);
    }
    return 0;
}