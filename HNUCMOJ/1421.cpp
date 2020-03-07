#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
static const double eps = 1e-4;
int a[maxn], b[maxn];
void merge(int l, int r){
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    int cnt = l;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) b[cnt++] = a[i++];
        else b[cnt++] = a[j++];
    }
    while(i <= mid) b[cnt++] = a[i++];
    while(j <= r) b[cnt++] = a[j++];
}
void merge_copy(int l, int r){
    for(int i = l; i <= r; ++i){
        a[i] = b[i];
    }
}
void merge_sort(int l, int r){
    if(l < r){
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, r);
        merge_copy(l, r);
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        merge_sort(0, n - 1);
        for(int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}