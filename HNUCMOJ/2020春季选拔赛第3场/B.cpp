#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
static const double eps = 1e-4;
double N, k;
int main(){
    while(scanf("%lf%lf", &N, &k) != EOF){
        double now1 = 50, now2 = 200;
        int ans = 1;
        bool f = 0;
        while(now1 < now2){
            ans++;
            double add = now2 * k / 100;
            if(add > N){
                f = 1;
                break;
            }
            now1 += N;
            now2 += add;
        }
        if(f) puts("Impossible");
        else printf("%d\n", ans);
    }
}