#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e3 + 5;
static const int mod = 10000;
typedef long long ll;
char mp[maxn][maxn];
bool used[maxn][maxn];
int n, m;
struct node
{
    int x, y;
    int dir;
    int line;
}u, v;
int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool check(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && !used[x][y];
}
bool bfs(pair<int, int>p1, pair<int, int>p2){
    queue<node>q;
    memset(used, 0, sizeof(used));
    u.x = p1.first, u.y = p1.second, u.line = 1, u.dir = -1;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        //printf("%d %d\n", u.x, u.y);
        if(u.x == p2.first && u.y == p2.second) return true;
        for(int i = 0; i < 4; ++i){
            v.x = u.x + d[i][0];
            v.y = u.y + d[i][1];
            v.dir = i % 2;
            //printf("x:%d y:%d\n", v.x, v.y);
            if(u.dir == -1 || i % 2 == u.dir) v.line = u.line;
            else v.line = u.line + 1;
            if(check(v.x, v.y)){
                if(v.line <= 3){
                    if(v.x == p2.first && v.y == p2.second) return true;
                    if(mp[v.x][v.y] == '.'){
                        q.push(v);
                        //printf("x:%d y:%d\n", v.x, v.y);
                        used[v.x][v.y] = 1;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", mp[i]+1);
    int q;
    scanf("%d", &q);
    while(q--){
        pair<int, int>p1, p2;
        scanf("%d%d%d%d", &p1.first, &p1.second, &p2.first, &p2.second);
        if(mp[p1.first][p1.second] != mp[p2.first][p2.second]) puts("NO");
        else if(mp[p1.first][p1.second] == '.' || mp[p2.first][p2.second] == '.') puts("NO");
        else if(bfs(p1, p2)){
            mp[p1.first][p1.second] = '.';
            mp[p2.first][p2.second] = '.';
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
/*
5 5
..A.C
.BAB.
BBAB.
.C...
....C
8
2 2 2 4
1 3 3 3
1 3 2 3
2 2 2 4
2 2 3 1
3 1 3 4
3 2 3 4
1 5 5 5
*/