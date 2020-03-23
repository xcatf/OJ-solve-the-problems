#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
char s[1005];
int main(){
    scanf("%s",s);
    map<char,int>m;
    for(int i=0;s[i];++i) m[s[i]]++;
    for(map<char,int>::iterator it=m.begin();it!=m.end();++it) printf("%c:%d\n",it->first,it->second);
    return 0;
}