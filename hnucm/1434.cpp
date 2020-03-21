#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
static const double eps = 1e-4;
int a[maxn];
int find_Knum(int l, int r, int k){
    srand((int)time(0));
    int pos = rand() % (r - l + 1) + l;
    swap(a[pos], a[l]);
    int i = l, j = l + 1;
    for(; j <= r; ++j){
        if(a[j] > a[l]){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[i]);
    int len = i - l + 1;
    if(len == k) return a[i];
    else if(len < k) return find_Knum(i + 1, r, k - len);
    else return find_Knum(l, i - 1, k);
}
int main()
{
    int n, k;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        scanf("%d", &k);
        printf("%d\n", find_Knum(0, n - 1, k));
    }
    return 0;
}