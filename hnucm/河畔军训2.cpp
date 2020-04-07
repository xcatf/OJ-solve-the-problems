#include <bits/stdc++.h>
#define x first
#define y second
#define mk make_pair
#define PII pair<int,int>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;

char mp[maxn][maxn];
set<PII>s[3];
queue<PII>Q[3];
int n,m;
int d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int cnt[3]={4,4,8};
bool bfs(int id){
    int sz=Q[id].size();
    while(sz--){
        PII u=Q[id].front();
        Q[id].pop();
        for(int i=0;i<cnt[id];++i){
            PII v;
            v.x=u.x+d[i][0];
            v.y=u.y+d[i][1];
            if(v.x>=0&&v.x<n&&v.y>=0&&v.y<m&&mp[v.x][v.y]!='#'&&!s[id].count(v)){
                s[id].emplace(v);
                Q[id].emplace(v);
                if(s[0].count(v)&&s[1].count(v)&&s[2].count(v)) return true;
            } 
        }
    }
    return false;
}
int solve(){
    int r=0;
    while(!Q[0].empty()||!Q[1].empty()||!Q[2].empty()){
        ++r;
        if(bfs(0)) return r;
        if(bfs(1)) return r;
        for(int i=0;i<3;++i){
            if(bfs(2)) return r;
        }
    }

    return -1;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<3;++i){
            s[i].clear();
            while(!Q[i].empty()) Q[i].pop();
        }
        for(int i=0;i<n;++i) scanf("%s",mp[i]);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mp[i][j]=='z') Q[0].emplace(mk(i,j)),s[0].emplace(mk(i,j));
                if(mp[i][j]=='y') Q[1].emplace(mk(i,j)),s[1].emplace(mk(i,j));
                if(mp[i][j]=='h') Q[2].emplace(mk(i,j)),s[2].emplace(mk(i,j));
            }
        }
        int ans=solve();
        if(ans==-1) printf("lack of junxun\n");
        else printf("%d\n",ans);
    }
    return 0;
}