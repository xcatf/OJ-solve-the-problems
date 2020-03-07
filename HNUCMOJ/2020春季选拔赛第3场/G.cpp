#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
static const double eps = 1e-4;
struct node
{
    int x, y, st;
};
int mp[maxn][maxn];
int n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool check(node p)
{
    return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m && mp[p.x][p.y] != -1;
}
int bfs(int sx, int sy, int ex, int ey)
{
    bool vis[105][105];
    memset(vis, 0, sizeof(vis));
    node p1, p2;
    p1.x = sx, p1.y = sy, p1.st = 0;
    vis[sx][sy] = 1;
    queue<node> q;
    q.push(p1);
    while (!q.empty())
    {
        p1 = q.front();
        q.pop();
        if (p1.x == ex && p1.y == ey)
            return p1.st;
        for (int i = 0; i < 4; ++i)
        {
            p2.x = p1.x + dir[i][0];
            p2.y = p1.y + dir[i][1];
            p2.st = p1.st + 1;
            if (check(p2) && !vis[p2.x][p2.y])
            {
                q.push(p2);
                vis[p2.x][p2.y] = 1;
            }
        }
    }
    return -1;
}
int dis[10][10];
int ans;
bool used[10];
void dfs(int id, int le, int u, int now)
{
    if (id == le)
    {
        ans = min(ans, now);
        return;
    }
    for (int v = 0; v < le; ++v)
    {
        if (!used[v])
        {
            used[v] = 1;
            dfs(id + 1, le, v, now + dis[u][v]);
            used[v] = 0;
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        node point[10];
        int cnt = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &mp[i][j]);
                if (mp[i][j] == 1 || mp[i][j] == 2)
                {
                    node p;
                    p.x = i, p.y = j;
                    if(mp[i][j] == 1){
                        point[cnt++] = p;
                    }
                    else point[0] = p;
                }
            }
        }
        memset(dis, 127, sizeof(dis));
        bool f = 1;
        for (int i = 0; i < cnt && f; ++i)
        {
            for (int j = i; j < cnt && f; ++j)
            {
                int d = bfs(point[i].x, point[i].y, point[j].x, point[j].y);
                if (d == -1)
                    f = 0;
                dis[i][j] = dis[j][i] = min(dis[i][j], d);
            }
        }
        if (!f)
            puts("-1");
        else
        {
            ans = INT_MAX;
            dfs(0, cnt, 0, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}