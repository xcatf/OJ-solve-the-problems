#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) x & -x;
const static int MAX_N = 1e6 + 5;
int a[MAX_N], c[MAX_N];
ll cnt[MAX_N];
void update(int x, int v) {
	while (x < MAX_N) {
		c[x] += v;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ret = 0;
	while (x) {
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}
int main(){
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		update(a[i] + 1, 1);
		cnt[i] += (i - sum(a[i] + 1));
	}
	memset(c, 0, sizeof(c));
	ll res = 0;
	for (int i = n; i >= 1; i--) {
		update(a[i] + 1, 1);
		cnt[i] += sum(a[i]);
		res += (cnt[i] + 1) * cnt[i] / 2;
        //printf("a:%d sum:%d cnt:%lld res:%lld\n", a[i], sum(a[i]), cnt[i], res);
	}
	printf("%lld\n", res);
	return 0;
}