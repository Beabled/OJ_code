#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct rec { int x, y; };
int n, m;
char s[N][N];
int d[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
queue<rec> q;

bool vaild(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void parse()
{
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            d[i][j] = -1;
            if (s[i][j] == '1') {
                d[i][j] = 0, q.push({i, j});
            }
        }
}

void bfs() 
{
    while (q.size()) {
        rec now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = now.x + dx[i], y = now.y + dy[i];
            if (!vaild) continue;
            if (d[x][y] == -1) {
                d[x][y] = d[now.x][now.y] + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i] + 1;
    parse();
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << d[i][j] << " ";
        cout << "\n";
    }
    return 0;
}