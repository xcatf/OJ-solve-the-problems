#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
char s[maxn];
int main(){
    while(~scanf("%s",s)){
        bool f=1;
        int cnt=0;
        for(int i=0;s[i];++i){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') ++cnt;
            else{
                if(cnt) --cnt;
                else{
                    f=0;
                    break;
                }   
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}