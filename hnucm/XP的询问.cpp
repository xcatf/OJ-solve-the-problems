#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],n,t,v;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i) scanf("%d%d",&a[i],&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        scanf("%d",&t);
        while(t--){
            scanf("%d",&v);
            int l=upper_bound(a,a+n,v)-a;
            int r=lower_bound(b,b+n,v)-b;
            printf("%d\n",l-r);
        }
        printf("\n");
    }
    return 0;
}