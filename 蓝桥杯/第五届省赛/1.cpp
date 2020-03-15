#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e5 + 5;
int main()
{
    for(int i = 1; i <= 100; ++i){
        for(int j = 1; j <= i; ++j){
            if(i * 1.9 + j * 2.3 == 82.3){
                printf("%d\n", j);
            }
        }
    }
    return 0;
}
/*
answer: 11
author: xcatf
 */