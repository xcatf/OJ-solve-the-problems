#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int s[maxn];
int main() {
    srand(time(0));
	freopen("data/D5.in","w",stdout);
    int n,m;
    n=rand()%9799+200;
    m=rand()%100+1;
    printf("%d\n%d\n",n,m);
    for(int i=1;i<=n;++i){
        s[i]=i;
    }
    for(int i=1;i<=n;++i){
        next_permutation(s+1,s+n+1);
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",s[i],i==n?'\n':' ');
    }
    putchar('\n');
	return 0;
}