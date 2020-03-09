#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
bool used[maxn];
int mp[maxn];
int main(){
    int num, hh, mm;
    char op[2];
    freopen("C3.in", "r", stdin);
    freopen("C3.out", "w", stdout);
    int time = 0, cnt = 0;
    while(scanf("%d", &num) && num != -1){
        scanf("%s%d:%d", op, &hh, &mm);
        if(num == 0){
            int avg;
            avg = (int)ceil(1.0* time / max(1, cnt));
            printf("%d %d\n", cnt, avg);
            cnt = 0;
            time = 0;
            memset(mp, 0, sizeof(mp));
            memset(used, 0, sizeof(used));
            continue;
        }
        int now = hh * 60 + mm;
        if(now < mp[num]) continue;
        if(used[num]){
            if(op[0] == 'S') continue;
            time += now - mp[num];
            cnt++;
            mp[num] = now;
            used[num] = 0;
        }
        else{
            if(op[0] == 'E') continue;
            mp[num] = now;
            used[num] = 1;
        }
    }
    return 0;
}