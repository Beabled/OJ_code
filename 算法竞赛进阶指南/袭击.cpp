#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int t, n;
double eps = 1e-6, res, INF = 1e15;
struct node {
    double x, y;
    bool type;
    bool operator < (const node& t) const
    {
        return x < t.x;
    }
}point[N], tmp[N];


double get_dis(node x, node y)
{
    if (x.type == y.type) return res;
    return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

double dfs(int l, int r)
{
    if (l == r) return INF;
    int mid = l + r >> 1;
    double mind = point[mid].x;
    double ans = min(dfs(l, mid), dfs(mid + 1, r));

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (point[i].y < point[j].y) tmp[k++] = point[i++];
        else tmp[k++] = point[j++];
    while (i <= mid) tmp[k++] = point[i++];
    while (j <= r) tmp[k++] = point[j++];
    for (i = l, j = 0; i <= r; i++, j++) point[i] = tmp[j];

    k = 0;
    for (i = l; i <= r; i++)
        if (point[i].x >= mind - ans && point[i].x <= mind + ans) tmp[k++] = point[i];
    
    for (i = 0; i < k; i++)
        for (j = i - 1; j >= 0 && tmp[i].y - tmp[j].y + eps <= ans; j--)
            ans = min(ans, get_dis(point[i], point[j]));
    res = min(res, ans);
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lf%lf", &point[i].x, &point[i].y), point[i].type = true;
        for (int i = n; i < 2 * n; i++) scanf("%lf%lf", &point[i].x, &point[i].y), point[i].type = false;
        res = get_dis(point[0], point[(n << 1) - 1]);
        sort(point, point + 2 * n);
        printf("%.3lf\n", dfs(0, (n << 1) - 1));
    }
    return 0;
}