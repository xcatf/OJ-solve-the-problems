#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
static const double eps = 1e-4;
int main()
{
    //freopen("E.in", "r", stdin);
    //freopen("E2.out", "w", stdout);
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n & 1){
            puts("0 0");
            continue;
        }
        int x, y;
        y = n / 4;
        x = (n - y * 4) / 2;
        printf("%d ", x + y);
        x = n / 2;
        y = (n - x * 2) / 4;
        printf("%d\n", x + y);
    }
    return 0;
}