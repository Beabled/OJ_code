#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 7;
ll n, a[N], tmp[N];
ll res;

void merge_sort(ll q[], int l, int r)
{
    if (l >= r) return ;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else res += mid - i + 1, tmp[k++] = q[j++];
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        res = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        merge_sort(a, 0, n - 1);
        cout << res << "\n";
    }
    return 0;
}