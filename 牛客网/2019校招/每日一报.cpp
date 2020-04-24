#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+5;
const int mod=1e9+3;
struct node{
    int d,id;
    double t;
    bool operator<(const node&r)const{
        if(d!=r.d) return d>r.d;
        if(t!=r.t) return t>r.t;
        return id<r.id;
    }
}q[maxn];
int main(){
    int n;
    scanf("%d",&n);
    int c=0;
    for(int i=0;i<n;++i){
        int d,id;
        double t;
        scanf("%d%d%lf",&d,&id,&t);
        if(t>=38.0){
            q[c].d=d;q[c].id=id;q[c].t=t;
            ++c;
        }
    }
    sort(q,q+c);
    printf("%d\n",c);
    for(int i=0;i<c;++i) printf("%d %d %.1f\n",q[i].d,q[i].id,q[i].t);
    return 0;
}