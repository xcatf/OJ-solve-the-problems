#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
struct node{
    char num[10];
    int a,b,s,id;
    bool operator<(const node&rhs)const{
        if(id!=rhs.id) return id<rhs.id;
        if(s!=rhs.s) return s>rhs.s;
        if(a!=rhs.a) return a>rhs.a;
        return strcmp(num,rhs.num)<0;
    }
}ans[maxn];
int main(){
    // freopen("data/Morality6.in","r",stdin);
    // freopen("data/Morality6.out","w",stdout);
    int n,l,h;
    scanf("%d%d%d",&n,&l,&h);
    int cnt=0;
    for(int i=0;i<n;++i){
        char s1[10];
        int a,b;
        scanf("%s%d%d",s1,&a,&b);
        if(a>=l&&b>=l){
            ans[cnt].a=a;
            ans[cnt].b=b;
            strcpy(ans[cnt].num,s1);
            ans[cnt].s=a+b;
            if(a>=h&&b>=h) ans[cnt].id=1;
            else if(a>=h&&b<h) ans[cnt].id=2;
            else if(a<h&&b<h&&a>=b) ans[cnt].id=3;
            else ans[cnt].id=4;
            ++cnt;
        }
    }
    sort(ans,ans+cnt);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i){
        printf("%s %d %d\n",ans[i].num,ans[i].a,ans[i].b);
    }
    return 0;
}