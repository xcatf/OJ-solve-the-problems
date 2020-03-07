#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
static const double eps = 1e-4;
int sum[maxn];
bool check(int x){
    if(x % 7 == 0) return 1;
    while(x){
        if(x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}
int main(){
    for(int i = 1; i <= 100; ++i){
        sum[i] = sum[i - 1];
        if(!check(i)) sum[i] += i * i;
    }
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", sum[n]);
    }
}