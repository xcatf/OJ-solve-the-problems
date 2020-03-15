#include <bits/stdc++.h>
int ans = 0;
char s[20];
void dfs(int cnt1, int cnt2, int val, int idx){
    if(cnt1 > 5 || cnt2 > 10) return ;
    if(idx == 15 && val == 0){
        ++ans;
        s[idx] = '\0';
        printf("%s\n", s);
        return ;
    }
    if(val <= 0) return;
    s[idx] = 'a';
    dfs(cnt1 + 1, cnt2, val * 2, idx + 1);
    s[idx] = 'b';
    dfs(cnt1, cnt2 + 1, val - 1, idx + 1);

}
int main(){
    dfs(0, 0, 2, 0);
    printf("%d\n", ans);
    return 0;
}
/*
answer: 14
author: xcatf
*/