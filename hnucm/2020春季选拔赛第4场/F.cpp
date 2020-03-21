#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char a[maxn], b[10];
int getlen(int l){
    int res = 1;
    for(int i = l + 1; a[i]; ++i){
        if(a[i] == a[i - 1]) ++res;
        else break;
    }
    return res;
}
int main(){
    freopen("F.in", "r", stdin);
    freopen("F.out", "w", stdout);
    while(scanf("%s", a) != EOF){
        scanf("%s", b);
        int len = strlen(b);
        if(len == 5){
            if(b[0] == '5'){
                puts("NO");
                continue;
            }
            else{
                char sc = b[0];
                int cnt = 0;
                for(int i = 0; a[i]; ++i){
                    if(a[i] == sc + 1){
                        sc++;
                        cnt++;
                        if(cnt == 5) break;
                    }
                }
                if(cnt == 5) puts("YES");
                else puts("NO");
            }
        }
        else{
            bool f = 0;
            for(int i = 0; a[i]; ){
                int now_len = 1;
                if(a[i] > b[0]){
                    now_len = getlen(i);
                    if(now_len >= len){
                        f = 1;
                        break;
                    }
                }
                i += now_len;
            }
            puts(f ? "YES" : "NO");
        }
    }
    return 0;
}