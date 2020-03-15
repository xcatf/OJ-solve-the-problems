#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
typedef long long ll;
int n;
int ans;
void solve(int now, int add){
    if(now > n) return ;
    if(now) ++ans;
    for(int i = add; i < 10; ++i){
        solve(now * 10 + i, i);
    }
}
int main()
{
    scanf("%d", &n);
    ans = 0;
    solve(0, 1);
    printf("%d\n", ans);
    return 0;
}