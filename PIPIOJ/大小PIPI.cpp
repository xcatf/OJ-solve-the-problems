#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
char s[maxn];
char ans[maxn];
int main(){
    while(~scanf("%s",s)){
        stack<char>st;
        for(int i=0;s[i];++i){
            if(st.empty()) st.emplace(s[i]);
            else{
                if(st.top()!=s[i]) st.emplace(s[i]);
                else{
                    if(s[i]=='P') st.pop();
                    else{
                        st.pop();
                        st.emplace('P');
                    }
                }
            }
            if(st.size()>=2){
                char a=st.top();
                st.pop();
                char b=st.top();
                st.pop();
                if(a==b){
                    if(a=='p') st.emplace('P');
                }
                else{
                    st.emplace(b);
                    st.emplace(a);
                }
            }
        }
        int n=st.size();
        ans[n]='\0';
        while(!st.empty()){
            ans[--n]=st.top();
            st.pop();
        }
        printf("%s\n",ans);
    }
    return 0;
}