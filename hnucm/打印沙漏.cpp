#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int findN(int x){
    int l=1,r=1000;
    int res=1;
    while(l<r){
        int mid=l+r>>1;
        if(2*mid*mid-1>x) r=mid;
        else{
            res=mid;
            l=mid+1;
        }
    }
    return res;
}
int main(){
    // freopen("data/hourglass6.in","r",stdin);
    // freopen("data/hourglass6.out","w",stdout);
    int n;
    char ch[2];
    scanf("%d%s",&n,ch);
    int N=findN(n);
    int M=(N<<1)-1;
    for(int i=N;i>=1;--i){
        int m1=(i<<1)-1;
        int m2=(M-m1)>>1;
        for(int j=0;j<m2;++j) putchar(' ');
        for(int j=0;j<m1;++j) putchar(ch[0]);
        putchar('\n');
    }
    for(int i=2;i<=N;++i){
        int m1=(i<<1)-1;
        int m2=(M-m1)>>1;
        for(int j=0;j<m2;++j) putchar(' ');
        for(int j=0;j<m1;++j) putchar(ch[0]);
        putchar('\n');
    }
    printf("%d\n",n-2*N*N+1);
    return 0;
}