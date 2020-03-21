#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
static const ll mod = 998244353;
int h[maxn], sum[maxn];
int a[maxn], b[maxn];
int main() {    
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &h[i]);
    sort(h + 1, h + n + 1);
    for(int i = 1; i <= m; ++i) scanf("%d%d", &a[i], &b[i]);
    int p = upper_bound(h + 1, h + n + 1, a[1]) - h;
    sum[1]++;
    sum[p]--;
    for(int i = 2; i <= m; ++i){
         int p1 = upper_bound(h + 1, h + n + 1, a[i]) - h - 1;
         int p2 = upper_bound(h + 1, h + n + 1, b[i - 1]) - h;
         if(p2 <= p1){
             sum[p2]++;
             sum[p1 + 1]--;
         }
     }
     for(int i = 1; i <= n; ++i){
         sum[i] += sum[i - 1];
     }
     int res = 0;
     for(int i = 1; i <= n; ++i){
         if(sum[i] >= k) ++res;
     }
     printf("%d\n", res);
    return 0;
}