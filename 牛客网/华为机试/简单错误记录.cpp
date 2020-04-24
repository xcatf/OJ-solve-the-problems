#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
struct node{
    char s[20];
    int cnt,row;
}q[1005];
char s[1005];
int main(){
    int x;
    int c=0;
    // freopen("data/record4.in","r",stdin);
    // freopen("data/record4.out","w",stdout);
    while(~scanf("%s%d",s,&x)){
        char *p=strrchr(s,'\\');
        ++p;
        if(strlen(p)>16) p+=strlen(p)-16;
        bool f=0;
        for(int i=0;i<c;++i){
            if(strcmp(q[i].s,p)==0&&x==q[i].row){
                q[i].cnt++;
                f=1;
                break;
            }
        }
        if(f) continue;
        q[c].row=x;
        strcpy(q[c].s,p);
        q[c++].cnt=1;
    }
    for(int i=max(0,c-8);i<c;++i) printf("%s %d %d\n",q[i].s,q[i].row,q[i].cnt);
    return 0;
}