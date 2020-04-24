#include<bits/stdc++.h>
#define low(x) (x & (-x))
using namespace std;
const int N = 1e5+10;
typedef long long LL;
int ls[N*50],rs[N*50],rt[N*50],cnt;
LL c[N],val[N*50],ans1[N],ans2[N],ans;
int n,m,a[N],mp[N];
 
void add(int x){for (; x <= n; x += low(x)) c[x]++; }
LL sum(int x){LL sum = 0; for (; x; x -= low(x)) sum += c[x]; return sum;}
 
void update(int &now, int l, int r, int k){
	if (!now) now = ++cnt;	
	val[now]++;
	if (l + 1 == r) return;
	int mid = (l + r) / 2;
	if (k < mid) update(ls[now],l,mid,k);
	if (k >= mid) update(rs[now],mid,r,k);
}
 
LL query(int now, int l, int r, int a, int b){
	LL res = 0;
	if (a <= l && b >= r - 1) return val[now];
	int mid = (l + r) / 2;
	if (a < mid) res += query(ls[now],l,mid,a,b);
	if (b >= mid) res += query(rs[now],mid,r,a,b);
	return res;
}
 
LL ask(int l, int r, int ll, int rr){
	if (ll > rr) return 0;
	LL res = 0;
	for (int i = l; i; i -= low(i)) res -= query(rt[i],1,n+1,ll,rr);
	for (int i = r; i; i -= low(i)) res += query(rt[i],1,1+n,ll,rr);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		mp[a[i]] = i;
		ans1[i] = sum(n) - sum(a[i]);
		ans += ans1[i];
		ans2[i] = a[i] - sum(a[i]) - 1; 
		add(a[i]);
	}
 
	for (int i = 0; i < m; ++i){
		printf("%lld\n",ans);
		int now,pos;
		scanf("%d",&now);
		pos = mp[now];
		ans -= (ans1[pos] + ans2[pos]) - ask(0,pos,now+1,n) - ask(pos,n,1,now-1);
		for (int j = pos; j <= n; j += low(j))
			update(rt[j],1,n+1,now);
	}
	return 0;
}