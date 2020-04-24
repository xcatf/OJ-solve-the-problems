#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=1e9+3;
int a[4];
int main(){
    for(int i=0;i<4;++i) scanf("%d",&a[i]);
    sort(a,a+4);
    printf("%d\n",abs(a[0]+a[3]-a[1]-a[2]));
    return 0;
}