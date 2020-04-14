#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
char s[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d%s",&n,s);
        int cnt=0,ans=0;
        for(int i=0;i<n;++i){
            if(cnt){
                ++ans;
                ++i;
                cnt=0;
            }
            else if(s[i]=='.') ++cnt;
        }
        if(cnt) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}