#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 7;
char s[N];
ull f1[N], f2[N], p[N];
int n;

bool check1(int mid) 
{
    for (int i = mid + 1; i + mid <= n; i++)
        if (f1[i - 1] - f1[i - mid - 1] * p[mid] == f2[i + 1] - f2[i + mid + 1] * p[mid]) 
            return true;
    return false;
}

bool check2(int mid) 
{
    for (int i = mid; i + mid <= n; i++)
        if (f1[i] - f1[i - mid] * p[mid] == f2[i + 1] - f2[i + mid + 1] * p[mid]) 
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int t = 1;
    p[0] = 1;
    for (int i = 1; i <= 1e6; i++) p[i] = p[i - 1] * 131;
    while (cin >> s + 1) {
        int res = 0;
        if (s[1] == 'E' && s[2] == 'N' && s[3] == 'D') break;
        n = strlen(s + 1);
        p[0] = 1;
        f1[0] = f2[0] = 0, f1[n + 1] = f2[n + 1] = 0;
        for (int i = 1, j = n; i <= n; i++, j--) {
            f1[i] = f1[i - 1] * 131 + s[i] - 'a' + 1;
            f2[j] = f2[j + 1] * 131 + s[j] - 'a' + 1;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check1(mid)) l = mid;
            else r = mid - 1;
        }
        res = r * 2 + 1;
        l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check2(mid)) l = mid;
            else r = mid - 1;
        }
        res = max(res, r * 2);
        cout << "Case " << t++ << ": " << res << "\n";
    }
    return 0;
}