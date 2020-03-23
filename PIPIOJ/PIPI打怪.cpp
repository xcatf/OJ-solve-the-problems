#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
int a[maxn];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=(int)ceil(a[0]/2.0);
        int now=ans+1;
        int i=1;
        while(i<n){
            bool f=0;
            for(;i<n&&a[i]<=now*2;++i,f=1);
            if(i>=n) break;
            int d=(int)ceil(a[i]/2.0)-now;
            ans+=d;
            now+=d;
            if(f) --ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}