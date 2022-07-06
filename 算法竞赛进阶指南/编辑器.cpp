#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int q;
int s1[N], s2[N], t1, t2;
int f[N], sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> q;
    f[0] = -0x3f3f3f3f;
    while (q--)
    {
        string s;
        int y;
        cin >> s;
        if (s == "I") cin >> y, s1[++t1] = y, sum[t1] = y + sum[t1 - 1], f[t1] = max(f[t1 - 1], sum[t1]);
        else if (s == "D") 
            {if (t1 >= 1) t1--;}
        else if (s == "L")
            {if (t1 >= 1) s2[++t2] = s1[t1], t1--;}
        else if (s == "R")
            {if (t2 >= 1) s1[++t1] = s2[t2], sum[t1] = s2[t2] + sum[t1 - 1], f[t1] = max(f[t1 - 1], sum[t1]), t2--;}
        else if (s == "Q") cin >> y, cout << f[y] << "\n";
    }
    return 0;
}