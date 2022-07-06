#include <bits/stdc++.h>
using namespace std;
char a[5][5], b[5][5];
vector<pair<int, int>> res;

int get(int i, int j)
{
    return i * 4 + j;
}

void turn(int i, int j)
{
    if (b[i][j] == '+') b[i][j] = '-';
    else b[i][j] = '+';
}

void get_turn(int i, int j)
{
    turn(i, j), turn(i - 1, j), turn(i + 1, j);
    turn(i, j - 1), turn(i, j + 1);
}

int main()
{
    for (int i = 1; i <= 4; i++) cin >> a[i] + 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++) cout << a[i] << " ";
        cout << "\n";
    }
    for (int op = 0; op < 1 << 16; op++)
    {
        vector<pair<int, int>> t;
        memcpy(b, a, sizeof a);
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                if (op >> get(i - 1, j - 1) & 1)
                    get_turn(i, j), t.push_back({i, j});
        bool f = true;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                if (b[i][j] == '-') 
                {
                    f = false;
                    break;
                }
        if (f)
        {
            if (t.empty() || t.size() < res.size()) res = t;
        }
    }
    cout << res.size();
    for (int i = 0; i < res.size(); i++) cout << res[i].first << " " << res[i].second << "\n";
    return 0;
}