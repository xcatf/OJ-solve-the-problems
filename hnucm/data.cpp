#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+5;
char s[30][5];
bool v[30][2];
int pr[30];
int find_set(int x){
    if(pr[x]!=x) pr[x]=find_set(pr[x]);
    return pr[x];
}
void union_set(int x,int y){
    int fx=find_set(x);
    int fy=find_set(y);
    if(fx!=fy) pr[fx]=fy;

}
int main(){
    srand((int)time(0));
    freopen("data/family3.in","w",stdout);
    for(int t=0;t<1000;++t){
        int n=50000;;
        int m=50;
        memset(v,0,sizeof(v));
        for(int i=0;i<30;++i) pr[i]=i;
        int cnt=0;
        char s1[5];
        vector<char>str;
        for(int i=0;i<n;++i){
            for(int k=0;k<3;++k) s1[k]=rand()%26+'A';
            if(rand()%4==0) s1[1]='-';
            if(s1[0]==s1[1]||s1[0]==s1[2]||s1[1]==s1[2]) continue;
            s1[3]='\0';
            if(!v[s1[0]-'A'][0]&& (s1[1]=='-'||!v[s1[1]-'A'][1]) && !v[s1[2]-'A'][1]){
                v[s1[0]-'A'][0]=1;
                if(s1[1]!='-') v[s1[1]-'A'][1]=1;
                v[s1[2]-'A'][1]=1;
                int x=s1[0]-'A';
                int y=s1[1]-'A';
                int z=s1[2]-'A';
                if(find_set(x)==find_set(z)) continue;
                if(s1[1]!='-'){
                    if(find_set(x)==find_set(y)) continue;
                    if(find_set(z)==find_set(y)) continue;
                    union_set(x,y);
                    union_set(z,y);
                }
                union_set(x,z);
                for(int k=0;k<3;++k){
                    if(s1[k]!='-') str.push_back(s1[k]);
                }
                strcpy(s[cnt++],s1);
            }
        }
        vector<pair<int,int>>query;
        for(int i=0;i<m;++i){
            int id1=rand()%str.size();
            int id2=rand()%str.size();
            if(str[id1]==str[id2]) continue;
            query.push_back(make_pair(id1,id2));
        }
        printf("%d %d\n",cnt,query.size());
        for(int i=0;i<cnt;++i) printf("%s\n",s[i]);
        for(int i=0;i<query.size();++i){
            printf("%c%c\n",str[query[i].first],str[query[i].second]); 
        }
    }
    return 0;
}