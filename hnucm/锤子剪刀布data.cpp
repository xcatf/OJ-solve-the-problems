#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s[]={'B','C','J'};
int main(){
    srand((int)time(0));
    freopen("data/hammer6.in","w",stdout);
    int n=10;
    printf("%d\n",n);
    for(int i=0;i<n;++i){
        int p1=rand()%3;
        int p2=rand()%3;
        printf("%c %c\n",s[p1],s[p2]);
    }
    return 0;
}