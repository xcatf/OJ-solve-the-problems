#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
int mp[maxn];
char ch[]={'[',']'};
int main()
{
    srand((int)time(0));
    freopen("D4.in", "w", stdout);
    int n = rand() % 10000 + 1;
    if (n & 1)
        ++n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
        vec[i] = i;
    int N = n / 2;
    for (int i = 0; i < N; ++i)
    {
        int l = rand() % vec.size();
        int left = vec[l];
        vec.erase(vec.begin() + l);
        int r = rand() % vec.size();
        int right = vec[r];
        vec.erase(vec.begin() + r);
        if (left > right)
            swap(left, right);
        mp[left] = 0;
        mp[right] = 1;
    }
    for (int i = 0; i < n; ++i)
        printf("%c", ch[mp[i]]);
    putchar('\n');

    return 0;
}