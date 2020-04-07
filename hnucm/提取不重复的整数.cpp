#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
bool v[10];
int main(){
    char s[12];
    while(~scanf("%s",s)){
        int le=strlen(s);
        memset(v,0,sizeof(v));
        bool f=0;
        for(int i=le-1;i>=0;--i){
            if(!f&&s[i]=='0'){
                v[0]=1;
                continue;
            }
            if(!v[s[i]-'0']){
                putchar(s[i]);
                f=1;
                v[s[i]-'0']=1;
            }
        }
        if(!f) putchar('0');
        putchar('\n');
    }
    return 0;
}