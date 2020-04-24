#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
char s[N];
int get_pos(int now){
    for(int i=now;s[i];++i){
        if(s[i]==';') return i;
    }
    return -1;
}
int main(){
    // freopen("data/coordinate3.in","r",stdin);
    // freopen("data/coordinate3.out","w",stdout);
    while(~scanf("%s",s)){
        int x=0,y=0;
        int n=strlen(s);
        for(int i=0;i<n;++i){
            int p=get_pos(i);
            if(p-i==3){
                if(isdigit(s[i+1])&&isdigit(s[i+2])){
                    int cnt=(s[i+1]-'0')*10+s[i+2]-'0';
                    if(s[i]=='A') x-=cnt;
                    else if(s[i]=='D') x+=cnt;
                    else if(s[i]=='W') y+=cnt;
                    else if(s[i]=='S') y-=cnt;
                }
            }
            else if(p-i==2){
                 if(isdigit(s[i+1])){
                    int cnt=s[i+1]-'0';
                    if(s[i]=='A') x-=cnt;
                    else if(s[i]=='D') x+=cnt;
                    else if(s[i]=='W') y+=cnt;
                    else if(s[i]=='S') y-=cnt;
                }
            }
            if(p!=-1) i=p;
        }
        printf("%d,%d\n",x,y);
    }
    return 0;
}