#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 5e6;
ll n;
bool f(ll x, bool fg)
{

    if (x < 2) return !fg;
    if (x == 3 || x == 2) return fg;
    if (x % 2 == 0) return f(x / 2, !fg);
    return f(x / 2, !fg) | f(x - x / 2, !fg);
}
int main()
{
    scanf("%lld", &n);
    puts(f(n, 1) ? "PIPI" : "POPO");
    return 0;
}