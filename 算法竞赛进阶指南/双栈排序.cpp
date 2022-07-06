#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, f[N], a[N], color[N];
bool g[N][N];

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = 1; i <= n; i++) {
        if (g[u][i]) {
            if (color[i] == c) return false;
            if (color[i] == -1 && !dfs(i, !c)) return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[n + 1] = n + 1;
    for (int i = n; i; i--) f[i] = min(f[i + 1], a[i]);
    memset(color, -1, sizeof color);
    memset(g, false, sizeof g);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j] && f[j + 1] < a[i]) {
                g[i][j] = g[j][i] = true;
            }
        } 
    bool st = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1 && !dfs(i, 0)) {
            st = false;
            break; 
        }
    }
    if (!st) {
        cout << "0\n";
        return 0;
    }
    int now = 1;
    stack<int> s1, s2;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            while (!s1.empty() && s1.top() == now) {
                cout << "b ";
                s1.pop();
                now++;
            }
            while (!s1.empty() && a[i] > s1.top()) {
                if (!s1.empty() && s1.top() == now) {
                    cout << "b ";
                    s1.pop();
                    now++;
                }
                else if (!s2.empty() && s2.top() == now) {
                    cout << "d ";
                    s2.pop();
                    now++;
                }
                else break;
            }
            cout << "a ";
            s1.push(a[i]);
        }
        else {
            while (1) {
                if (!s1.empty() && s1.top() == now) {
                    cout << "b ";
                    s1.pop();
                    now++;
                }
                else if (!s2.empty() && s2.top() == now) {
                    cout << "d ";
                    s2.pop();
                    now++;
                }
                else break;
            }
            cout << "c ";
            s2.push(a[i]);
        }
    }
    while (1) {
        if (!s1.empty() && s1.top() == now) {
            cout << "b ";
            now++, s1.pop();
        }
        else if (!s2.empty() && s2.top() == now) {
            cout << "d ";
            now++, s2.pop();
        }
        else break;
    }
    return 0;
}