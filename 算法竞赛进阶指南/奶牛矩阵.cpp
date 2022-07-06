#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 80;
int n, m, ne[N];
char g[N][M];
string s[N];
bool st[M];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> g[i] + 1;
    int width = 0;
    for (int l = 1; l <= m; l++) {
        bool f = true;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i + l <= m; i++)
                if (g[j][i] != g[j][i + l]) {
                    f = false;
                    break;
                }
            if (!f) break;
        }
        if (!f) st[l] = true;
    }
    for (int i = 1; i <= m; i++)
        if (!st[i]) {
            width = i;
            break;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= width; j++) s[i] += g[i][j];
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) j++;
        ne[i] = j;
    }
    int h = n - ne[n];
    cout << h * width << "\n";
    return 0;
}