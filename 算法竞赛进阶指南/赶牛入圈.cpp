#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1010;
int f[N][N];
int n, c, res = 1e9;
vector<pii> node;
vector<int> sum;

bool check(int x)
{
    for (int i1 = 1, i2 = 1; i2 <= sum.size(); i2++)
    {
        while (sum[i2 - 1] - sum[i1 - 1] + 1 > x) i1++;
        for (int j1 = 1, j2 = 1; j2 <= sum.size(); j2++)
        {
            while (sum[j2 - 1] - sum[j1 - 1] + 1 > x) j1++;
            if (f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1] >= c) return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> c >> n;
    for (int i = 1, x, y; i <= n; i++) 
    {
        cin >> x >> y;
        sum.push_back(x);
        sum.push_back(y);
        node.push_back({x, y});
    }
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    for (int i = 0; i < n; i++)
    {
        int a = lower_bound(sum.begin(), sum.end(), node[i].x) - sum.begin() + 1;
        int b = lower_bound(sum.begin(), sum.end(), node[i].y) - sum.begin() + 1;
        f[a][b]++;
    }
    for (int i = 1; i <= sum.size(); i++)
        for (int j = 1; j <= sum.size(); j++)
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    int l = 1, r = 10000;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
    return 0;
}