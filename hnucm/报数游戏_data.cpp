#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
int main(){
    srand((int)time(0));
    freopen("E4.in","w",stdout);
    int t=5;
    printf("%d\n",t);
    while(t--){
        int n=rand()%10000+1;
        int m=rand()%10000+1;
        printf("%d %d\n",n,m);
    }
    return 0;
}