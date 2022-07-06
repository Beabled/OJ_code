#include <bits/stdc++.h>
using namespace std;

int f[1010][1010];
int n;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n != -1)
    {
        memset(f, 0, sizeof f);
        f[1][1] = 1; 
        int p = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int a = 1; a <= p; a++)
                for (int b = 1; b <= p; b++)
                {
                    f[a + 2 * p][b] = f[a + p][b + p] = f[a][b + 2 * p] = f[a + 2 * p][b + 2 * p] = f[a][b];
                }
            p *= 3;
        }
        for (int i = 1; i <= p; i++)
        {
            for (int j = 1; j <= p; j++) 
                if (f[i][j]) cout << 'X';
                else cout << ' ';
            cout << "\n";
        }
        cout << "-\n";
    }
    return 0;
}