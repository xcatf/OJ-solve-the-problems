#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
int main(){
    int n;
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
    while(scanf("%d", &n) != EOF && n){
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i = 0; i < n; ++i){
            int val;
            scanf("%d", &val);
            pq.push(val);
        }
        int ans = 0;
        while(pq.size() > 1){
            int now1 = pq.top();
            pq.pop();
            int now2 = pq.top() + now1;
            pq.pop();
            ans += now2;
            pq.push(now2);
        }
        printf("%d\n", ans);
    }
    return 0;
}