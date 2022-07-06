#include <bits/stdc++.h>
using namespace std;
const int N = 16, M = N * N + 1;
char str[N][N], bstr[M][N][N];
int state[N][N], b1state[M][N][N], b2state[M][N][N];
int num[1 << N], cnt[1 << N];

inline void draw(int x, int y, int z)
{
    str[x][y] = 'A' + z;
    for (int i = 0; i < 16; i++) {
        state[x][i] &= ~(1 << z);
        state[i][y] &= ~(1 << z);
    }
    int sx = x / 4 * 4, sy = y / 4 * 4;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) state[sx + i][sy + j] &= ~(1 << z);
    state[x][y] = 1 << z;
}

bool dfs(int now)
{
    if (!now) return true;
    int know = now;
    memcpy(b1state[know], state, sizeof state);
    memcpy(bstr[know], str, sizeof str);
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++) 
            if (str[i][j] == '-') {
                int s = state[i][j];
                if (!s) {
                    memcpy(state, b1state[know], sizeof state);
                    memcpy(str, bstr[know], sizeof str);
                    return false;
                }
                if (cnt[s] == 1) {
                    draw(i, j, num[s]);
                    now--;
                }
            }

    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << 16) - 1, drawn = 0;
        for (int j = 0; j < N; j++) {
            int s = state[i][j];
            sand &= ~(sor & s);
            sor |= s;
            if (str[i][j] != '-') drawn |= s;
        }
        if (sor != (1 << 16) - 1) {
            memcpy(state, b1state[know], sizeof state);
            memcpy(str, bstr[know], sizeof str);
            return false;
        }
        for (int k = sand; k; k -= k&-k) {
            int t = k&-k;
            if (!(drawn & t)) {
                for (int j = 0; j < N; j++)
                    if (state[i][j] & t) {
                        draw(i, j, num[t]);
                        now--;
                    } 
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << 16) - 1, drawn = 0;
        for (int j = 0; j < N; j++) {
            int s = state[j][i];
            sand &= ~(sor & s);
            sor |= s;
            if (str[j][i] != '-') drawn |= s;
        }
        if (sor != (1 << 16) - 1) {
            memcpy(state, b1state[know], sizeof state);
            memcpy(str, bstr[know], sizeof str);
            return false;
        }
        for (int k = sand; k; k -= k&-k) {
            int t = k&-k;
            if (!(drawn & t)) {
                for (int j = 0; j < N; j++)
                    if (state[j][i] & t) {
                        draw(j, i, num[t]);
                        now--;
                    } 
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << 16) - 1, drawn = 0;
        for (int j = 0; j < N; j++) {
            int sx = i / 4 * 4, sy = i % 4 * 4;
            int dx = j / 4, dy = j % 4; 
            int s = state[sx + dx][sy + dy];
            sand &= ~(sor & s);
            sor |= s;
            if (str[sx + dx][sy + dy] != '-') drawn |= s;
        }
        if (sor != (1 << 16) - 1) {
            memcpy(state, b1state[know], sizeof state);
            memcpy(str, bstr[know], sizeof str);
            return false;
        }
        for (int k = sand; k; k -= k&-k) {
            int t = k&-k;
            if (!(drawn & t)) {
                for (int j = 0; j < N; j++) {
                    int sx = i / 4 * 4, sy = i % 4 * 4;
                    int dx = j / 4, dy = j % 4; 
                    if (state[sx + dx][sy + dy] & t) {
                        draw(sx + dx, sy + dy, num[t]);
                        now--;
                    } 
                }
            }
        }
    }

    if (!now) return true;
    int temp = 17, x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (str[i][j] == '-' && cnt[state[i][j]] < temp) temp = cnt[state[i][j]], x = i, y = j;
        }
    memcpy(b2state[know], state, sizeof state);
    for (int i = state[x][y]; i; i -= i&-i) {
        memcpy(state, b2state[know], sizeof state);
        draw(x, y, num[i&-i]);
        if (dfs(now - 1)) return true;
    }
    memcpy(state, b1state[know], sizeof state);
    memcpy(str, bstr[know], sizeof str);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 1 << N; i++)   
        for (int j = i; j; j -= j&-j) cnt[i]++;
    for (int i = 0; i < N; i++) num[1 << i] = i;
    while (cin >> str[0]) {
        for (int i = 1; i < 16; i++) cin >> str[i];
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++) state[i][j] = (1 << 16) - 1;
        int t = 0;
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
                if (str[i][j] != '-') draw(i, j, str[i][j] - 'A');
                else t++;
        dfs(t);
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) cout << str[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}