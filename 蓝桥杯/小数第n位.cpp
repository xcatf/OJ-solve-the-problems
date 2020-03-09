#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
typedef long long ll;
int main()
{
    ll a, b, n;
    while(scanf("%lld%lld%lld", &a, &b, &n) != EOF){
        a %= b;
        while(n > 10){
            a *= 1e10;
            a %= b;
            n -= 10;
        }
        for(int i = 0; i < (int)n - 1; ++i){
            a *= 10;
            a %= b;
        }
        for(int i = 0; i < 3; ++i){
            a *= 10;
            printf("%lld", a / b);
            a %= b;
        }
        putchar('\n');
    }   
    return 0;
}