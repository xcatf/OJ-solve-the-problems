#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
string s;
bool v[128];
int main(){
    // freopen("data/count1.in","r",stdin);
    // freopen("data/count1.out","w",stdout);
    getline(cin,s);
    int ans=0;
    set<char>se;
    for(int i=0;s[i];++i){
        if(s[i]>=0&&s[i]<=127&&!v[s[i]]) ++ans,v[s[i]]=1;
    }
    printf("%d\n",ans);
    return 0;
}