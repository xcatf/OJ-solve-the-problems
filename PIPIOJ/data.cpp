#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    srand((int)time(0));
    freopen("data/in0.in","w",stdout);
    for(int t=1;t<=10;++t){
        int n=rand()%10000+1;
        int m=rand()%10000;
        printf("%d %d\n",n,m);
        for(int i=0;i<m;++i){
            printf("%d %d\n",rand()%n+1,rand()%n+1);
        }
    }
    return 0;
}