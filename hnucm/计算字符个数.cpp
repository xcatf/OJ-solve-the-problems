#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
string s;
int main(){
    // freopen("data/characters3.in","r",stdin);
    // freopen("data/characters3.out","w",stdout);
    char c;
    getline(cin,s);
    cin>>c;
    int ans=0;
    for(int i=0;s[i];++i){
        if(tolower(s[i])==tolower(c)) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}