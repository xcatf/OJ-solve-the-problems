#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
static const double eps = 1e-4;
int a[maxn];
int partition(int l, int r){
    srand((int)time(0));
    int pos = rand() % (r - l + 1) + l;
    swap(a[l], a[pos]);
    int i = l, j = i + 1;
    for(; j <= r; ++j){
        if(a[j] < a[l]){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[i]);
    return i;
}
void quick_sort(int l, int r){
    if(l < r){
        int pos = partition(l, r);
        quick_sort(l, pos - 1);
        quick_sort(pos + 1, r);
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        quick_sort(0, n - 1);
        for(int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}