#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<string, int> pii;
const int N = 1e5 + 7;
pii a[N];
int n, m;

int calc(int bit, int now)
{
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].y >> bit & 1;
        if (a[i].x == "AND") now &= x;
        else if (a[i].x == "OR") now |= x;
        else now ^= x;
    }
    return now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        a[i] = make_pair(s, x); 
    }
    int val = 0, res = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int res0 = calc(bit, 0);
        int res1 = calc(bit, 1);
        if (val + (1 << bit) <= m && res0 < res1)
            val += 1 << bit, res += res1 << bit;
        else res += res0 << bit;
    }
    cout << res << "\n";
    return 0;
}