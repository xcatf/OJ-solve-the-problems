#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int n,m;
int ysf(int n,int p){
    if(p==0) return 0;
    int x=m+p-1;
    return 1+ysf(n-1,x%(n-1));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",ysf(n,(m-1)%n));
    }
    return 0;
}