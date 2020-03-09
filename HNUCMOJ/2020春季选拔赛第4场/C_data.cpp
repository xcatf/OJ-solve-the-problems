#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e2 + 5;
char opt[2] = {'S', 'E'};
struct node{
    int now, num;
    int hh, mm;
    char ch;
    bool operator < (const node &rhs)const{
        return now < rhs.now;
    }
}a[maxn];
int main(){
    srand((int)time(0));
    freopen("C3.in", "w", stdout);
    int n = rand() % 100 + 1;
    for(int i = 0; i < n; ++i){
        int d = rand() % 50 + 1;
        for(int j = 0; j < d; ++j){
            char ch = opt[rand() % 2];
            int hh = rand() % 24;
            int mm = rand() % 60;
            int num = rand() % 100 + 1;
            a[j].hh = hh;
            a[j].mm = mm;
            a[j].num = num;
            a[j].ch = ch;
            a[j].now = hh * 60 + mm;
        }
        sort(a, a + d);
        for(int j = 0; j < d; ++j) printf("%d %c %02d:%02d\n", a[j].num, a[j].ch, a[j].hh, a[j].mm);
        printf("0 %c %02d:%02d\n", a[d - 1].ch, a[d - 1].hh, a[d - 1].mm);
    }
    printf("-1");
    return 0;
}