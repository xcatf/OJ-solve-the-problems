#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
bool check(int x,int n){
    int ans=0;
    int now=1;
    while(x/10){
        ans=now*(x%10)+ans;
        now*=10;
        x/=10;
        if(ans==n) return true;
    }
    return false;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        puts(check(n*n,n)?"Yes!":"No!");
    }
    return 0;
}