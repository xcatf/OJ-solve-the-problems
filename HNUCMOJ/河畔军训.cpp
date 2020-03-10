#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
static const double eps = 1e-4;
char mp[maxn][maxn];
bool used[3][maxn][maxn];
int n, m;
bool check(int x, int y, int id){
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#' && !used[id][x][y];
}
int d1[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int d2[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
queue<pair<int, int> >q[3];
pair<int, int>pos[3];
bool bfs(int id){
    pair<int, int>u, v;
    int sz = q[id].size();
    while(sz--){
        u = q[id].front();
        q[id].pop();
        if(id == 2){
            for(int i = 0; i < 8; ++i){
                v.first = u.first + d2[i][0];
                v.second = u.second + d2[i][1];
                if(check(v.first, v.second, id)){
                    used[id][v.first][v.second] = 1;
                    q[id].push(v);                   
                    if(used[0][v.first][v.second] && used[1][v.first][v.second] && used[2][v.first][v.second]) 
                        return true;
                }
            }
        }
        else{
            for(int i = 0; i < 4; ++i){
                v.first = u.first + d1[1][0];
                v.second = u.second + d1[i][1];
                if(check(v.first, v.second, id)){
                    used[id][v.first][v.second] = 1;
                    q[id].push(v);
                    if(used[0][v.first][v.second] && used[1][v.first][v.second] && used[2][v.first][v.second]) 
                        return true;
                }
            }
        }
    }
    return false;
}
int solve(){
    memset(used, 0, sizeof(used));
    for(int i = 0; i < 3; ++i){
        while(!q[i].empty()) q[i].pop();
        q[i].push(pos[i]);
        used[i][pos[i].first][pos[i].second] = 1;
    }
    int res = 0;
    while(!q[0].empty() || !q[1].empty() || !q[2].empty()){
        ++res;
        if(bfs(0)) return res;
        if(bfs(1)) return res;
        for(int k = 0; k < 3; ++k){
            if(bfs(2)) return res;
        }
    }
    return -1;
}
int main()
{
    char tc[3] = {'z', 'y', 'h'};
    //freopen("D.in", "r", stdin);
    //freopen("D.out", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; ++i) scanf("%s", mp[i]);
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < 3; ++k){
                    if(mp[i][j] == tc[k])
                    {
                        pos[k].first = i;
                        pos[k].second = j;
                        break;    
                    }
                }
            }
        }
        int ans = solve();
        if(ans != -1) printf("%d\n", ans);
        else puts("lack of junxun");
    }
    return 0;
}