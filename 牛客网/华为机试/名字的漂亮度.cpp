#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
char s[N];
int main(){
    int n;
    // freopen("data/beauty2.in","r",stdin);
    // freopen("data/beauty2.out","w",stdout);
    while(~scanf("%d",&n)){
         for(int k=1;k<=n;++k){
            scanf("%s",s);
            int c[26]={0};
            int tot=1,le=strlen(s);
            for(int i=0;i<le;++i){
                s[i]=tolower(s[i]);
                c[s[i]-'a']++;
            }
            sort(c,c+26,greater<int>());
            ll ans=0;        
            for(int i=0;i<26;++i) ans+=(26-i)*c[i];
            printf("%lld\n",ans);
        }
    }
    return 0;
}