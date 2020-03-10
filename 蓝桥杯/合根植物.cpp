#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e6 + 5;
typedef long long ll;
int p[maxn];
int find_set(int x){
    if(p[x] != x){
        p[x] = find_set(p[x]);
    }
    return p[x];
}
void union_set(int x, int y){
    int fx = find_set(x);
    int fy = find_set(y);
    if(fx != fy) p[fx] = p[fy];
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    n *= m;
    for(int i = 1; i <= n; ++i) p[i] = i;
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        union_set(a, b);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(p[i] == i) ans++;
    }
    printf("%d\n", ans);
}