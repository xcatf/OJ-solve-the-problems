#include <bits/stdc++.h>
using namespace std;
static const int maxn = 55;
int n, init_pos;
int main(){
    scanf("%d", &n);
    scanf("%d", &init_pos);
    int ans = 1;
    bool fg = 0;
    for(int i = 1; i < n; ++i){
        int p;
        scanf("%d", &p);
        if(p * init_pos > 0){
            if(p < init_pos) ++ans;
        }
        else{
            if(init_pos > 0 && abs(p) > init_pos){
                ++ans;
                fg = 1;
            }
            if(init_pos < 0 && p < abs(init_pos)){
                ++ans;
                fg = 1;
            }
        }
    }
    if(fg) printf("%d\n", ans);
    else printf("1\n");
    return 0;
}