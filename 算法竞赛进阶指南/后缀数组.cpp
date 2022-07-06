#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 3e5 + 7;
char s[N];
ull f[N], p[N];
int a[N], n;

bool cmp(int x, int y) 
{
    int l = 0, r = min(n - x, n - y) + 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (f[x + mid - 1] - f[x - 1] * p[mid] == f[y + mid - 1] - f[y - 1] * p[mid]) l = mid;
        else r = mid - 1;
    }
    return s[x + r] < s[y + r];
}

int find(int x, int y)
{
    int l = 0, r = min(n - x, n - y) + 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (f[x + mid - 1] - f[x - 1] * p[mid] == f[y + mid - 1] - f[y - 1] * p[mid]) l = mid;
        else r = mid - 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> s + 1;
    n = strlen(s + 1);
    p[0] = 1, s[n + 1] = 'a' - 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * 131 + s[i] - 'a' + 1;
        p[i] = p[i - 1] * 131;
        a[i] = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) cout << a[i] - 1 << " ";
    cout << "\n" << 0 << " ";
    for (int i = 2; i <= n; i++) cout << find(a[i], a[i - 1]) << " ";
    return 0; 
}