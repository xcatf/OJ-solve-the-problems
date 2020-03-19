#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e6 + 5;
int n, a[maxn], b[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    int ans = n;
    int i = 0, pos = 0;
    while(pos < n){
        pos = find(b + pos, b + n, a[i]) - b;
        while(i < n && pos < n && a[i] == b[pos]){
            --ans;
            ++i;
            ++pos;
        }
    }
    printf("%d\n", ans);
    return 0;
}