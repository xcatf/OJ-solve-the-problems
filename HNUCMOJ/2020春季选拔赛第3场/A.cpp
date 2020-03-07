#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s[maxn];
char letter[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int get_cnt(int id, char pattern){
    for(int j = 0; j < strlen(letter[id]); ++j){
        if(letter[id][j] == pattern) return j + 1;
    }
    return 0;
}
int main(){
    map<char, int>mp;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < strlen(letter[i]); ++j) mp[letter[i][j]] = i;
    }
    while(scanf("%s", s) != EOF){
        int ans = 0;
        int now = -1;
        for(int i = 0; s[i]; ++i){
            int id = mp[s[i]];
            ans += get_cnt(id, s[i]);
            if(id == now) ans += 2;
            now = id;
        }
        printf("%d\n", ans);
    }
}