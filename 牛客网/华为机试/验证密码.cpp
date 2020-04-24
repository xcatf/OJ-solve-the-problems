#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
char s[N];
bool check(int p){
    for(int i=0;i<p-2;++i){
        if(s[i]==s[p]&&s[i+1]==s[p+1]&&s[i+2]==s[p+2]) return true;
    }
    return false;
}
int main(){
    // freopen("data/pwd4.in","r",stdin);
    // freopen("data/pwd4.out","w",stdout);
    while(~scanf("%s",s)){
        int n=strlen(s);
        if(n<=8){
            printf("NG\n");
            continue;
        }
        bool f=1;
        int c1=0,c2=0,c3=0,c4=0;
        for(int i=0;i<n;++i){
            if(i+2<n&&i>2){
                if(check(i)){
                    f=0;
                    break;
                }
            }
            if(s[i]>='a'&&s[i]<='z') c1=1;
            else if(s[i]>='A'&&s[i]<='Z') c2=1;
            else if(isdigit(s[i])) c3=1;
            else c4=1;
        }
        if(f&&c1+c2+c3+c4>=3) printf("OK\n");
        else printf("NG\n");
    }
    return 0;
}