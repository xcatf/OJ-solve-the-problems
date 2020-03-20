#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
char s[maxn];
int main()
{
    // freopen("D4.in","r",stdin);
    // freopen("D4.out","w",stdout);
    scanf("%s", s);
    stack<pair<char, int>> st;
    for (int i = 0; s[i]; ++i)
    {
        if (st.empty())
            st.push(make_pair(s[i], i));
        else
        {
            pair<char, int> now = st.top();
            if (now.first == '(' && s[i] == ')' || now.first == '{' && s[i] == '}' || now.first == '[' && s[i] == ']')
            {
                printf("%d %d\n", now.second, i);
                st.pop();
            }
            else
                st.push(make_pair(s[i], i));
        }
    }
    return 0;
}