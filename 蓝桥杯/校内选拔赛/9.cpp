#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e3 + 5;
static const int mod = 10000;
typedef long long ll;
int n, m;
char mp[maxn][maxn];
struct node
{
    int x, y;
    int cnt;
}u, v;
queue<node>q;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool check(node p){
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", mp[i]);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(mp[i][j] == 'g'){
                u.x = i;
                u.y = j;
                u.cnt = 0;
                q.push(u);
            }
        }
    }
    while(!q.empty()){
        u = q.front();
        q.pop();
        mp[u.x][u.y] = 'g';
        if(u.cnt == k) continue;
        for(int i = 0; i < 4; ++i){
            v.x = u.x + d[i][0];
            v.y = u.y + d[i][1];
            v.cnt = u.cnt + 1;
            if(check(v)) q.push(v);
        }
    }
    for(int i = 0; i < n; ++i) printf("%s\n", mp[i]);
    return 0;
}