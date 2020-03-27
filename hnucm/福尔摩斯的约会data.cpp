#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s1[maxn];
int main(){
    srand((int)time(0));
    freopen("data/appointment0.in","w",stdout);
    for(int t=0;t<4;++t){
        for(int i=0;i<60;++i){
            int r=rand()%4;
            if(r==0) printf("%c",rand()%26+'A');
            else if(r==1) printf("%c",rand()%26+'a');
            else if(r==2) printf("&");
            else printf("%c",rand()%10+'0');
        }
        putchar('\n');
    }
    return 0;
}