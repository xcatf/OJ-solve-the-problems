#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e5 + 5;
static const int mod = 10000;
typedef long long ll;
int a[maxn];
struct node
{
    int id;
    int left,right;
    int max;
}tr[maxn << 2];

pair<int,int> buildmax(int left,int right,int now)
{
    tr[now].left=left;
    tr[now].right=right;
    if(left==right)
    {
        tr[now].id=left;
        tr[now].max=a[left];
        return make_pair(left,a[left]);
    }
    int mid=(left+right)>>1;

    pair<int,int> r1=buildmax(left,mid,now*2);
    pair<int,int> r2=buildmax(mid+1,right,now*2+1);
    if(r1.second>=r2.second)
    {
        tr[now].id=r1.first;
        tr[now].max=r1.second;
        return r1;
    }
    else
    {
        tr[now].id=r2.first;
        tr[now].max=r2.second;
        return r2;
    }
}

pair<int,int> querymax(int left,int right,int now)
{
    if(left == tr[now].left && right == tr[now].right)
        return make_pair(tr[now].id,tr[now].max);
    int mid=(tr[now].left+tr[now].right)>>1;

    if(right<=mid)
        return querymax(left, right, now << 1);
    else if(left>mid)
        return querymax(left, right, now << 1 | 1);
    else
    {
        pair<int,int> r1=querymax(left, mid, now << 1);
        pair<int,int> r2=querymax(mid+1, right, now << 1 | 1);
        return r1.second >= r2.second ? r1 : r2;
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    buildmax(1, n, 1);
    int ql = 1, qr = n - m + 1;
    for(int i = 1; i <= m; ++i){
        pair<int, int>res = querymax(ql, qr, 1);
        printf("%d%c", res.second, i == m ? '\n' : ' ');
        ql = res.first + 1;
        qr++;
    }
    return 0;
}

