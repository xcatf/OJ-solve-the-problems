#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const int mod=1e9+3;
bool leaf(int x){
    return (x%4==0&&x%100!=0)||x%400==0;
}
int wk[2205];
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void getweek(){//得到该年第一年是星期几
    wk[2000]=6;
    int nw=6;
    for(int i=2000;i<2200;++i){
        if(leaf(i)) nw+=2;
        else ++nw;
        wk[i+1]=nw%7;
    }
}
void getday(int y,int &fa,int &ma){
    int nw=wk[y];
    if(leaf(y)) a[2]=29;
    else a[2]=28;
    int nd;
    if(nw==0) nd=1;
    else nd=8-nw;
    int i=0;
    while(i<5){
        nd+=7;
        if(nd>a[i]){
            nd-=a[i];
            ++i;
        }
    }
    //5月第二个星期天
    ma=nd+7;
    while(i<6){
        nd+=7;
        if(nd>a[i]){
            nd-=a[i];
            ++i;
        }
    }
    //6月第三个星期天
    fa=nd+14;
}
char dy[][5]={"",
    "1st","2nd","3rd","4th","5th","6th","7th","8th","9th","10th", 
    "11th","12th","13th","14th","15th","16th","17th","18th","19th", 
    "20th","21st","22nd","23rd","24th","25th","26th","27th","28th", 
    "29th","30th","31st"
};
int main(){
    int t,y,m,d;
    getweek();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&y,&m,&d);
        int fa=0,ma=0;
        getday(y,fa,ma);
        if(m>6||m==6&&d>=fa){//最近节日是明年母亲节
            ++y;
            getday(y,fa,ma);
            printf("Mother's Day: May %s, %d\n",dy[ma],y);
        }
        else if(m==5&&d>=ma||m==6){//最近节日是今年父亲节
            printf("Father's Day: June %s, %d\n",dy[fa],y);
        }
        else{
            printf("Mother's Day: May %s, %d\n",dy[ma],y);
        }
    }
    return 0;
}