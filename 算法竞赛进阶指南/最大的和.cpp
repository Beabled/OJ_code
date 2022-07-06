#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int a[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j], a[i][j] += a[i - 1][j];
    int res = -1e9;
    for (int i = 0; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int sum = 0;
            for (int k = 1; k <= n; k++)
            {
                int w = a[j][k] - a[i][k];
                sum = max(0, sum) + w;
                res = max(res, sum);
            }
        }
    cout << res << "\n";
    return 0;
}