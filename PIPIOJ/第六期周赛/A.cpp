#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e7 + 5;
int main(){
    string s;
    while(cin >> s){
        int len = s.length();
        for(int i = 0; i < len; ++i){
            //cout << i << ":";
            if(s[i] == 'P'){
                if(i - 1 >= 0 && s[i - 1] == 'P'){
                    s.erase(i - 1, 2);
                    len -= 2;
                    i -= 2;
                }
                else if(i + 1 < len && s[i + 1] == 'P'){
                    s.erase(i, 2);
                    len -= 2;
                    --i;
                }
            }
            else{
                if(i - 1  >= 0 && s[i - 1] == 'p'){
                    s.replace(i - 1, 2, "P");
                    len--;
                    i -= 2;
                }
                else if(i + 1 < len && s[i + 1] == 'p'){
                    s.replace(i, 2, "P");
                    len--;
                    --i;
                }
            }
            //cout << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}
/*
ppPPpppP
ppPPpP
*/