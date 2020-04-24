#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e5+5;
char s[maxn];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    reverse(s,s+n);
    int pos=0;
    for(int i=0;i<n;++i){
        if(s[i]=='.'){
            reverse(s+pos,s+i);
            pos=i+1;
        }
        else if(i==n-1) reverse(s+pos,s+n);
    }
    printf("%s\n",s);
    return 0;
}