#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1e5 + 7;
int n, res;
int a[N], b[N];


int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) a[i] -= i;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        res += abs(a[(n + 1) / 2] - a[i]);
        res += abs(b[(n + 1) / 2] - b[i]);
    }
    cout << res << "\n";
    return 0;
}