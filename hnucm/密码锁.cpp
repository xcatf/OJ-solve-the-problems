#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+5;
char s[15];
struct node{
    char str[15];
    int cnt;
    node(){}
    node(char *a,int b){strcpy(str,a);cnt=b;}
};
bool check(char *str){
    return strstr(str,"2012");
}
int bfs(int n){
    unordered_map<string,bool>mp;
    queue<node>q;
    q.emplace(node(s,0));
    mp[s]=1;
    while(!q.empty()){
        node u=q.front();
        q.pop();
        if(check(u.str)) return u.cnt;
        for(int i=0;i<n-1;++i){
            swap(u.str[i],u.str[i+1]);
            if(!mp[u.str]){
                mp[u.str]=1;
                q.emplace(node(u.str,u.cnt+1));
                
            }
            swap(u.str[i],u.str[i+1]);
        }
    }
    return -1;
}
int main(){
    // freopen("data/pwd4.in","r",stdin);
    // freopen("data/pwd4.out","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        printf("%d\n",bfs(n));
    }
    return 0;
}