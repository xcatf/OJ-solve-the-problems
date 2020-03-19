#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int main() {
    srand(time(0));
	freopen("data/A4.in","w",stdout);
    for(int i=1;i<=7;++i){
        printf("%d%d\n",rand()%8,rand()%8);
    }
	return 0;
}