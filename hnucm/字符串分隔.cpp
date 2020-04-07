#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
char s[maxn];
int main(){
    // freopen("data/delimited3.in","r",stdin);
    // freopen("data/delimited3.out","w",stdout);
    for(int t=0;t<2;++t){
        gets(s);
        getchar();
        int le=strlen(s);
        for(int i=0;i<le;i+=8){
            for(int j=i;j<=i+7&&j<le;++j) putchar(s[j]);
            if(i+8<le) putchar('\n');
        }
        if(le%8){
            for(int i=0;i<8-(le%8);++i) putchar('0');
        }
        putchar('\n');
    }
    return 0;
}