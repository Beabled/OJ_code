#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int n, k, q[N], a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        if (t >= h && i - q[h] >= k) h++;
        while (t >= h && a[q[t]] >= a[i]) t--;
        q[++t] = i;
        if (i >= k) cout << a[q[h]] << " ";
    }
    cout << "\n";
    h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        if (t >= h && i - q[h] >= k) h++;
        while (t >= h && a[q[t]] <= a[i]) t--;
        q[++t] = i;
        if (i >= k) cout << a[q[h]] << " ";
    }
    cout << " ";
    return 0;
} 