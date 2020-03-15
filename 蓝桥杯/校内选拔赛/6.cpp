#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
typedef long long ll;
map<char, bool>mp;
char ts[] = {'a', 'e', 'i', 'o', 'u'};
char s[105];
int main()
{
    for(int i = 0; i < 5; ++i) mp[ts[i]] = 1;
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        int i = 0;
        int cnt = 2;
        bool fg = 1;
        while(i < len && cnt){
            if(i < len && !mp[s[i]]){
                while(i < len && !mp[s[i]]) ++i;
            }
            else{
                fg = 0;
                break;
            }
            if(i < len && mp[s[i]]){
                while(i < len && mp[s[i]]) ++i;
            }
            else{
                fg = 0;
                break;
            }
            --cnt;
        }
        if(cnt==0 && i == len && fg) puts("yes");
        else puts("no");
    }
    return 0;
}