#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e5 + 5;
int cnt[maxn];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int R = 0;
    for(int i = 0; i < n; ++i){
        int v;
        scanf("%d", &v);
        cnt[v]++;
        R = max(R, v);
    }
    int now = 0;
    for(int i = 0; i + k <= R; ++i){
        if(k && cnt[i] && cnt[i + k]){
            now += min(cnt[i], cnt[i + k]);
            cnt[i + k] = max(0, cnt[i + k] - cnt[i]); 
        }
        else if(!k && cnt[i]){
            now += cnt[i] - 1;
        }
    }
    printf("%d\n", n - now);
    return 0;
}