#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 2e5 + 7;
map<int, int> s;
struct node
{
    int x, y, id;
}a[N];
int n, m;

bool cmp(node x, node y)
{
    if (x.x == y.x) return x.y > y.y;
    return x.x > y.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s[x]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        a[i].x = s[x], a[i].id = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        a[i].y = s[x];
    }
    sort(a + 1, a + 1 + m, cmp);
    cout << a[1].id << "\n";
    return 0;
}