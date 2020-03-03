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
    int a, b, x, y;
    while(scanf("%d%d", &a, &b) != EOF){
        if(__gcd(a, b) != 1) puts("sorry");
        else{
            ex_gcd(a, b, x, y);
            while(x < 0){
                x += b;
                y -= a;
            }
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}