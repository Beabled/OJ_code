#include <bits/stdc++.h>
using namespace std;
const int N = 6, M = 15;
int q[M][N], t[M];
map<int, int> s;

int main()
{
    for (int i = 1; i <= 13; i++)
        for (int j = 1; j <= 4; j++)
        {
            char x;
            cin >> x;
            if (x == '0') q[i][j] = 10;
            else if (x == 'A') q[i][j] = 1;
            else if (x == 'J') q[i][j] = 11;
            else if (x == 'Q') q[i][j] = 12;
            else if (x == 'K') q[i][j] = 13;
            else q[i][j] = x - '0'; 
        }
    for (int i = 1; i <= 12; i++) t[i] = 4;
    t[13] = 1;
    int k = 0, res = 0;
    while (k < 4)
    {
        int now = q[13][t[13]++];
        s[now]++, res++;
        while (now != 13)
        {
            now = q[now][t[now]--];
            s[now]++, res++;
        }
        k++, res++;
    }
    int ans = 0;
    for (int i = 1; i <= 12; i++) 
        if (s[i] == 4) ans++;
    cout << ans << "\n";

    return 0;
}