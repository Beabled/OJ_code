#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 7;
ll n, m, a[N], b[N];
priority_queue<ll, vector<ll>, greater<ll>> q2;
priority_queue<ll, vector<ll>, less<ll>> q1;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int j = 1;
    for (int i = 1; i <= m; i++) {
        while (q1.size() + q2.size() < b[i]) {
            if (!q1.size()) q1.push(a[j++]);
            else {
                if (a[j] > q1.top()) q2.push(a[j++]);
                else q1.push(a[j++]);
            }
        }
        while (q1.size() > i) {
            q2.push(q1.top());
            q1.pop();
        }
        while (q1.size() < i) {
            q1.push(q2.top());
            q2.pop();
        }
        cout << q1.top() << "\n";
    }
    return 0;
}