#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
string s;
int main(){
    // freopen("data/words4.in","r",stdin);
    // freopen("data/words4.out","w",stdout);
    getline(cin,s);
    int le=s.length();
    int ans=0;
    for(int i=le-1;i>=0&&s[i]!=' ';--i) ++ans;
    printf("%d\n",ans);
    return 0;
}