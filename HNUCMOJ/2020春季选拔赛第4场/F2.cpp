#include<bits/stdc++.h>
using namespace std;
char a[105],b[105];
int aa[15];
int main()
{
     //freopen("F.in", "r", stdin);
    //freopen("F2.out", "w", stdout);
    while(~scanf("%s %s",a+1,b+1)){
        memset(aa,0,sizeof(aa));
        int la=strlen(a+1),lb=strlen(b+1);
        for(int i=1;i<=la;++i)
            ++aa[a[i]-'0'];
        int ju=0;
        if(lb>=1&&lb<=4){
            for(int i=b[1]-'0'+1;i<=9;++i){
                if(aa[i]>=lb){
                    ju=1;
                    break;
                }
            }
        }else{
            for(int i=b[1]-'0'+1;i+4<=9;++i){
                if(aa[i]&&aa[i+1]&&aa[i+2]&&aa[i+3]&&aa[i+4]){
                    ju=1;
                    break;
                }
            }
        }
        if(ju)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
