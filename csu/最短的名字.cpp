#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=2e5+5;
struct Tree{
    int child[N][26],tot,cnt[N];
    int newnode(){
        for(int i=0;i<26;++i) child[tot][i]=-1;
        cnt[tot]=0;
        return tot++;
    }
    void init(){
        tot=0;
        newnode();
    }
    void build(char *s){
        int now=0;
        for(int i=0;s[i];++i){
            int x=s[i]-'a';
            if(child[now][x]==-1){
                int ne=newnode();
                child[now][x]=ne;
            }
            now=child[now][x];
            cnt[now]++;
        }
    }
    int search(int rt){
        int ans=0,now=rt;
        for(int i=0;i<26;++i){
            if(child[now][i]!=-1){
                int ne=child[now][i];
                ans+=cnt[ne];
                if(cnt[ne]>1) ans+=search(ne);
            }
        }
        return ans;
    }
}trie;
char s[1000005];
int main(){
    freopen("data/name6.in","r",stdin);
    freopen("data/name6.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        trie.init();
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s",s);
            trie.build(s);
        }
        printf("%d\n",trie.search(0));
    }
    return 0;
}