#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int main(){
    // freopen("data/program0.in","r",stdin);
    // freopen("data/program0.out","w",stdout);
    char c[2];
    int n;
    while(~scanf("%d%s",&n,c)){
        int N=(n+1)>>1;
        for(int j=0;j<n;++j) putchar(c[0]);
        printf("\n");
        for(int i=1;i<N-1;++i){
            printf("%c",c[0]);
            for(int j=1;j<n-1;++j) putchar(' ');
            printf("%c\n",c[0]);
        }
        for(int j=0;j<n;++j) putchar(c[0]);
        printf("\n\n");
    }
    return 0;
}