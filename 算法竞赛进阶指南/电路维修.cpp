#include <bits/stdc++.h>
using namespace std;
const int N = 550;
int n, m;
char s[N][N];
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
bool st[N][N];
int v[N][N];
struct rec { int x, y, v; };

bool vaild(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t; while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> s[i] + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) 
                if (s[i][j] == '\\') v[i][j] = 0;
                else v[i][j] = 1; 
        memset(st, false, sizeof st);
        deque<rec> q;
        v[1][1] = 0, st[1][1] = true;
        if (s[1][1] == '\\') q.push_back({1, 1, 0});
        else if (s[1][1] == '/') q.push_back({1, 1, 1});
        while (q.size()) {
            rec now = q.front(); q.pop_front();
            if (now.x == n && now.y == m) {
                if (v[n][m] == 0) {
                    cout << now.v << "\n";
                }
                else {
                    cout << "NO SOLUTION\n";
                }
                break;
            }
            for (int i = 0; i < 4; i++) {
                int x = now.x + dx[i], y = now.y + dy[i];
                if (!vaild(x, y) || st[x][y]) continue;
                st[x][y] = true;
                if (v[x][y] == v[now.x][now.y]) {
                    v[x][y] = 1 - v[x][y];
                    q.push_back({x, y, now.v + 1});
                }
                else q.push_front({x, y, now.v});
            }
            int k = 0;
            if (v[now.x][now.y] != 0) {
                k += 2;
            }
            
            for (int i = 4 + k; i < 6 + k; i++) {
                int x = now.x + dx[i], y = now.y + dy[i];
                if (!vaild(x, y) || st[x][y]) continue;
                st[x][y] = true;
                if (v[x][y] == v[now.x][now.y]) q.push_front({x, y, now.v});
                else {
                    v[x][y] = 1 - v[x][y];
                    q.push_back({x, y, now.v + 1});
                }
            }
        }
    }
    return 0;
}