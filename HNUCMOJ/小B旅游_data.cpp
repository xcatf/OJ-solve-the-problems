#include <bits/stdc++.h>
using namespace std;
int main(){
    srand((int)time(0));
    freopen("C4.in","w",stdout);
    int n=rand()%10000+1, m=rand()%500000+1;
    int p=rand()%10000+1;
    printf("%d %d %d\n",n,m,p);
    for(int i=0;i<m;++i){
        int u=rand()%n+1;
        int v=rand()%n+1;
        printf("%d %d\n",u,v);
    }
    return 0;
}