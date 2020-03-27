#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int cnt1[3],cnt2[3];
int main(){
    // freopen("data/hammer6.in","r",stdin);
    // freopen("data/hammer6.out","w",stdout);
    int n;
    scanf("%d",&n);
    char c1[2],c2[2];
    for(int i=0;i<n;++i){
        scanf("%s%s",c1,c2);
        if(c1[0]==c2[0]) continue;
        if(c1[0]=='B'&&c2[0]=='C') cnt1[0]++;
        else if(c1[0]=='C'&&c2[0]=='J') cnt1[1]++;
        else if(c1[0]=='J'&&c2[0]=='B') cnt1[2]++;
        else if(c2[0]=='B') cnt2[0]++;
        else if(c2[0]=='C') cnt2[1]++;
        else cnt2[2]++;
    }
    int w1=0,w2=0,m1=0,m2=0;
    for(int i=0;i<3;++i){
        w1+=cnt1[i];
        if(cnt1[m1]<cnt1[i]) m1=i;
    }
    for(int i=0;i<3;++i){
        w2+=cnt2[i];
        if(cnt2[m2]<cnt2[i]) m2=i;
    }
    int t=n-w1-w2;
    printf("%d %d %d\n%d %d %d\n",w1,t,w2,w2,t,w1);
    printf("%c %c\n",m1==0?'B':m1==1?'C':'J',m2==0?'B':m2==1?'C':'J');
    return 0;
}