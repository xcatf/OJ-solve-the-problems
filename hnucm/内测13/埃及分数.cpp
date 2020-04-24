#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e2+5;
int main(){
    int a,b;
    while(~scanf("%d/%d",&a,&b)){
        while(a!=1){
            if(b%(a-1)==0){
                printf("1/%d+",b/(a-1));
                a=1;
            }
            else{
                int c=b/a+1;
                printf("1/%d+",c);
                a=a*c-b;
                b=b*c;
                if(b%a==0){
                    b/=a;
                    a=1;
                }
            }
        }
        printf("1/%d",b);
        printf("\n");
    }
    return 0;
}