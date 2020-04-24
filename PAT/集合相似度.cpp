#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
set<int>s[55];
int main(){
    int n,m,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j){
            scanf("%d",&x);
            s[i].insert(x);
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        int b=s[x].size()+s[y].size(),a=0;
        for(auto it=s[x].begin();it!=s[x].end();++it){
            if(s[y].count(*it)) ++a;
        }
        printf("%.2f%%\n",1.0*a/(b-a)*100);
    }
    return 0;
}