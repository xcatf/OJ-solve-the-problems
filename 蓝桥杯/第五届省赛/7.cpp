#include <bits/stdc++.h>
using namespace std;
int val[13];
bool used[13];
int ind[6][4] = {
    {10,3,5,11},
    {10,2,9,12},
    {1,2,3,4},
    {1,9,8,7},
    {4,5,6,7},
    {11,6,8,12}
};
int getval(int id){
    int res = 0;
    for(int j = 0; j < 4; ++j) res += val[ind[id][j]];
    return res;
}
bool check(){
    int pre = getval(0);
    for(int i = 1; i <  6; ++i){
        int now = getval(i);
        if(now != pre) return false;
    }
    return true;
}
bool fg = 0;
void dfs(int id){
    if(fg) return ;
    if(id >= 13){
        if(check()){
            for(int i = 1; i <= 12; ++i) printf("%d%c", val[i], i == 12 ? '\n' : ' ');
            fg = 1;
        }
        return ;
    }
    if(id == 1 || id == 10 || id == 11) dfs(id + 1);
    else{
        for(int i = 1; i <= 12; ++i){ 
            if(fg) return ;
            if(!used[i]){
                val[id] = i;
                used[i] = 1;
                dfs(id + 1);
                used[i] = 0;
            }
        }
    }
}
int main(){
    val[1] = 1;
    val[10] = 8;
    val[11] = 3;
    used[1] = 1;
    used[8] = 1;
    used[3] = 1;
    dfs(1);
    printf("%d\n", val[3]);
    return 0;
}
/*
answer: 10
*/