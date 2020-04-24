#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const int mod=1e9+3;
int main(){
    int n;
    scanf("%d",&n);
    if(n==1) printf("1\n1\n");
    else if(n==2) printf("2\n1\n00\n");
    else{
        printf("%d\n",n-1);
        for(int i=2;i<=n;++i){
            printf("0");
            for(int j=0;j<i-2;++j) printf("1");
            printf("0\n");
        }
    }
    return 0;
}