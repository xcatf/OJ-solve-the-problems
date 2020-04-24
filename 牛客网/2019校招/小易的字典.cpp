#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
char s[205];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int c=0;
    while(n&&m){
        ll r=1;
        for(int i=1;i<n;++i){
            r*=n+m-i;
            r/=i;
            if(r>k) break;
        }
        if(k<=r){
            s[c++]='a';
            --n;
        }
        else{
            s[c++]='z';
            k-=r;
            --m;
        }
    }
    if(k!=1){
        printf("-1\n");
        return 0;
    }
    while(n--) s[c++]='a';
    while(m--) s[c++]='z';
    s[c]=0;
    printf("%s\n",s);
    return 0;
}