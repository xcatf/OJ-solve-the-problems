#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
struct node{
    int d1,d2;
    bool operator<(const node&rhs)const{
        return d2>rhs.d2;
    }
}q1[maxn];
int q2[maxn];
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    int c1=0,c2=0;
    int ans=0;
    for(int i=0;i<n;++i){
        int d1,d2;
        scanf("%d%d",&d1,&d2);
        if(d1>=d){
            ++ans;
            continue;
        }
        if(d1+d2<d) q2[c2++]=d1;
        else{
            q1[c1].d1=d1;
            q1[c1].d2=d2;
            ++c1;
        }
    }
    sort(q1,q1+c1);
    sort(q2,q2+c2);
    int i=0,j=0;
    while(i<c1&&j<c2){
        if(min(q1[i].d1,q2[j])+q1[i].d2>=d){
            ++ans;
            ++i;
        }
        ++j;
    }
    j=c1-1;
    q2[0]=-1;
    while(i<=j){
        if(q2[0]==-1){
            q2[0]=q1[j--].d1;
        }
        else{
            if(min(q1[i].d1,q2[0])+q1[i].d2>=d){
                ++ans;
                ++i;
            }
            q2[0]=-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}