#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ex_gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a / b * x;
    return r;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, B, x, y;
        scanf("%d%d", &n, &B);
        ex_gcd(9973, B, x, y);
        y = y * n;
        while(y < 0) y += 9973;
        printf("%d\n", y % 9973);
    }
    return 0;
}