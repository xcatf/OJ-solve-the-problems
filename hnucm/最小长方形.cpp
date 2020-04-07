#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int x,y;
    while(~scanf("%d%d",&x,&y)&&(x||y)){
        int mx=x,my=y,Mx=x,My=y;
        while(~scanf("%d%d",&x,&y)&&(x||y)){
            mx=min(mx,x);
            my=min(my,y);
            Mx=max(Mx,x);
            My=max(My,y);
        }
        printf("%d %d %d %d\n",mx,my,Mx,My);
    }
    return 0;
}