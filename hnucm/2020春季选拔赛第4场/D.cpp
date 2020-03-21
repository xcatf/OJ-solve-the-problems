#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
int a[maxn];
int main(){
    int n;
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    while(scanf("%d", &n) != EOF){
        int max_p = 0, min_p = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            if(a[i] > a[max_p]) max_p = i;
            if(a[i] < a[min_p]) min_p = i;
        }
        swap(a[max_p], a[min_p]);
        for(int i = 0; i < n; ++i) printf("%d%c", a[i], i == n -1 ? '\n' : ' ');
    }
    return 0;
}