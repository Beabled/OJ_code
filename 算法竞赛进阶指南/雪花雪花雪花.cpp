#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int n, h[N], ne[N], snow[N][6], idx, p = 99991;

int H(int a[])
{
    ll sum = 0, mul = 1;
    for (int i = 0; i < 6; i++) {
        sum = (sum + a[i]) % p;
        mul = (mul * a[i]) % p;
    }
    return (sum + mul) % p;
}

bool equal(int a[], int b[])
{
    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < 6; j++) {
            bool eq = 1;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j + k) % 6]) eq = 0;
            if (eq) return 1;
            eq = 1;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j - k + 6) % 6]) eq = 0;
            if (eq) return 1;
        }
        return 0;
}

bool insert(int a[]) {
    int val = H(a);
    for (int i = h[val]; i; i = ne[i]) {
        if (equal(snow[i], a)) return 1;
    }

    ++idx;
    memcpy(snow[++idx], a, 6 * sizeof(int));
    ne[idx] = h[val];
    h[val] = idx;
    return 0;  
}

int main()
{

    ios::sync_with_stdio(false);
    cin >> n;
    int a[6];
    for (int i = 1; i <= n; i++) {
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        if (insert(a)) {
            cout << "Twin snowflakes found.\n";
            return 0;
        }
    }
    cout << "No two snowflakes are alike.\n";
    return 0;
}