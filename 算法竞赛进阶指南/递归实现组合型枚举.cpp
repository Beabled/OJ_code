#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 25;

int a[N], n, m;
bool st[N];

void dfs(int index, int sum)
{
    if (n + 1 - index < m - sum) return;
    if (sum == m)
    {
        for (int i = 1; i <= sum; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    
    a[sum + 1] = index;
    dfs(index + 1, sum + 1);
    dfs(index + 1, sum);
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}