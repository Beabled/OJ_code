#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6;

char f[N][N], a[N][N];
int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= 5 && b >= 1 && b <= 5)
            if (f[a][b] == '1') f[a][b] = '0';
            else f[a][b] = '1';
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
                cin >> a[i][j];
        
        int res = 1e9;
        for (int op = 0; op < 32; op++)
        {
            memcpy(f, a, sizeof a);
            int step = 0;
            
            
            for (int i = 0; i < 5; i++)
            {
                if (op >> i & 1)
                {
                    step++;
                    turn(1, i + 1);
                }
            }
            
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 5; j++)
                {
                    if (f[i][j] == '0')
                    {
                        step++;
                        turn(i + 1, j);
                    }
                }
                
            bool dark = false;
            for (int i = 1; i <= 5; i++)
                if (f[5][i] == '0')
                {
                    dark = true;
                    break;
                }
                
            if (!dark) res = min(res, step);
        }
        
        if (res <= 6) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}