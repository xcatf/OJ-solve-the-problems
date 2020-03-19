#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int main() {
    srand(time(0));
	freopen("data/B1.in","w",stdout);
    int n=20,m=20,k=rand()%1000;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(rand()%2==1){
                printf("%d%c",rand()%500,(j==m)?'\n':' ');
            }else{
                printf("0%c",(j==m)?'\n':' ');
            }
        }
    }
	return 0;
}