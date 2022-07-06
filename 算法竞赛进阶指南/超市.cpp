#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1e4 + 7;
int n;
pii a[N];

bool cmp(pii x, pii y)
{
    if (x.y == y.y) return x.x > y.x;
    return x.y < y.y;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
        sort(a, a + n, cmp);
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (q.size() < a[i].y) q.push(a[i].x);
            else {
                if (q.top() < a[i].x) q.pop(), q.push(a[i].x);
            }
        }
        while (!q.empty()) {
            res += q.top();
            q.pop();
        }
        cout << res << "\n";
    }
    return 0;
}