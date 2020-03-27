#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s1[maxn];
int main(){
    srand((int)time(0));
    freopen("data/cake5.in","w",stdout);
    int n=1000;
    int d=rand()%500+1;
    printf("%d %d\n",n,d);
    for(int i=1;i<=n;++i) printf("%.1f%c",0.5*(rand()%1000+1),i==n?'\n':' ');
    for(int i=1;i<=n;++i) printf("%.1f%c",0.5*(rand()%1000+1),i==n?'\n':' ');
    return 0;
}