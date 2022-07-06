#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
char s[N];
int n, ne[N];

int main()
{
    ios::sync_with_stdio(false);
    int t = 1;
    while (cin >> n, n)
    {
        cout << "Test case #" << t++ << "\n";
        cin >> s + 1;
        for (int i = 0; i <= n; i++) ne[i] = 0;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = 2; i <= n; i++) {
            if (i % (i - ne[i]) == 0 && i / (i - ne[i]) > 1) {
                cout << i << " " << i / (i - ne[i]) << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}