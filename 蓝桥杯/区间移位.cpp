#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
struct node{
    int l,r;
    bool operator<(const node&rhs)const{
        return r<rhs.r;
    }
}a[maxn];
int n;
bool check(int le){
    vector<node>v;
    for(int i=0;i<n;++i) v.push_back(a[i]);
    int pos=0;
    while(1){
        bool f=0;
        for(int i=0;i<v.size();++i){
            if(v[i].l-le<=pos&&v[i].r+le>=pos){
                f=1;
                if(v[i].l+le<pos) pos=v[i].r+le;
                else pos+=v[i].r-v[i].l;
                v.erase(v.begin()+i);
                break;
            }
        }
        if(!f||pos>=20000)break;
    }
    return pos>=20000;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].l<<=1;a[i].r<<=1;
    }
    sort(a,a+n);
    int l=0,r=20000;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(r%2==0) printf("%d\n",r/2);
    else printf("%.1f\n",r/2.0);
    return 0;
}