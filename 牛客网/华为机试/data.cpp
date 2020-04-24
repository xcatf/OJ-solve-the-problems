#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
char s[]={'W','S','A','D','Q','R','$','&','^','%'};
int main(){
    freopen("data/coordinate3.in","w",stdout);
    for(int t=1;t<=1000;++t){
        printf("%c%d",s[rand()%6],rand()%100);
        int n=rand()%1000+1;
        for(int j=1;j<=n;++j){
            printf(";%c%d",s[rand()%4],rand()%200+1);
        }
        printf("\n");
    }
    return 0;
}