#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
char s[maxn];
char d[4]={'N','W','S','E'};
int main(){
    int n;
    scanf("%d%s",&n,s);
    int cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            if(cnt==3) cnt=0;
            else ++cnt;
        }
        else{
            if(cnt==0) cnt=3;
            else --cnt;
        }
    }
    printf("%c\n",d[cnt]);
    return 0;
}