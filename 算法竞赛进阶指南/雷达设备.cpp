#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define x first
#define y second
typedef pair<double, double> pii;
const int N = 1010;

int d;
int n;
pii a[N];

bool cmp(pii x, pii y)
{
    return x.y < y.y;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > d) 
        {
            cout << -1 << endl;
            return;
        }
        double len = sqrt(d * d - y * y);
        a[i].x = x - len, a[i].y = x + len;
    }

    sort(a, a + n, cmp);

    int res = 0;
    double last = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x > last)
        {
            res++;
            last = a[i].y;
        }
    }

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> d;
    solve();
    return 0;
}