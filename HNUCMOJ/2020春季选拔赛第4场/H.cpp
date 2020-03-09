#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
int tr[8200];
char s[maxn];
int n;
int dfs(int state, int now){
    if(now * 2 >= n){
        if(state == 0) return 0;
        if(tr[now] == 0) return 1;
        return 2;
    }
    if(state == 1){
        if(tr[now] == 0) return min(dfs(1, now << 1), dfs(1, now << 1 | 1));
        return dfs(1, now << 1) + dfs(1, now << 1 | 1);
    }
    return 0;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", s);
        for(int i = 1; i < n; ++i) scanf("%d", &tr[i]);
        int len = strlen(s);
        int id = 0;
        s[len] = '0';
        while(id < len && s[id] == '0') ++id;
        int ans = dfs(s[id] - '0', 1);
        for(int i = id + 1; i < len; ++i){
            if(s[i] != s[i - 1]) ++ans;
        } 
        printf("%d\n", ans);
    }
    return 0;
}