#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1e5 + 7;
int n;
vector<int> a;
pii q[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, x; i <= n; i++) cin >> x, a.push_back(x);
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int i = 0; i < n; i++) q[i] = {a[i], i};
    sort(q, q + n);
    int res = 1, cnt = 1;
    for (int i = 0; i < n; i++) {
        int k = q[i].y;
        if ((k == 0 || a[k - 1] < a[k]) && (k == n - 1 || a[k + 1] < a[k])) cnt--;
        else if (k != 0 && k != n - 1 && a[k - 1] > a[k] && a[k + 1] > a[k]) cnt++;
        if (q[i].x != q[i + 1].x) res = max(res, cnt);
    }
    cout << res << "\n";
    return 0;
}