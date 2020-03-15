#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e5 + 5;
typedef long long ll;
int a[maxn];
int main(){
    int cas;
    int n, m;
    scanf("%d%d%d", &cas, &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while(m--){
        int op, l, r, ql, qr, d;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d%d", &l, &r, &d);
            for(int i = l; i <= r; ++i) a[i] += d;
        }
        else if(op == 2){
            scanf("%d%d%d%d", &l, &r, &ql, &qr);
            for(int i = ql; i <= qr; ++i) a[l++] = a[i];
        }
        else{
            scanf("%d%d", &l, &r);
            ll ans = 0;
            for(int i = l; i <= r; ++i) ans += a[i];
            printf("%lld\n", ans);
        }
    }
}