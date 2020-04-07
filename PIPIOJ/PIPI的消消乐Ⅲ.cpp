#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5 + 5;
int main(){
    int n;
    scanf("%d",&n);
    bool f=0;
    for(int i=0;i<n;++i){
        int v;
        scanf("%d",&v);
        if(v&1) f=1;
    }
    puts(f?"PIPI":"POPO");
    return 0;
}