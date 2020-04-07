#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod=7777777;
const int maxn=1e4+5;
int a[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    while(m--){
        next_permutation(a,a+n);
    }
    for(int i=0;i<n;++i) printf("%d%c",a[i],i==n-1?'\n':' ');
    return 0;
}