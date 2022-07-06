#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n;
int f[N];
vector<string> res;
map<string, int> s;
stack<char> q;

void dfs(int u, string str, int t)
{
    if (u == n)
    {
        auto r = q;
        while (!r.empty()) str += r.top(), r.pop();
        if (!s[str]) res.push_back(str), s[str]++;
        return;
    }
    if (!q.empty()) 
    {
        char x = q.top();
        q.pop();
        dfs(u, str + x, t - 1);
        q.push(x);
    }
    if (u + 1 < 10) q.push(u + '1');
    else q.push('a' + u + 1 - 10);
    dfs(u + 1, str, t + 1);
    q.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(0, "", -1);
    sort(res.begin(), res.end());
    for (int i = 0; i < min(20, int(res.size())); i++) 
    {
        for (int j = 0; j < res[i].size(); j++)
            if (res[i][j] >= 'a' && res[i][j] <= 'z') 
            {
                cout << to_string(int(res[i][j] - 'a' + 10));
            }
            else cout << res[i][j];
        cout << "\n";
    }
    return 0;
}