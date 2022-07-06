#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 5e4 + 7;
struct ask {
    int l, r, id;
}p[N];
ll n, m, c[N], L[N], R[N], num[N];
pii Res[N];
ll res;

bool cmp1(ask x, ask y)
{
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}

bool cmp2(ask x, ask y)
{
    return x.r < y.r;
}

void work(int x, int v)
{
    res -= (num[x] * (num[x] - 1));
    num[x] += v;
    res += (num[x] * (num[x] - 1));
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        cin >> p[i].l >> p[i].r;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + m, cmp1);
    int t = sqrt(m);
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    if (R[t] < m) t++, L[t] = R[t - 1] + 1, R[t] = m;
    for (int i = 1; i <= t; i++) {
        res = 0;
        sort(p + L[i], p + R[i] + 1, cmp2);
        memset(num, 0, sizeof num);
        int l = p[L[i]].l, r = p[L[i]].r;
        for (int j = l; j <= r; j++) work(c[j], 1);
        Res[p[L[i]].id].x = res;
        Res[p[L[i]].id].y = (ll)(r - l + 1) * (r - l);
        ll g = gcd(Res[p[L[i]].id].x, Res[p[L[i]].id].y);
        if (!g) {
            Res[p[L[i]].id].x = 0, Res[p[L[i]].id].y = 1;
        }
        else {
            Res[p[L[i]].id].x /= g, Res[p[L[i]].id].y /= g;
        }
        for (int j = L[i] + 1; j <= R[i]; j++) {
            while (r < p[j].r) work(c[++r], 1);
            while (l < p[j].l) work(c[l++], -1);
            while (l > p[j].l) work(c[--l], 1);
            Res[p[j].id].x = res;
            Res[p[j].id].y = (ll)(r - l + 1) * (r - l);
            ll g = gcd(Res[p[j].id].x, Res[p[j].id].y);
            if (!g) Res[p[j].id].x = 0, Res[p[j].id].y = 1;
            else Res[p[j].id].x /= g, Res[p[j].id].y /= g; 
        }
    }
    for (int i = 1; i <= m; i++) cout << Res[i].x << "/" << Res[i].y << "\n";
    return 0;
}