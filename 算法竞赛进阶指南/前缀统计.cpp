#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m, son[N][30], cnt[N], idx;

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - 'a';
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
    cnt[p]++;
}

int query(string s)
{
    int p = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - 'a';
        if (!son[p][t]) return res;
        p = son[p][t], res += cnt[p];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        insert(str);
    }
    while (m--) {
        string str;
        cin >> str;
        cout << query(str) << "\n";
    }
    return 0;
}