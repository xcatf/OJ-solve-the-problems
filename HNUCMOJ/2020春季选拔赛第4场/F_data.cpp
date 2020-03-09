#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char s1[maxn];
int main(){
    srand((int)time(0));
    freopen("F.in", "w", stdout);
    for(int t = 0; t < 200; ++t){
        int n1 = rand() % 100 + 1;
        for(int i = 0; i < n1; ++i){
            s1[i] = rand() % 10 + '0';
        }
        s1[n1] = '\0';
        sort(s1, s1 + n1);
        printf("%s\n", s1);
        int n2 = rand() % 5 + 1;
        if(n2 < 5){
            char ch = rand() % 10 + '0';
            for(int i = 0; i < n2; ++i) putchar(ch);
        }   
        else{
            char ch = rand() % 5 + '1';
            for(int i = 0; i < n2; ++i) putchar(ch + i);
        }
        putchar('\n');
    }
    return 0;
}