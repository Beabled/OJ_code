#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1e5 + 7;
int n, m;
pii a[N], b[N];

bool cmp(pii x, pii y)
{
    return x.x < y.x;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        long long res = 0, cnt = 0;
        for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
        for (int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;
        multiset<int> s;
        sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
        for (int i = m, j = n; i >= 1; i--)
        {
            while (j >= 1 && b[i].x <= a[j].x) s.insert(a[j--].y);
            multiset<int>::iterator it = s.lower_bound(b[i].y);
            if (it != s.end())
            {
                cnt++;
                res += 500 * b[i].x + 2 * b[i].y;
                s.erase(it);
            }
        }
        cout << cnt << " " << res << "\n";
    }
    return 0;
}