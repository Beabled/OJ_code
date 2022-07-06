#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 * 10 + 7;
int t, n, son[N][12], idx;
bool st1[N], st2[N];

bool insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - '0';
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
        if (st2[p]) return false;
        if (i == s.size() - 1) {
            if (st1[p]) return false;
            st2[p] = true;
        }
        st1[p] = true;
    }
    return true;
}

void solve()
{
    idx = 0;
    memset(st1, false, sizeof st1);
    memset(st2, false, sizeof st2);
    memset(son, 0, sizeof son);
    cin >> n;
    bool f = true;
    while (n--) {
        string s;
        cin >> s;
        if (!insert(s)) f = false;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t; while (t--) solve();
    return 0;
}