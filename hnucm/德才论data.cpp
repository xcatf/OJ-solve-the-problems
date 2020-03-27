#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s1[maxn];
int main(){
    srand((int)time(0));
    freopen("data/Morality6.in","w",stdout);
    int n=98765;
    int l=rand()%40+60;
    if(l>=90) --l;
    int r=max(1,rand()%(100-l))+l;
    printf("%d %d %d\n",n,l,r);
    int num=12345678;
    for(int i=0;i<n;++i){
        printf("%08d\n",num);
        ++num;
        int a,b;
        if(rand()%4==0) a=rand()%40+60,b=rand()%40+60;
        else rand()%100+1,rand()%100+1;
        printf("%d %d\n",a,b);
    }
    return 0;
}