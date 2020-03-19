#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int main() {
    srand(time(0));
	freopen("data/C5.in","w",stdout);
    int n=rand()%11;
    printf("%d\n",n);
    n=pow(2,n);
    for(int i=1;i<=n;++i){
        printf("%d",rand()%2);
    }
	return 0;
}