#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
char a[N], b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), m = strlen(b + 1);
    for (int i = n + 1; i <= n * 2; i++) a[i] = a[i - n];
    for (int i = m + 1; i <= m * 2; i++) b[i] = b[i - m];
    int i = 1, j = 2, k;
    while (i <= n && j <= n) {
        for (k = 0; k < n && a[i + k] == a[j + k]; k++);
        if (k == n) break;
        if (a[i + k] > a[j + k]) {
            i = i + k + 1;
            if (i == j) i++;
        }
        else {
            j = j + k + 1;
            if (i == j) j++;
        }
    }
    int res1 = min(i, j);
    i = 1, j = 2;
    while (i <= n && j <= n) {
        for (k = 0; k < n && b[i + k] == b[j + k]; k++);
        if (k == n) break;
        if (b[i + k] > b[j + k]) {
            i = i + k + 1;
            if (i == j) i++;
        }
        else {
            j = j + k + 1;
            if (i == j) j++;
        }
    }
    int res2 = min(i, j);
    for (int i = res1, j = res2, k = 0; k < n; k++)
        if (a[i + k] != b[j + k]) {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    for (int i = res1; i < res1 + n; i++) cout << a[i];
    return 0;
}