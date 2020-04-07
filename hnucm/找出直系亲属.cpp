#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
static const double eps = 1e-4;
unordered_map<char,char>ne;
int dfs(char now,char tr,int h){
    if(now==tr) return h;
    if(isalpha(ne[now])) return dfs(ne[now],tr,h+1);
    return -1;
}
int main(){
    freopen("data/family3.in","r",stdin);
    freopen("data/family3.out","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        char s[5];
        ne.clear();
        for(int i=0;i<n;++i){
            scanf("%s",s);
            if(s[1]!='-') ne[s[1]]=s[0];
            if(s[2]!='-') ne[s[2]]=s[0];
        }
        while(m--){
            scanf("%s",s);
            int r=dfs(s[1],s[0],0);
            if(r!=-1){
                for(int i=3;i<=r;++i) printf("great-");
                if(r>=2) printf("grand");
                printf("child\n");
                continue;
            }
            r=dfs(s[0],s[1],0);
            if(r!=-1){
                for(int i=3;i<=r;++i) printf("great-");
                if(r>=2) printf("grand");
                printf("parent\n");
                continue;
            }
            printf("-\n");
        }
    }
    return 0;
}