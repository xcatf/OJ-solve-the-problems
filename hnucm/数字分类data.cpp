#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s1[maxn];
int main(){
    srand((int)time(0));
    freopen("data/digital5.in","w",stdout);
    int n=rand()%5+1;
    printf("%d",n);
    for(int i=1;i<=n;++i){
        printf(" %d",rand()%10000);
    }
    return 0;
}