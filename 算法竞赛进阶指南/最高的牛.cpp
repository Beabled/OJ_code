#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e4 + 7;
int d[N];
int n, p, h, m;
map<pii, bool> st;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> p >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (st[{a, b}]) continue;
        st[{a, b}] = true;
        d[a + 1]--, d[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        cout << h + d[i] << "\n";
    }
    return 0;
}