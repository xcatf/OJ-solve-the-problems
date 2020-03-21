#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
int solve(int n)
{
    bool vis[305] = {false};
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            if (!vis[j])
                ++ans;
            else
                --ans;
            vis[j] = !vis[j];
        }
    }
    return ans;
}
int main()
{
    freopen("test_out.out","w",stdout);
    for(int i=1;i<=300;++i){
        printf("%d\n",solve(i));
    }
}