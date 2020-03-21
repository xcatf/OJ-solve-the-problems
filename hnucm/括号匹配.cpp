#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
char s[maxn];
struct node
{
    int l, r;
    node() {}
    node(int L, int R)
    {
        l = L;
        r = R;
    }
    bool operator<(const node &rhs) const
    {
        return l > rhs.l;
    }
};
int main()
{
    // freopen("D4.in","r",stdin);
    // freopen("D4.out","w",stdout);
    while (~scanf("%s", s))
    {
        stack<pair<char, int>> st;
        priority_queue<node> pq;
        for (int i = 0; s[i]; ++i)
        {
            if (st.empty())
                st.push(make_pair(s[i], i));
            else
            {
                pair<char, int> now = st.top();
                if (now.first == '(' && s[i] == ')' || now.first == '{' && s[i] == '}' || now.first == '[' && s[i] == ']')
                {
                    pq.push(node(now.second + 1, i + 1));
                    st.pop();
                }
                else
                    st.push(make_pair(s[i], i));
            }
        }
        while (!pq.empty())
        {
            printf("%d %d\n", pq.top().l, pq.top().r);
            pq.pop();
        }
    }
    return 0;
}