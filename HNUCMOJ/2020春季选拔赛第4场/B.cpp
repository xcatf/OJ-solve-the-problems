#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
int place(int m, int n){
    if(m == 0) return 1;
    if(n == 1) return 1;
    if(m >= n) return  place(m, n - 1) + place(m - n, n);
    return place(m, m);
}
int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF){
        printf("%d\n", place(m, n));
    }
    return 0;
}