#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
int maxl[maxn], minl[maxn];
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    minl[1] = a[1];
    maxl[n] = a[n];
    for(int i = 2; i <= n; ++i) minl[i] = min(minl[i - 1], a[i]);
    for(int i = n - 1; i >= 1; --i) maxl[i] = max(maxl[i + 1], a[i]);
    int ans = 0;
    for(int i = 2; i <= n - 1; ++i){
        if(minl[i - 1] < a[i] && a[i] < maxl[i + 1]){
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
