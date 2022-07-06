#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1010;
int h[N][N], n, m;
char g[N][N];

void build()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'F') h[i][j] += h[i - 1][j] + 1;
            else h[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    build();
    int res = 0;
    for (int i = n; i >= 1; i--) {
        stack<pii> s;
        for (int j = 1; j <= m + 1; j++) {
            int deep = 1;
            while (!s.empty() && s.top().x >= h[i][j]) {
                deep += s.top().y;
                res = max(res, s.top().x * (deep - 1));
                s.pop();
            }
            s.push({h[i][j], deep});
        }
    }
    cout << res * 3 << "\n";
    return 0;
}