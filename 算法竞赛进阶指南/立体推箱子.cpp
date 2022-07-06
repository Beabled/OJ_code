#include <bits/stdc++.h>
using namespace std;
const int N = 550;
struct rec { int x, y, lie; };
int n, m;
int dx[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
int dy[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
int dlie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};
int d1[] = {1, -1, 0, 0}, d2[] = {0, 0, 1, -1};
rec st, ed;
char s[N][N];
int d[N][N][3];

bool vaild(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool vaild(rec x)
{
    if (!vaild(x.x, x.y)) return 0;
    if (s[x.x][x.y] == '#') return 0;
    if (x.lie == 0 && s[x.x][x.y] != '.') return 0;
    if (x.lie == 1 && s[x.x + 1][x.y] == '#') return 0;
    if (x.lie == 2 && s[x.x][x.y + 1] == '#') return 0;
    return 1;
}

void parse_st_ed()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] == 'O') ed.x = i, ed.y = j, ed.lie = 0, s[i][j] = '.';
            else if (s[i][j] == 'X') {
                for (int k = 0; k < 4; k++) {
                    int x = i + d1[k], y = j + d2[k];
                    if (vaild(x, y) && s[x][y] == 'X') {
                        st.x = min(x, i), st.y = min(y, j);
                        st.lie = k < 2 ? 1 : 2;
                        s[i][j] = s[x][y] = '.';
                        break;
                    }
                }
                if (s[i][j] == 'X') st.x = i, st.y = j, st.lie = 0;
            }
}

int bfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 3; k++) d[i][j][k] = -1;
    queue<rec> q;
    d[st.x][st.y][st.lie] = 0, q.push(st);
    while (q.size()) {
        rec now = q.front(); q.pop();
        if (now.x == ed.x && now.y == ed.y && now.lie == ed.lie) return d[now.x][now.y][now.lie];
        for (int i = 0; i < 4; i++) {
            int x = now.x + dx[now.lie][i], y = now.y + dy[now.lie][i], lie = dlie[now.lie][i];
            if (!vaild({x, y, lie})) continue;
            if (d[x][y][lie] == -1) {
                d[x][y][lie] = d[now.x][now.y][now.lie] + 1, q.push({x, y, lie});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m, n || m) {
        for (int i = 1; i <= n; i++) cin >> s[i] + 1;
        parse_st_ed();
        int res = bfs();
        if (res == -1) cout << "Impossible\n"; else cout << res << "\n";
    }
    return 0;
}