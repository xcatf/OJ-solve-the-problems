#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
char hx[1000],dc[maxn],tc[maxn],bit[maxn];
int ta[maxn],tb[maxn];
int getval(char c){
    if(c>='A') return c-'A'+10;
    return c-'0';
}
void BigInterAdd(char *a,char *b){  //10进制高精度加法
    memset(ta,0,sizeof(ta));
    memset(tb,0,sizeof(tb));
    int l1=strlen(a),l2=strlen(b);
    for(int i=0;i<l1;++i) ta[i]=getval(a[l1-i-1]);
    for(int i=0;i<l2;++i) tb[i]=getval(b[l2-i-1]);
    l1=max(l1,l2);
    int cay=0;
    for(int i=0;i<l1;++i){
        ta[i]+=tb[i]+cay;
        cay=ta[i]/10;
        ta[i]%=10; 
    }
    if(cay) ta[l1++]=cay;
    for(int i=0;i<l1;++i) a[i]=ta[l1-i-1]+'0';
    a[l1]='\0';
}   
void BigInterMul(char *tr,char *a,int mul){  //10进制高精度乘以低精度
    memset(ta,0,sizeof(ta));
    int le=strlen(a);
    for(int i=0;i<le;++i) ta[i]=getval(a[le-i-1]);
    int cay=0;
    for(int i=0;i<le;++i){
        ta[i]=ta[i]*mul+cay;
        cay=ta[i]/10;
        ta[i]%=10;
    }
    while(cay){
        ta[le]=ta[le]*mul+cay;
        cay=ta[le]/10;
        ta[le]%=10;
        le++;
    }
    for(int i=0;i<le;++i) tr[i]=ta[le-i-1]+'0';
    tr[le]='\0';
}
void toDecimal(){
    int le=strlen(hx);
    bit[0]='1'; //表示16的n次方
    bit[1]='\0';
    dc[0]='0';
    dc[1]='\0';         //最终十进制答案
    for(int i=le-1;i>=2;--i){
        BigInterMul(tc,bit,getval(hx[i]));
        BigInterAdd(dc,tc);
        BigInterMul(bit,bit,16);
    }
}
int main(){
    // freopen("data/conversion2.in","r",stdin);
    // freopen("data/conversion2.out","w",stdout);
    while(~scanf("%s",hx)){
        toDecimal();
        printf("%s\n",dc);
    }
    return 0;
}