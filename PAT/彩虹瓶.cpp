#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
        int x=1,v;
        stack<int>st;
        bool fg=0;
        for(int i=0;i<n;++i){
            scanf("%d",&v);
            if(fg) continue;
            if(st.size()>m){
                fg=1;
                continue;
            }
            if(v==x) ++x;
            else st.emplace(v);
            while(!st.empty()&&st.top()==x){
                st.pop();
                ++x;
            }
        }
        --x;
        puts(x==n?"YES":"NO");
    }
    return 0;
}