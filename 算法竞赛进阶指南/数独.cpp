#include <bits/stdc++.h>
using namespace std;
const int N = 10, M = 1 << 10 + 1;
string s;
char g[N][N];
int row[N], col[N], grid[N], num[M], cnt[M], t;

inline int get(int x, int y)
{
    return ((x / 3) * 3) + y / 3;
}

inline void flip(int x, int y, int z)
{
    row[x] ^= 1 << z;
    col[y] ^= 1 << z;
    grid[get(x, y)] ^= 1 << z;
}

bool dfs(int now)
{
    if (!now) return 1;
    int temp = 10, x, y;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (g[i][j] != '.') continue;
            int val = row[i] & col[j] & grid[get(i, j)];
            if (!val) return 0;
            if (temp > cnt[val]) {
                temp = cnt[val], x = i, y = j;
            }
        }
    int val = row[x] & col[y] & grid[get(x, y)];
    for (; val; val -= val&-val) {
        int z = num[val&-val];
        g[x][y] = '1' + z;
        flip(x, y, z);
        if (dfs(now - 1)) return 1;
        flip(x, y, z);
        g[x][y] = '.';
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 1 << 9; i++)
        for (int j = i; j; j -= j&-j) cnt[i]++;
    for (int i = 0; i < 9; i++) num[1 << i] = i;
    ios::sync_with_stdio(false);
    while (cin >> s, s != "end") {
        int k = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) g[i][j] = s[k++];
        for (int i = 0; i < 9; i++) row[i] = col[i] = grid[i] = (1 << 9) - 1;
        t = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (g[i][j] != '.') flip(i, j, g[i][j] - '1');
                else t++;
        dfs(t);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) cout << g[i][j];
        cout << "\n";
    }
    return 0;
}