#include <bits/stdc++.h>
using namespace std;
const int N = 880;
struct rec { int x, y; };
int n, m, t;
char s[N][N];
bool st[N][N][2];
rec sta[2], ed1, ed2;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool vaild(int x, int y, int v) 
{
    if (abs(x - ed1.x) + abs(y - ed1.y) <= 2 * (v) || abs(x - ed2.x) + abs(y - ed2.y) <= 2 * (v)) return false;
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != 'X';
}

int bfs()
{
    int res = 0;
    queue<rec> q[2];
    q[0].push(sta[0]), q[1].push(sta[1]);
    st[sta[0].x][sta[0].y][0] = st[sta[1].x][sta[1].y][1] = true;
    while (q[0].size() || q[1].size()) {
        res++;
        for (int i = 0; i < 3; i++) {
            for (int j = 0, len = q[0].size(); j < len; j++) {
                rec now = q[0].front(); q[0].pop();
                if (!vaild(now.x, now.y, res)) continue;
                for (int k = 0; k < 4; k++) {
                    int x = now.x + dx[k], y = now.y + dy[k];
                    if (!vaild(x, y, res)) continue;
                    if (st[x][y][1]) return res;
                    if (!st[x][y][0]) st[x][y][0] = true, q[0].push({x, y});
                }
            }
        }
        for (int j = 0, len = q[1].size(); j < len; j++) {
            rec now = q[1].front(); q[1].pop();
            if (!vaild(now.x, now.y, res)) continue;
            for (int k = 0; k < 4; k++) {
                int x = now.x + dx[k], y = now.y + dy[k];
                if (!vaild(x, y, res)) continue;
                if (st[x][y][0]) return res;
                if (!st[x][y][1]) st[x][y][1] = true, q[1].push({x, y});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t; while (t--) {
        cin >> n >> m;
        ed1.x = 0;
        for (int i = 1; i <= n; i++) cin >> s[i] + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) 
                if (s[i][j] == 'M') sta[0].x = i, sta[0].y = j;
                else if (s[i][j] == 'G') sta[1].x = i, sta[1].y = j;
                else if (s[i][j] == 'Z') {
                    if (!ed1.x) ed1.x = i, ed1.y = j;
                    else ed2.x = i, ed2.y = j;
                }
        memset(st, 0, sizeof st);
        int res = bfs();
        if (res == -1) cout << "-1\n"; else cout << res << "\n";
    }
    return 0;
}