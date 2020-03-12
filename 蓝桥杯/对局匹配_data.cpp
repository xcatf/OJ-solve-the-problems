#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    srand((int)time(0));
    freopen("test.in", "w", stdout);
    for(int t = 0; t < 10; ++t){
        int n = rand() % 10 + 1;
        int k = rand() % 10 + 1;
        printf("%d %d\n", n, k);
        for(int i = 1; i <= n; ++i){
            printf("%d%c", rand() % 20 + 1, i == n ? '\n' : ' ');
        }
    }
}