#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
int a[N], b[N], n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    ll d1 = 0, d2 = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i], b[i] = a[i] - a[i - 1];
        if (i != 1)
            if (b[i] > 0) d1 += b[i];
            else d2 += abs(b[i]);
    }
    cout << max(d1, d2) << "\n" << abs(d1 - d2) + 1 << "\n";
    return 0;
}