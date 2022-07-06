#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int t;
int st[N];
bool ju[1010];
queue<int> q, f[1010];

int main()
{
    ios::sync_with_stdio(false);
    int T = 0;
    while (cin >> t, t)
    {
        memset(st, 0, sizeof st);
        memset(ju, false, sizeof ju);
        T++;
        cout << "Scenario #" << T << "\n"; 
        q = queue<int>();
        f[0] = queue<int>();
        for (int i = 1; i <= t; i++)
        {
            int x;
            cin >> x;
            for (int j = 1; j <= x; j++)
            {
                int y;
                cin >> y;
                st[y] = i;
            }
            f[i] = queue<int>();
        }
        string s;
        int a;
        while (cin >> s)
        {
            if (s == "ENQUEUE") 
            {
                cin >> a, f[st[a]].push(a);
                if (!ju[st[a]]) q.push(st[a]), ju[st[a]] = true;
            }
            else if (s == "DEQUEUE") 
            {
                int x = q.front();
                cout << f[x].front() << "\n";
                f[x].pop();
                if (f[x].empty()) q.pop(), ju[x] = false;
            }
            else break;
        }
        cout << "\n";
    }
    return 0;
}