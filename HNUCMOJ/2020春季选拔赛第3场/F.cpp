#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
static const double eps = 1e-4;
double pos[maxn];
int n, k;
bool check(double dis){
    bool f = 1;
    int now = 0;
    double maxd = pos[1] - 1;
    for(int i = 1; i <= n; ++i){
        if(pos[i] > maxd){
            now++;
            if(now > k) return 0;
            if(pos[i + 1] - pos[i] > dis * 2) maxd = pos[i] + dis;
            else maxd = pos[i] + dis * 2;
        }
    }
    return 1;
}
int main(){
    while(scanf("%d%d", &n, &k) != EOF){
        for(int i = 1; i <= n; ++i) scanf("%lf", &pos[i]);
        pos[n + 1] = pos[n];
        double L = 0, R = (pos[n] - pos[1]) / 2 + 1;
        while(L < R){
            double mid = (L + R) / 2;
            if(check(mid)){
                R = mid - 0.0000005;
            }
            else L = mid + 0.0000005;
        }
        R = max(0.0, R);
        printf("%.6f\n", R);
    }
    return 0;
}