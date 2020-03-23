#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
char s[10][5]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}; 
bool f;
void solve(int n){
    if(n){
        solve(n/10);
        if(f) putchar(' '); 
        printf("%s",s[n%10]);
        f=1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==0) puts(s[0]);
    else{
        f=0;
        if(n<0){
            printf("fu");
            f=1;
        }
        solve(abs(n));
    }
    return 0;
}