#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
int edge[maxn][maxn];
int place[maxn][maxn];
int n, ans, m;
void dfs(int u, int cnt)
{
    if (cnt >= ans)
        return;
    if (u > n)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int j = 1; j <= cnt; ++j)
    {
        int now = 0;
        while (place[j][now] && !edge[u][place[j][now]])
            now++;
        if (place[j][now] == 0)
        {
            place[j][now] = u;
            dfs(u + 1, cnt);
            place[j][now] = 0;
        }
    }
    place[cnt + 1][0] = u;
    dfs(u + 1, cnt + 1);
    place[cnt + 1][0] = 0;
}
int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        edge[a][b] = edge[b][a] = 1;
    }
    ans = n;
    dfs(1, 1);
    printf("%d\n", ans);
    return 0;
}