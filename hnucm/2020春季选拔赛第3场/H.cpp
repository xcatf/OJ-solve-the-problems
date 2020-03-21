#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
static const double eps = 1e-4;
struct Tree{
    int l, r;
    int g;
}tr[maxn << 2];
void pushUp(int now){
    tr[now].g = __gcd(tr[now << 1].g, tr[now << 1 | 1].g);
}
void build(int now, int l, int r){
    tr[now].l = l;
    tr[now].r = r;
    if(l == r){
        scanf("%d", &tr[now].g);
        return ;
    }
    int m = l + r >> 1;
    build(now << 1, l, m);
    build(now << 1 | 1, m + 1, r);
    pushUp(now);
}
int query(int now, int ql, int qr){
    if(tr[now].l == ql && tr[now].r == qr) return tr[now].g;
    if(tr[now << 1].r >= qr) return query(now << 1, ql, qr);
    if(tr[now << 1 | 1].l <= ql) return query(now << 1 | 1, ql, qr);
    int mid = (tr[now].l + tr[now].r) >> 1;
    int gl = query(now << 1, ql, mid);
    int gr = query(now << 1 | 1, mid + 1, qr);
    return __gcd(gl, gr);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
    return 0;
}