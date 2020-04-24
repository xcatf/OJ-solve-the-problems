#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    srand((int)time(0));
    freopen("data/numpairs10.in","w",stdout);
    for(int t=1;t<=1;++t){
        int n=rand()%10000+1;
        printf("%d %d\n",n,rand()%n);
    }
    return 0;
}