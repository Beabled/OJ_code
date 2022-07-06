#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7;
int n;
int q[N], idx, tmp[N];

ll merge_sort(int q[], int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else res += mid - i + 1, tmp[k++] = q[j++];
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        idx = 0;
        for (int i = 1; i <= n * n; i++)
        {
            int a;
            cin >> a;
            if (a) q[idx++] = a;
        }
        ll res1 = merge_sort(q, 0, n * n - 2);
        idx = 0;
        for (int i = 1; i <= n * n; i++)
        {
            int a;
            cin >> a;
            if (a) q[idx++] = a;
        }
        ll res2 = merge_sort(q, 0, n * n - 2);
        res1 %= 2, res2 %= 2;
        if (res1 == res2) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}