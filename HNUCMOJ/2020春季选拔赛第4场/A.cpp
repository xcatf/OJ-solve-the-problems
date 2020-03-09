#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
struct node{
    int weight;
    char color[15];
    bool operator < (const node &rhs)const{
        return weight > rhs.weight;
    }
}a[maxn];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i) scanf("%d%s", &a[i].weight, a[i].color);
        sort(a, a + n);
        for(int i = 0; i < n; ++i) printf("%s\n", a[i].color);
    }
    return 0;
}