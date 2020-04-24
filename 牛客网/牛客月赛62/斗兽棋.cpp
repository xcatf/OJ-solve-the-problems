#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e5+5;
char s1[15],s2[15];
int main(){
    scanf("%s%s",s1,s2);
    if(s2[0]=='e'&&s1[0]=='t'||s2[0]=='t'&&s1[0]=='c'||s2[0]=='c'&&s1[0]=='m'||s2[0]=='m'&&s1[0]=='e'){
        printf("tiangou txdy\n");
    }
    else printf("tiangou yiwusuoyou\n");
    return 0;
}