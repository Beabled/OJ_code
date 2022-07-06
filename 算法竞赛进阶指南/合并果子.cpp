#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1, x; i <= n; i++) cin >> x, q.push(x);
    int res = 0;
    while (q.size() >= 2) {
        int x = q.top();
        q.pop();
        x += q.top();
        q.pop();
        res += x;
        q.push(x);
    } 
    cout << res << "\n";
    return 0;
}