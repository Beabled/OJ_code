#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 5052;

int s[N][N], n, ma, r, res;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> r;
    
    while (n--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ma = max(ma, x + 1), ma = max(ma, y + 1);
        s[x + 1][y + 1] += w;
    }
    
    for (int i = 1; i <= ma; i++)
        for (int j = 1; j <= ma; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    for (int i = r; i <= ma; i++)
        for (int j = r; j <= ma; j++)
            res = max(res, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
    
    if (r < ma) cout << res << endl;
    else cout << s[ma][ma] << endl;
    
    return 0;
}