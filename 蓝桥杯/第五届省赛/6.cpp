#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            for(int k = 1; k <= 9; ++k){
                for(int t = 1; t <= 9; ++t){
                    if(i == j || k == t) continue;
                    int upnow1 = i * k;
                    int downnow1 = j * t;
                    int upnow2 = i *  10 + k;
                    int downnow2 = j * 10 + t;
                    int g = __gcd(upnow1, downnow1);
                    upnow1 /= g;
                    downnow1 /= g;
                    g = __gcd(upnow2, downnow2);
                    upnow2 /= g;
                    downnow2 /= g;
                    if(upnow1 == upnow2 && downnow1 == downnow2){
                        ++ans;
                        printf("%d/%d * %d/%d = %d/%d\n", i, j, k, t, i * 10 + k, j * 10 + t);
                    }

                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
answer: 14
*/