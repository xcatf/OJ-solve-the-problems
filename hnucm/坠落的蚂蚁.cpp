#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+5;
int dir[maxn];
int pos[2][maxn];
int main(){
    int n;
    scanf("%d",&n);
    int ip=0;
    for(int i=0;i<n;++i){
        int p,d;
        scanf("%d%d",&p,&d);
        dir[p]=d;
        if(d==0) ip=p;
    }
    int lcnt=0,rcnt=0;
    for(int i=1;i<=99;++i){
        if(i<ip&&dir[i]==1){
            pos[0][lcnt++]=i;
        }
        else if(i>ip&&dir[i]==-1){
            pos[1][rcnt++]=i;
        }
    }
    if(lcnt==rcnt) printf("Cannot fall!\n");
    else if(lcnt>rcnt) printf("%d\n",100-pos[0][lcnt-rcnt-1]);
    else printf("%d\n",pos[1][lcnt]);
    return 0;
}