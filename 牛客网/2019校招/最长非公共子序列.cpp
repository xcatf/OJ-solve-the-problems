#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const int mod=1e9+3;
char s1[maxn],s2[maxn];
int ne[maxn][26];
int p[26];
int main(){
    scanf("%s%s",s1+1,s2);
    memset(p,-1,sizeof(p));
    int n1=strlen(s1+1),n2=strlen(s2);
    if(n1!=n2){
        printf("%d\n",max(n1,n2));
        return 0;
    }
    for(int i=n1;i>=1;--i){
        for(int j=0;j<26;++j) ne[i][j]=p[j];
        p[s1[i]-'a']=i;
    }
    for(int j=0;j<26;++j) ne[0][j]=p[j];
    int pos=0;
    int ans=-1;
    for(int i=0;i<n2;++i){
        pos=ne[pos][s2[i]-'a'];
        if(pos==-1){
            ans=n1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}