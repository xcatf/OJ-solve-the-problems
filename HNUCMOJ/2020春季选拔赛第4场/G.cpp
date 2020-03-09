#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 35;
char s1[maxn], s2[maxn];
ll cnt[maxn];
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    cnt[n] = 1;
    for(int i = n - 1; i >= 1; --i) cnt[i] = cnt[i + 1] << 1;
    int now = 1;
    while(now <= n && s1[now] == s2[now]) now++;
    if(now > n){
        puts("0");
        return 0;
    }
    ll ans1 = 1;
    for(int i = now + 1; i <= n; ++i){
        if(s1[i] != s2[now]) ans1 += cnt[i];
        if(s2[i] != s1[now]) ans1 += cnt[i]; 
    }
    char ch;
    if(s1[now] != 'T' && s2[now] != 'T') ch = 'T';
    else if(s1[now] != 'L' && s2[now] != 'L') ch = 'L';
    else ch = 'R';
    ll ans2 = cnt[now] + 1;
    for(int i = now + 1; i <= n; ++i){
        if(s1[i] != ch) ans2 += cnt[i];
        if(s2[i] != ch) ans2 += cnt[i];
    }
    printf("%lld\n", min(ans1, ans2));
    return 0;
}