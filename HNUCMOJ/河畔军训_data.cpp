#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
static const double eps = 1e-4;
char mp[maxn][maxn];
char opt[4] = {'.', '.', '.', '#'};
int main()
{   
    srand((int)time(0));
    freopen("D.in", "w", stdout);
    for(int t = 0; t < 50; ++t){
        int n = rand() % 500 + 1;
        int m = rand() % 500 + 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) mp[i][j] = opt[rand() % 4];
        }
        mp[rand() % n][rand() % m] = 'z';
        mp[rand() % n][rand() % m] = 'y';
        mp[rand() % n][rand() % m] = 'h';
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; ++i){
            mp[i][m] = '\0';
            printf("%s\n", mp[i]);
        }
    }
    return 0;
}