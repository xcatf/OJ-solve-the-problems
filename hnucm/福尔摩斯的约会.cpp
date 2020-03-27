#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
char s1[65],s2[65];
char s[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    // freopen("data/appointment5.in","r",stdin);
    // freopen("data/appointment5.out","w",stdout);
    scanf("%s%s",s1,s2);
    int w,hh,mm;
    int i;
    for(i=0;s1[i]&&s2[i];++i){
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'){
            w=s1[i]-'A';
            break;
        }
    }
    ++i;
    for(;s1[i]&&s2[i];++i){
        if(s1[i]==s2[i]){
            if(s1[i]>='0'&&s1[i]<='9'){
                hh=s1[i]-'0';
                break;
            }
            if(s1[i]>='A'&&s1[i]<='N'){
                hh=s1[i]-'A'+10;
                break;
            }
        }
    }
    scanf("%s%s",s1,s2);
    for(i=0;s1[i]&&s2[i];++i){
        if(s1[i]==s2[i]&&isalpha(s1[i])){
            mm=i;
            break;
        }
    }
    printf("%s %02d:%02d\n",s[w],hh,mm);
}